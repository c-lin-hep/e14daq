#include "FADCManager.h"

FADCManager::FADCManager( int crateID , int slot , int runID ) : VMEController(slot,"adc"){

   m_crateID = crateID;
   m_slotID = slot;
   m_runID = runID;
   SetBoardType();
  
}

FADCManager::~FADCManager(){
   ;
}

void FADCManager::SetBoardType( void ){

   if( version() >= 2200 && version() < 5000 ){
      m_boardtype = 1; // 125 mhz
   }else if( version() >= 5000 ){
      m_boardtype = 2; // 500 mhz
   }else if( version() < 2200 && version() >= 2000 ){
      m_boardtype = 3;
   }else{
      m_boardtype = 0;
   }

}

void FADCManager::Init( void ){

   write_reg("use_zero",0);
   write_reg("ena_daq_mode",1);
   write_reg("LVDS_tx_sel",0);
   write_reg("plv1_scan_en",0);
 
   write_reg("live_bypass",0);
   write_reg("l1a_bypass",0);
   write_reg("N_width",0x08);
   write_reg("live_bypass_mode",0);

   write_reg("pulse_mode2",0);

   bool en_ped_rec = ( m_boardtype == 3 ) ? false : true;
   write_reg("ena_pedrecord",en_ped_rec);

   write_reg("DS_mode_control",0x0);
   write_reg("DS_mode_control",0x7);


   ResetSpill();

}

void FADCManager::ResetSpill( void ){
   write_reg("spill_count_clear",1);
   write_reg("spill_count_clear",0);

   write_reg("trig_count_rst",1);
   write_reg("trig_count_rst",0);
}

void FADCManager::SetDaisyChain( int ifadc ){

     write_reg("veto_crate",0);
    
     int dc_rank = e14::nDaisyChainMembers - ( ifadc / e14::nDaisyChains ) - 1;

     switch( dc_rank ){
        case 0:
           write_reg("first_adc",1);
           write_reg("lckrefn_l1",0);
           write_reg("maxt",e14::et_dc_maxt);
           write_reg("pattern_tx",0xf000);
           break;
        case 1:
           write_reg("first_adc",0);
           write_reg("lckrefn_l1",1);
           write_reg("maxt",2*e14::et_dc_maxt);
           write_reg("pattern_tx",0x0f00);
           write_reg("pattern_rx",0xf000);
           break;
        case 2:
           write_reg("first_adc",0);
           write_reg("lckrefn_l1",1);
           write_reg("maxt",3*e14::et_dc_maxt);
           write_reg("pattern_tx",0x00f0);
           write_reg("pattern_rx",0xff00);
           break;
        case 3:
           write_reg("first_adc",0);
           write_reg("lckrefn_l1",1);
           write_reg("maxt",4*e14::et_dc_maxt);
           write_reg("pattern_tx",0x000f);
           write_reg("pattern_rx",0xfff0);
           break;
        default:
           std::cout<<" [Error] Unexpected Daisy-Chain ranking. " << std::endl;
     }
  
}

void FADCManager::SetVeto( void ){

   write_reg("lckrefn_l1",0x0);
   write_reg("veto_crate",1);
   
}

void FADCManager::SetPeakWindow( void ){

   write_reg("CB_tmin",0x2);
   write_reg("CB_tmax",0x2);

}

void FADCManager::SetPeakWindow( int tleft, int tright ){

   const int tcenter = 2;
   
   write_reg("CB_tmin",tcenter - tleft);
   write_reg("CB_tmax",tcenter + tright);

}

void FADCManager::SetPeakThreshold( int* thr ){

   if( m_boardtype!=1 &&  m_boardtype!=2 ) return;

   int nchs = ( m_boardtype==2 ) ? e14::n500mhzChannels : e14::nChannels; 

   for( int ich=0; ich<nchs; ++ich ){
      char reg_name[32];
      sprintf( reg_name , "cls_thr_%d" , ich );
      write_reg(reg_name,thr[ich] );
   }

}

