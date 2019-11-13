#include "TopCDTManager.h"

TopCDTManager::TopCDTManager( void ) : VMEController( e14::tcdt_slot,"tcdt"){

   Init();

}

TopCDTManager::~TopCDTManager(){
    ;
}

void TopCDTManager::Init( void ){

   SetTestMode();

   write_reg("reset",1);
   write_reg("reset",1);

   /// real fiber input ///
   write_reg("et_in_switch",0);
   write_reg("veto_in_switch",0);

   write_reg("live_mode",0);    // 0: from MACTRIS, 1: internal
   write_reg("ena_live_sim",0); 
   write_reg("force_live_on",0);

   write_reg("et_err_in_switch",0);

   write_reg("bypass_tlk_err",0);
   write_reg("bypass_dc_err",0);
   write_reg("bypass_lv2_full",0);
   write_reg("ena_olrx",0x7);

   write_reg("send_factory_trig",0);
   write_reg("ena_delta_factory",0);
   write_reg("factory_ntrig",0);
   write_reg("ena_fiber_sim",0);
   write_reg("ena_lvds_cnt_debug",0);
   write_reg("ext_trig_in_switch",0);
   write_reg("ena_delta_lv1",1);
   write_reg("ena_clock_trig",0);
   write_reg("nclus_in_switch",0);

   /// set default delay ///
   write_reg("delay_et_raw",e14::delay_raw);
   write_reg("delay_veto_raw",e14::delay_raw);
   write_reg("delay_lv1b_req",e14::delay_lv1b_req);
   write_reg("delay_lv1",e14::delay_lv1);
   write_reg("spill_off_time",e14::spill_off_time);
}

void TopCDTManager::SetTree( TTree* tr ){

   tr->Branch("Spill",&m_spill,"Spill/I");
   tr->Branch("isTLKErr",&m_isTLKErr,"isTLKErr/O");
   tr->Branch("isEtVetoDCErr",&m_isDCErr,"isEtVetoDCErr/O");
   tr->Branch("isTLKErr",&m_isTLKErr,"isTLKErr/O");
   tr->Branch("isTLKErr",&m_isTLKErr,"isTLKErr/O");
   tr->Branch("isLocalAlignErr",&m_isLocalAlignErr,"isLocalAlignErr/O");
   tr->Branch("isGlobalAlignErr",&m_isGlobalAlignErr,"isGlobalAlignErr/O");
   tr->Branch("isClusDeltaErr",&m_isClusDeltaErr,"isClusDeltaErr/O");
   tr->Branch("isClusIdErr",&m_isClusIdErr,"isClusIdErr/O");
   tr->Branch("isClusTimeErr",&m_isClusTimeErr,"isClusTimeErr/O");

   tr->Branch("EtAlignPtnTime",&m_EtAlignPtnTime,"EtAlignPtnTime/I");
   tr->Branch("VetoAlignPtnTime",&m_VetoAlignPtnTime,"VetoAlignPtnTime/I");
   tr->Branch("EtDeltaPtnTime",&m_EtDeltaPtnTime,"EtDeltaPtnTime/I");
   tr->Branch("VetoDeltaPtnTime",&m_VetoDeltaPtnTime,"VetoDeltaPtnTime/I");
   tr->Branch("DelayClusTime",&m_DelayClusTime,"DelayClusTime/I");
   tr->Branch("EarlyLv1Time",&m_EarlyLv1Time,"EarlyLv1Time/I");

   tr->Branch("EtDeltaPtn",&m_EtDeltaPtn,"EtDeltaPtn/I");
   tr->Branch("VetoDeltaPtn",&m_VetoDeltaPtn,"VetoDeltaPtn/I");
   tr->Branch("EtDeltaLv1aTime",&m_EtDeltaLv1aTime,"EtDeltaLv1aTime/I");
   tr->Branch("VetoDeltaLv1aTime",&m_VetoDeltaLv1aTime,"VetoDeltaLv1aTime/I");

   tr->Branch("nDelta",&m_ndelta,"nDelta/I");
   tr->Branch("Lv1aRawCnt",&m_lv1a_raw_cnt,"Lv1aRawCnt/I");
   tr->Branch("Lv1aCnt",&m_lv1a_cnt,"Lv1aCnt/I");
   tr->Branch("Lv1aRejCnt",&m_lv1a_rej_cnt,"Lv1aRejCnt/I");
   tr->Branch("Lv1Cnt",&m_lv1_cnt,"Lv1Cnt/I");
   tr->Branch("Lv1PSCnt",&m_lv1_ps_cnt,"Lv1PSCnt/I");
   tr->Branch("Lv2RejCnt",&m_lv2_rej_cnt,"Lv2RejCnt/I");
   tr->Branch("RawClusCnt",m_raw_clus_cnt,"RawClusCnt[10]/I");
   tr->Branch("L1AInternalClusCnt",m_scaled_clus_cnt,"L1AInternalClusCnt[10]/I");
   tr->Branch("TrigTypeLv1aRawCnt",m_type_lv1a_raw_cnt,"TrigTypeLv1aRawCnt[8]/I");
   tr->Branch("TrigTypeLv1aScaledCnt",m_type_lv1a_scaled_cnt,"TrigTypeLv1aScaledCnt[8]/I");
   tr->Branch("TrigTypeLv1bRawCnt",m_type_lv1b_raw_cnt,"TrigTypeLv1bRawCnt[8]/I");
   tr->Branch("TrigTypeLv1bScaledCnt",m_type_lv1b_scaled_cnt,"TrigTypeLv1bScaledCnt[8]/I");
   tr->Branch("VetoScalarCnt",m_veto_cnt,"VetoScalarCnt[8]/I");
   tr->Branch("ExtTrigCnt",m_ext_cnt,"ExtTrigCnt[2]/I");
   tr->Branch("AccData",m_ext_data,"AccData[2]/I");

}