void FADCManager::SetPeakWindowDelay( int delay ){

   if(e14::isVetoCrate[m_crateID] ){
      if( m_boardtype == 1 ){
         write_reg("CB_delay", delay + e14::delay_offset_125mhz );
      }else if( m_boardtype == 2 ){
         write_reg("CB_delay", delay );
      }
   }
   else{
      write_reg("CB_delay", delay );
   }

}

void FADCManager::SetBitMapDelay( int delay ){

   write_reg("delay_cb_readout",delay);

}

void FADCManager::SetPeakScan( int init_delay ){

   SetPeakWindowDelay( init_delay );
   SetPeakWindow();

   write_reg("plv1_scan_en",0);
   usleep(1000);
   write_reg("plv1_scan_en",1); 

}

void FADCManager::SetMasking( bool* mask ){

   if(  m_boardtype!=1 && m_boardtype!=2 ) return; 
   int nchs = ( m_boardtype==2 ) ? e14::n500mhzChannels : e14::nChannels;

   for( int ich=0; ich<nchs; ++ich ){
      char reg_name[32];
      sprintf( reg_name , "cls_mask_%d" , ich );
      write_reg(reg_name, mask[ich] );
   }

}

void FADCManager::SetLinearFunc( int* p0, int* p1 ){

   /// register variable
   unsigned long p0_reg_val;
   unsigned long p1_reg_val;

   /// p0, p1 register addresss offset
   const int p0_addr_offset = 17;
   const int p1_addr_offset = 1;
 
   for( int ich=0; ich<e14::nChannels; ++ich ){

      /// p0 setting ///
      p0_reg_val =  ( p0[ich] < 0 ) ? ( 1 << 31 ) : 0; 
      p0_reg_val += abs(p0[ich]);
  
      write_reg("rb_addr", ich + p0_addr_offset);
      write_reg("rb_value",p0_reg_val);
      
      /// p1 setting ///
      /// p1 = 0 stands for masking in ET sum

      int et_thr = 0;

      if( p1[ich] > 0 ){
         et_thr = ( e14::local_et_thr - p0[ich]) / p1[ich];
         et_thr = ( et_thr < 0 ) ? 0 : et_thr;
      }else{
         et_thr = 0xffff;
      }

      p1_reg_val = ( et_thr << 16 ) + p1[ich];

      write_reg("rb_addr", ich + p1_addr_offset );
      write_reg("rb_value", p1_reg_val );

   }

}

void FADCManager::SetChannelDelay( int* delay ){

   if(  m_boardtype==1 ){
      int nchs = e14::nChannels;
      int reg_val = 0;
      char reg_name[32];

      for( int ich=0; ich<nchs; ++ich ){
         int init_bit = (ich/4)*16;
         switch( (ich % 4 ) ){
            case 0: 
               reg_val = delay[ich];
               break;
            case 1:
               reg_val += ( delay[ich] << 4 );
               break;
            case 2:
               reg_val += ( delay[ich] << 8 );
               break;
            case 3:
               reg_val += ( delay[ich] << 12 );
               sprintf(reg_name,"delay[%d:%d]",init_bit+15,init_bit);
               write_reg(reg_name, reg_val);
               break;
            default: ;
         }  
      }
   }
   /// 500 mhz 
   else if ( m_boardtype==2 ){
      unsigned long val = 0;
      int nchs = e14::n500mhzChannels;
      for( int ich=0; ich<nchs; ++ich ){
         val += ( delay[ich] ) << ( ich * 5 );
      }

      write_reg("delay[15:0]", (val & 0xffff) );
      write_reg("delay[31:16]", ( (val & 0x1f0000) >> 16) );


   }

}


void FADCManager::SetDBMode( void ){

   write_reg("spill_count_clear",0x01);
   write_reg("spill_count_clear",0x00);

   write_reg("trig_count_rst",0x01);
   write_reg("trig_count_rst",0x00);
   
   // DS_mode: 
   // - bit 0: FIFO writing enable, 
   // - bit 1: FIFO reading request,
   // - bit 2: FIFO NOT clear 

   // Nsamples = val x 8
   write_reg("N_width",0x08);
    
   write_reg("DS_mode_control",0x00);
   usleep(1000);
   write_reg("DS_mode_control",0x04);
   write_reg("DS_mode_control",0x05);

}

void FADCManager::RunDBCaptureForPed( void ){

  write_reg("use_zero",0);
  write_reg("use_lossless",0);

  write_reg("N_width",0x06);
  write_reg("clk_select_mode",0);
  write_reg("live_bypass",0);
  write_reg("l1a_bypass",0);
  write_reg("live_bypass_mode",0x01);
  write_reg("l1a_bypass_mode",0x01);
  write_reg("live_bypass",0x01);
  write_reg("ena_daq_mode",0);

  write_reg("l1a_bypass_mode",0);
  for(int i=0; i<50; i++){
	write_reg("pulse_mode2",1);
	write_reg("ena_selftrig",1);
	write_reg("ena_selftrig",0);
	usleep(1000);
  }

  RunDBCaptureSpillBase(-1,-1);

}

void FADCManager::RunDBCapture( int runID ){

   RunDBCaptureSpillBase(runID,-1);

}

void FADCManager::RunDBCaptureSpillBase(int runID, int SpillNo){

   bool isAlmostFull = false;
   const int MAX_TIMER = 60000000;

   bool isTimeOut = false;

   int timer = 0;

   while( !isAlmostFull ){
      usleep(1000);
      isAlmostFull = read_reg("almost_full");
      timer++;
      if( timer > MAX_TIMER ){
         isTimeOut = true;
         break;
      }
   }

   write_reg("DS_mode_control",0x04);
   write_reg("DS_mode_control",0x04);
   usleep(1000);
   write_reg("DS_mode_control",0x06);
   write_reg("DS_mode_control",0x06);
  
   char ofname[100];
   if( SpillNo<0 ){
      if(runID>0 ){
         sprintf( ofname,"/raw_data/raw_data/crate%d/run%d/run%d_fadc%d.txt" 
                        , m_crateID, runID, runID ,m_slotID-3 );
      }
      else{
         sprintf( ofname , "/DAQcodes/e14daq/current/database/ped_data/crate%d/fadc%d.txt"
                         , m_crateID , m_slotID-3 );
      }
   }
   else
      sprintf( ofname,"/raw_data/raw_data/crate%d/run%d/run%d_fadc%d_spill%d.txt"
                        , m_crateID, runID, runID ,m_slotID-3, SpillNo );


   std::ofstream ofile( ofname );
   unsigned long data_buffer[16400];
   int nwords = 15480;
   read_blt(0,data_buffer,nwords);

   ofile << std::hex;
   for( int i=0; i<nwords; i++ ){
      ofile << (data_buffer[i]&0x0000ffff) << "\t" << ((data_buffer[i]&0xffff0000)>>16) << "\t";
      if( (i-5) % 8 == 0 ) ofile << std::endl;
   }
  
  ofile << std::endl;
  ofile << "ef";

  if( isTimeOut )
     ofile << "time out flag is on! " << std::endl;

  write_reg("DS_mode_control",0x04);
  write_reg("DS_mode_control",0x00);
  write_reg("live_bypass",0x00);
  write_reg("N_width",0x08);
  write_reg("ena_daq_mode",1);

}