void TopCDTManager::SetTestMode( void ){

   write_reg("test_mode",1);

}

void TopCDTManager::SetOperationMode( void ){

   write_reg("test_mode",0);

}

bool TopCDTManager::SetTrigType(char const* runtype, int trigno){

   char fname[100];
   sprintf( fname, "%s/TrigType/%s/TrigType%d.txt", e14::setdir.c_str(), runtype, trigno);
   std::ifstream ifile( fname );

   if( ifile.fail() ){
      std::cout<<" [Error] Fail to read trigger type setting, unknown runtype : " 
               << runtype << std::endl;
      return false; 
   }

   char rname[32], reg_name[32]; 
   int rval = 0;
   while( ifile >> rname >> std::hex >> rval ){
      sprintf( reg_name, "type%d_%s", trigno, rname );
      write_reg( reg_name , rval );         

//      if( strcmp(rname,"ps")==0 )
//      {
//         sprintf( reg_name, "new_type%d_%s", trigno, rname );
//         write_reg( reg_name , rval );
//      }
   }

   return true;
}

bool TopCDTManager::SetExtTrigType(char const* runtype, int trigno){

   char fname[100];
   sprintf( fname, "%s/TrigType/%s/Ext%d.txt", e14::setdir.c_str(), runtype, trigno);
   std::ifstream ifile( fname );

   if( ifile.fail() ){ 
      std::cout<<" [Error] Fail to read external trigger type setting, unknown runtype: " 
               << runtype << std::endl;
      return false;
   }

   char rname[32], reg_name[32];
   int rval = 0;
   while( ifile >> rname >> std::hex >> rval ){
      sprintf( reg_name, "ext%d_%s", trigno, rname );
      write_reg( reg_name , rval );
   }

   return true;

}

void TopCDTManager::UpdateErr( int spill ){

   m_spill = spill;
   m_isTLKErr = read_reg("tlk_err");
   m_isDCErr = read_reg("dc_err");
   m_isLocalAlignErr = read_reg("local_align_err");
   m_isGlobalAlignErr = read_reg("global_align_err");
   m_isClusDeltaErr = read_reg("clus_delta_err");
   m_isClusIdErr = read_reg("clus_id_err");
   m_isClusTimeErr = read_reg("clus_id_err");

   m_EtAlignPtnTime = read_reg("delay_et_align_ptn");
   m_VetoAlignPtnTime = read_reg("delay_veto_align_ptn");
   m_EtDeltaPtnTime = read_reg("delay_et_delta_ptn");
   m_VetoDeltaPtnTime = read_reg("delay_veto_delta_ptn");
   m_DelayClusTime = read_reg("delay_clus_result");
   m_EarlyLv1Time = read_reg("lv1_delay");

   m_EtDeltaPtn = read_reg("delta_et_raw");
   m_VetoDeltaPtn = read_reg("delta_veto_raw");
   m_EtDeltaLv1aTime = read_reg("et_delta_lv1a_t");
   m_VetoDeltaLv1aTime = read_reg("veto_delta_lv1a_t");

}




void TopCDTManager::UpdateCounters( int spill ){

   m_spill = spill;
   m_ndelta = read_reg("ndelta");
   m_lv1a_raw_cnt = read_reg("lv1a_raw_cnt");
   m_lv1a_cnt = read_reg("lv1a_cnt");
   m_lv1a_rej_cnt = read_reg("lv1a_rej_cnt");
   m_lv1_cnt = read_reg("lv1_cnt");
   m_lv1_ps_cnt = read_reg("lv1_ps_cnt");
   m_lv2_rej_cnt = read_reg("lv2_rej_cnt");

   char reg_name[32];

   for( int i=0; i<10; i++ ){
      if( i < 9 ){
         sprintf(reg_name,"raw_clus%d_cnt",i);
         m_raw_clus_cnt[i] = read_reg(reg_name);
      }else{
         m_raw_clus_cnt[i] = read_reg("raw_clusN_cnt");
      }
   }

   for( int i=0; i<10; i++ ){
      if( i < 9 ){
         sprintf(reg_name,"scaled_clus%d_cnt",i);
         m_scaled_clus_cnt[i] = read_reg(reg_name);
      }else{
         m_scaled_clus_cnt[i] = read_reg("scaled_clusN_cnt");
      }
   }  

   for( int i=0; i<8; i++ ){
      sprintf(reg_name,"type%d_lv1a_raw_cnt",i);
      m_type_lv1a_raw_cnt[i] = read_reg(reg_name);
   }

   for( int i=0; i<8; i++ ){
      sprintf(reg_name,"type%d_lv1a_scaled_cnt",i);
      m_type_lv1a_scaled_cnt[i] = read_reg(reg_name);
   }

   for( int i=0; i<8; i++ ){
      sprintf(reg_name,"type%d_lv1b_raw_cnt",i);
      m_type_lv1b_raw_cnt[i] = read_reg(reg_name);
   }

   for( int i=0; i<8; i++ ){
      sprintf(reg_name,"type%d_lv1b_scaled_cnt",i);
      m_type_lv1b_scaled_cnt[i] = read_reg(reg_name);
   }

   for( int i=0; i<8; i++ ){
      sprintf(reg_name,"type%d_lv1a_raw_cnt",i);
      m_type_lv1a_raw_cnt[i] = read_reg(reg_name);
   }

   for( int i=0; i<16; i++ ){
      sprintf(reg_name,"veto%d_cnt",i);
      m_veto_cnt[i] = read_reg(reg_name);
   }

   for( int i=0; i<2; i++ ){
      sprintf(reg_name,"ext%d_cnt",i);
      m_ext_cnt[i] = read_reg(reg_name);
   }

   for( int i=0; i<2; i++ ){
      sprintf(reg_name,"exdata%d",i);
      m_ext_data[i] = read_reg(reg_name);
   }

   m_csi_cnt = read_reg("et_cnt");

}

void TopCDTManager::PrintErr( void ){

       std::cout<<" Error monitoring... " << std::endl;
       std::cout<<" [0] TLK error               : \t" << m_isTLKErr << std::endl;
       std::cout<<" [1] DC / veto error         : \t" << m_isDCErr << std::endl;
       std::cout<<" [2] Local align err         : \t" << m_isLocalAlignErr << std::endl;
       std::cout<<" [3] Global align err        : \t" << m_isGlobalAlignErr << std::endl;
       std::cout<<" [4] Cluster delta trig err  : \t" << m_isClusDeltaErr << std::endl;
       std::cout<<" [5] Cluster ID err          : \t" << m_isClusIdErr  << std::endl;
       std::cout<<" [6] Cluster timing err      : \t" << m_isClusTimeErr << std::endl;

       std::cout<< std::dec << std::endl;
       std::cout<<" Timing test result: " << std::endl;
       std::cout<<" [0] ET align pattern time   : \t" << m_EtAlignPtnTime << std::endl;
       std::cout<<" [1] Veto align time         : \t" << m_VetoAlignPtnTime << std::endl;
       std::cout<<" [2] ET delta pattern time   : \t" << m_EtDeltaPtnTime << std::endl;
       std::cout<<" [3] Veto delta pattern time : \t" << m_VetoDeltaPtnTime << std::endl;
       std::cout<<" [4] T to get clus from plv1 : \t" << m_DelayClusTime << std::endl;
       std::cout<<" [5] Early lv1 decision time : \t" << m_EarlyLv1Time << std::endl;

       std::cout<< std::hex << std::endl;
       std::cout<<" Delta pattern monitoring: " << std::endl;
       std::cout<<" [0] Delta ET raw (in hex)   : \t" << m_EtDeltaPtn << std::endl;
       std::cout<<" [1] Delta veto raw (in hex) : \t" << m_VetoDeltaPtn << std::endl;
       std::cout<< std::dec;
       std::cout<<" [2] Delta ET time (lv1a)    : \t" << m_EtDeltaLv1aTime << std::endl;
       std::cout<<" [3] Delta veto time (lv1a)  : \t" << m_VetoDeltaLv1aTime << std::endl;

}