void FADCManager::SetPedMeanSigma( double* mean, double* sigma, double* eta, int* ch_det, DetParContainer* DPC ){

  int NCH = 0;
  double SigmaThr, EtaThr;
  if( m_boardtype == 1 ){  /// 125MHz ADC
    NCH = e14::nChannels; //// 16
  }
  else if( m_boardtype == 2 ){  /// 500MHz ADC
    NCH = e14::n500mhzChannels; //// 4
  }
  else return;

  std::ofstream noisyfile;
  noisyfile.open( Form("/raw_data/ped_record/noisy_channel_list/noisych_run%d_crate%d.txt",m_runID,m_crateID) , std::ios::app );

  std::ofstream settingrecord;
  if( settingrecord.is_open() ) {std::cout<<"Setting record file wrongly opened for crate "<<m_crateID<<"\n";}
  settingrecord.open( Form("/raw_data/ped_record/setting_record/crate%d/pedsetting_run%d_crate%d.txt",m_crateID,m_runID,m_crateID) , std::ios::app );
  if( !(settingrecord.is_open()) ) {std::cout<<"Setting record file not opened for crate "<<m_crateID<<"\n";}

  int adc_useps = 0;
  int reg_useps[16], reg_m[16], reg_s[16] = {0};
  int ChannelDetID;
  for( int ich=0; ich<NCH; ich++ ){
    if(ich>=16) break;
    reg_m[ich] = TMath::Nint(mean[ich]);
    reg_s[ich] = (int)(3*sigma[ich]);
    ChannelDetID = ch_det[ich]-1;

    //// for different detectors, different suppresion thresholds and noisy-channel criteira are set
    //// suppression thresholds default is 3*sigma
    //// noisy-channel criteria default is Sigma>4.0 Eta<0.75 for 125MHz, and Sigma>2.0 Eta<0.80 for 500MHz
    //// if cannot find corresponding detector, then set this channel as default
    if( ChannelDetID<0 ) { reg_s[ich] = 99; reg_useps[ich] = 1; SigmaThr = (m_boardtype==1) ? 4.0 : 2.0; EtaThr = (m_boardtype==1) ? 0.75 : 0.80; }
    else {
      reg_useps[ich] = DPC->GetUsePS( ChannelDetID );
      SigmaThr = DPC->GetSigThr( ChannelDetID );
      EtaThr = DPC->GetEtaThr( ChannelDetID );
      reg_s[ich] = DPC->GetPSThr( ChannelDetID, sigma[ich] );
    }

    //// Judge if this is a noisy channel or a low gain channel, if yes, set this channel's suppresion threshold at 0
    if( sigma[ich]>SigmaThr || eta[ich]<EtaThr ) { reg_s[ich] = 0; noisyfile<<m_crateID<<"\t"<<(m_slotID-3)<<"\t"<<ich<<"\n"; }
  }


  //// Search for any detector in this ADC requires ps
  //// If yes, then turn on ps for this ADC, and if other channel on the same ADC not require ps, set the threshold to 0, to avoid suppression
  for( int ich=0; ich<NCH; ich++ ){
    if(ich>=16) break;
    switch(adc_useps){
      case 0: {
	if( reg_useps[ich]==1 && ch_det[ich]>0 ){
	  adc_useps = 1;
	  ich = -1;
	}
	break;
      }
      case 1: {
	if( reg_useps[ich]==0 && ch_det[ich]>0 ){
	  reg_s[ich] = 0;
	}
	break;
      }
      default: break;
    }
  }


  //// output parameters to file & registers to ADC
  for( int ich=0; ich<NCH; ich++ ){
    if(ich>=16) break;
    if(reg_s[ich]>reg_m[ich]) {reg_s[ich] = reg_m[ich];}
    //// Write suppression parameters to ADC
    write_reg(Form("pedestal_%d",ich), reg_m[ich]);
    write_reg(Form("ps_thr_%d",ich), reg_s[ich]);
    //// Output setting parameters to file
    settingrecord<<(m_slotID-3)<<"\t"<<ich<<"\t"<<(ch_det[ich]-1)<<"\t"<<reg_m[ich]<<"\t"<<mean[ich]<<"   \t"<<reg_s[ich]<<"\t"<<sigma[ich]<<"\n";
  }
  write_reg("use_zero", adc_useps);
  settingrecord<<(m_slotID-3)<<"\t"<<adc_useps<<"\n";

  noisyfile.close();
  settingrecord.close();

}