void TopCDTManager::PrintCounter( void ){

        std::cout<< std::dec << std::endl;
        std::cout<<" N delta ptn       : \t" << m_ndelta << std::endl;
        std::cout<<" Lv1a raw cnt      : \t" << m_lv1a_raw_cnt << std::endl;
        std::cout<<" Lv1a accepted cnt : \t" << m_lv1a_cnt << std::endl;
        std::cout<<" Lv1a rejected cnt : \t" << m_lv1a_rej_cnt << std::endl;
        std::cout<<" Lv1 cnt           : \t" << m_lv1_cnt << std::endl;
        std::cout<<" Lv1 w/ ps         : \t" << m_lv1_ps_cnt << std::endl;
        std::cout<<" Lv2 full rej cnt  : \t" << m_lv2_rej_cnt << std::endl;
        std::cout<< std::endl;

        std::cout<<" Cluster counter (raw) " << std::endl;
        for( int i=0; i<10; i=i+2 ){
           std::cout<<"  - " << i   <<" cluster      : \t" << m_raw_clus_cnt[i]  << "\t\t "
                    <<"  - " << i+1 <<" cluster      : \t" << m_raw_clus_cnt[i+1]  << std::endl;
        }
        std::cout<<std::endl;

        std::cout<<" Cluster counter (internal, lv1 accepted) " << std::endl;
        for( int i=0; i<10; i=i+2 ){
           std::cout<<"  - " << i   <<" cluster      : \t" << m_scaled_clus_cnt[i]  << "\t\t "
                    <<"  - " << i+1 <<" cluster      : \t" << m_scaled_clus_cnt[i+1]  << std::endl;
        }
        std::cout<<std::endl;

        std::cout<<" Lv1a Trigger type counter" << std::endl;
        for( int i=0; i<8; i++ ){
           std::cout<<"  - type " << i <<" raw     : \t" << m_type_lv1a_raw_cnt[i]  << "\t\t "
                    <<"  - type " << i <<" scaled  : \t" << m_type_lv1a_scaled_cnt[i]  << std::endl;
        }
        std::cout<< std::endl;

        std::cout<<" Lv1b Trigger type counter" << std::endl;
        for( int i=0; i<8; i++ ){
           std::cout<<"  - type " << i <<" raw     : \t" << m_type_lv1b_raw_cnt[i]  << "\t\t "
                    <<"  - type " << i <<" scaled  : \t" << m_type_lv1b_scaled_cnt[i]  << std::endl;
        }
        std::cout<< std::endl;

        std::cout<<" Veto counter (rising edge, independent of trigger decision) " << std::endl;
        for( int i=0; i<16; i =i+2 ){
           std::cout<<"  - veto " << i   <<"         : \t" << m_veto_cnt[i]  << "\t\t "
                    <<"  - veto " << i+1 <<"         : \t" << m_veto_cnt[i+1]  << std::endl;
        }
        std::cout<< std::endl;

        std::cout<<" External trigger counter " << std::endl;
        std::cout<<"  - ext 0          : \t" << m_ext_cnt[0]  << "\t\t "
                 <<"  - ext 1          : \t" << m_ext_cnt[1]  << std::endl;
        std::cout<< std::endl;

        std::cout<<" External data (SEC,TMON) " << std::endl;
        std::cout<<"  - ext 0          : \t" << m_ext_data[0]  << "\t\t "
                 <<"  - ext 1          : \t" << m_ext_data[1]  << std::endl;
        std::cout<<std::endl;

        std::cout<<" CSI Et counter : " << m_csi_cnt;

}

void TopCDTManager::SaveErr( int runID, int spill ){

   std::string ofname = e14::mon_dir + Form("/err_log/run%d/run%d_spill%d.txt"
                                            ,runID,runID,spill);
   std::ofstream ofile( ofname.c_str() );

   ofile <<"tlk_err\t" << m_isTLKErr << std::endl;
   ofile <<"dc_err\t" << m_isDCErr << std::endl;
   ofile <<"local_align_err\t" << m_isLocalAlignErr << std::endl;
   ofile <<"global_align_err\t" << m_isGlobalAlignErr << std::endl;
   ofile <<"clus_delta_err\t" << m_isClusDeltaErr << std::endl;
   ofile <<"clus_id_err\t" << m_isClusIdErr  << std::endl;
   ofile <<"clus_time_err\t" << m_isClusTimeErr << std::endl;
   ofile.close();

}

void TopCDTManager::SaveCounters( int runID, int spill ){

   std::string ofname = e14::mon_dir + Form("/cnt_log/run%d/run%d_spill%d.txt"
                                            ,runID,runID,spill);
   std::ofstream ofile( ofname.c_str() );

   ofile <<"ndelta\t" << m_ndelta << std::endl;
   ofile <<"lv1a_raw_cnt\t"<< m_lv1a_raw_cnt << std::endl;
   ofile <<"lv1a_cnt\t" << m_lv1a_cnt << std::endl;
   ofile <<"lv1a_rej_cnt\t" << m_lv1a_rej_cnt << std::endl;
   ofile <<"lv1_cnt\t" << m_lv1_cnt << std::endl;
   ofile <<"lv1_ps_cnt\t"<< m_lv1_ps_cnt << std::endl;
   ofile <<"lv2_rej_cnt\t"<< m_lv2_rej_cnt << std::endl;

   for( int i=0; i<10; i++ ){
      ofile << "raw_cluster" << i << "\t" << m_raw_clus_cnt[i] << std::endl;
   }

   for( int i=0; i<10; i++ ){
      ofile << "scaled_cluster" << i << "\t" << m_scaled_clus_cnt[i] << std::endl;
   }

   for( int i=0; i<8; i++ ){
      ofile << "type_lv1a_raw" << i <<"\t" << m_type_lv1a_raw_cnt[i] << std::endl;
      ofile << "type_lv1a_scaled" << i <<"\t" << m_type_lv1a_scaled_cnt[i] << std::endl;
      ofile << "type_lv1b_raw" << i <<"\t" << m_type_lv1b_raw_cnt[i]  << std::endl;
      ofile << "type_lv1b_scaled" << i <<"\t" << m_type_lv1b_scaled_cnt[i]  << std::endl;

   }

   for( int i=0; i<16; i++ ){
      ofile << "veto" << i   <<"\t" << m_veto_cnt[i]  << std::endl;
   }

   ofile << "csi\t" << m_csi_cnt << std::endl;
   ofile << "ext0\t"<< m_ext_cnt[0]  << std::endl;
   ofile << "ext1\t"<< m_ext_cnt[1]  << std::endl;
   ofile << "SEC\t" << m_ext_data[0]  << std::endl;
   ofile << "TMON\t" << m_ext_data[1]  << std::endl;
   
}


/*

*/

/*
bool TopCDTManager::SystMonitor( int nspill ){

   bool live = read_reg("live");
   bool plive = 0;
   
   int  spill = read_reg("spill_count");
   if( spill > 1 ){
      std::cout<<" [Warning] Spill counter did not start from 1. " << std::endl;
   }

   bool isLastSpillEnd = false;
   int  on_timer = 0;
   int  off_timer = 0;

   while( !isLastSpillEnd ){
   
     live = read_reg("live");

     /// live rising edge 
     if( plive == 0 && live == 1 ){
        on_timer = 0;
        spill = read_reg("spill_count");
     }

     if( plive == 1 && live == 0 )
        off_timer = 0;

     if( on_timer == 4 )
        ReadErr();

     if( off_timer == 0 )
        ReadTrigCnt();

     // clock, cycling for each 0.4 sec
      usleep(400* 1000);
      plive = live;

      if( live ) on_timer++;
      else       off_timer++;  


      if( spill == nspill && off_timer == 1 )
         isLastSpillEnd = true;

   }

}



bool SaveErrLog( int spillno ){




}
   
bool SaveTrigCnt( int spillno );
*/
