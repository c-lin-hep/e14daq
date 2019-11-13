#include "E14DAQParContainer.h"

E14DAQParContainer::E14DAQParContainer( int crateID , int runID ){

   m_crateID = crateID;
   m_runID = runID;

   Init();

}

E14DAQParContainer::~E14DAQParContainer( void ){
   ;
}

void E14DAQParContainer::Init( void ){

   for( int ifadc=0; ifadc<s_nfadc; ++ifadc ){

      adctype[ifadc] = -1;
      slot[ifadc] = -1;
      tleft[ifadc] = -1;
      tright[ifadc] = -1;
      detbit[ifadc] = 15;   

      for( int ich=0; ich<s_nfadc; ++ich ){
         thr[ifadc][ich] = 0x3fff;
         mask[ifadc][ich] = 1;
         p0[ifadc][ich] = 0;
         p1[ifadc][ich] = 0;
         ch_delay[ifadc][ich] = 8;
	 ped_mean[ifadc][ich] = 8;
	 ped_sigma[ifadc][ich] = 8;
	 ped_eta[ifadc][ich] = 8;
         ch_detid[ifadc][ich] = 0;
      }
   
   }

}

void E14DAQParContainer::SetADCType( int slot, int type ){
  adctype[slot] = type;
}

bool E14DAQParContainer::SetADCSlot( void ){

   std::string ifname_sn = Form("Crate%d_Boards.txt",m_crateID);
   ifname_sn = e14::setdir + "/ADCSlot/" + ifname_sn;
   std::ifstream ifile_sn( ifname_sn.c_str() );

   if( ifile_sn.fail() ){
      std::cout << " [Error] E14DAQParContainer, crate "<< m_crateID
                << " Slot setting fails! " << std::endl;
      return false;
   }

   int rfadc, rslot;
   while( ifile_sn >> rfadc >> rslot ){
      slot[rfadc] = rslot;
   }

   ifile_sn.close();

   return true;

}

bool E14DAQParContainer::SetPeakThreshold( std::string runtype ){

   std::string ifname_thr = Form("Crate%d_PeakThreshold.txt",m_crateID);
   ifname_thr = e14::setdir + "/PeakThreshold/" + runtype + "/" + ifname_thr;
   std::ifstream ifile_thr( ifname_thr.c_str() );

   if( ifile_thr.fail() ){
      std::cout << " [Error] E14DAQParContainer, crate "<< m_crateID
                << " Peak threshold setting fails! " << std::endl;
      return false;
   }

   int rfadc, rch, rthr;
   while( ifile_thr >> rfadc >> rch >> rthr ){
      thr[rfadc][rch] = rthr;
   }

  ifile_thr.close();

  return true;

}

bool E14DAQParContainer::SetTimingWindow( std::string runtype ){

   std::string ifname_tw = Form("Crate%d_TimingWindow.txt",m_crateID);
   ifname_tw = e14::setdir + "/TimingWindow/" + runtype + "/" + ifname_tw;
   std::ifstream ifile_tw( ifname_tw.c_str() );

   if( ifile_tw.fail() ){
      std::cout<<" [Error] E14DAQParContainer, crate " << m_crateID
               <<" Timing window setting fails! " << std::endl;
      return false;
   }

   int rfadc, rtleft, rtright;
   while( ifile_tw >> rfadc >> rtleft >> rtright ){
      tleft[rfadc] = rtleft;
      tright[rfadc] = rtright;
   }

   ifile_tw.close();

   return true;

}

bool E14DAQParContainer::SetMasking( std::string runtype ){

   std::string ifname_msk = Form("Crate%d_MaskingList.txt",m_crateID);
   ifname_msk = e14::setdir + "/MaskingList/" + runtype + "/" + ifname_msk;
   std::ifstream ifile_msk( ifname_msk.c_str() );

   if( ifile_msk.fail() ){
      std::cout<<" [Error] E14DAQParContainer, crate " << m_crateID
               <<" Masking setting fails! " << std::endl;
      return false;
   }

   int rfadc, rch;
   bool rmask;
   while( ifile_msk >> rfadc >> rch >> rmask ){
      mask[rfadc][rch] = rmask;
   }

   ifile_msk.close();

   return true;

}

bool E14DAQParContainer::SetDetectorBit( void ){

   std::string ifname_db = Form("Crate%d_DetectorBit.txt",m_crateID);
   ifname_db = e14::setdir + "/DetectorBit/" + ifname_db;
   std::ifstream ifile_db( ifname_db.c_str() );

   if( ifile_db.fail() ){
      std::cout<<" [Error] E14DAQParContainer, crate " << m_crateID 
               <<" Detector bit setting fails! " << std::endl;
      return false;
   }

   int rfadc, rdb;
   while( ifile_db >> rfadc >> rdb ){
      detbit[rfadc] = rdb;
   }

   ifile_db.close();

   return true;

}

bool E14DAQParContainer::SetETLinearFunc( void ){

   std::string ifname_lf = Form("Crate%d_ETLinearFunc.txt",m_crateID);
   ifname_lf = e14::setdir + "/ETLinearFunc/" + ifname_lf;
   std::ifstream ifile_lf( ifname_lf.c_str() );

   if( ifile_lf.fail() ){
      std::cout<<" [Error] E14DAQParContainer, crate " << m_crateID 
               <<" ET linear function setting fails! " << std::endl;
      return false;
   }

   int rcrate, rfadc, rch, rp0, rp1;
   while( ifile_lf >> rcrate >> rfadc >> rch >> rp0 >> rp1 ){
      p0[rfadc][rch] = rp0;
      p1[rfadc][rch] = rp1;
   }

   ifile_lf.close();

   return true;

}

bool E14DAQParContainer::SetChannelDelay( void ){

   std::string ifname_cd = Form("Crate%d_ChannelDelay.txt",m_crateID);
   ifname_cd = e14::setdir + "/ChannelDelay/" + ifname_cd;
   std::ifstream ifile_cd( ifname_cd.c_str() );

   if( ifile_cd.fail() ){
      std::cout<<" [Error] E14DAQParContainer, crate " << m_crateID
               <<" Channel delay setting fails! " << std::endl;
      return false;
   }

   int rfadc, rch, rdelay;
   while( ifile_cd >> rfadc >> rch >> rdelay ){
      ch_delay[rfadc][rch] = rdelay;
   }

   ifile_cd.close();

   return true;

}

bool E14DAQParContainer::SetChannelDetector( void ){
   std::string ifname_det = Form("Crate%d_DetectorMap.txt",m_crateID);
   ifname_det = e14::setdir + "/mapfile/" + ifname_det;
   std::ifstream ifile_det( ifname_det.c_str() );

   if( ifile_det.fail() ){
      std::cout<<" [Error] E14DAQParContainer, crate " << m_crateID
               <<" Channel detector belonging setting fails! " << std::endl;
      return false;
   }

   int rfadc, rch, rdetid, NCH;
   while( ifile_det >> rfadc >> rch >> rdetid ){
      if( adctype[rfadc]==1 ) { NCH=16; }
      else if( adctype[rfadc]==2 ) { NCH=4; } 
      else continue;
      if( rch>=NCH ) continue;
      ch_detid[rfadc][rch] = rdetid;
   }

   return true;
}

bool E14DAQParContainer::SetPedestal( int runID ){

  TFile *fout = new TFile(Form("/raw_data/ped_data/crate%d/ped_run%d_crate%d.root",m_crateID,runID,m_crateID),"RECREATE");
  TTree *tr[16];
  if( !(fout->IsOpen()) ) return false;

  std::ifstream LowGainFile;
  LowGainFile.open("/DAQcodes/e14daq/current/setting/current/LowGain_Channel/LowGain_ChannelList.txt");
  short IsLowGain[16][16] = {0};
  int tcrate, tmod, tch;
  if( LowGainFile ){
    while( LowGainFile >> tcrate >> tmod >> tch ){
      if( tcrate!=m_crateID ) continue;
      IsLowGain[tmod][tch] = 1;
    }
  }
  std::ofstream ped_file(Form("/raw_data/ped_record/crate%d/ped_crate%d_run%d",m_crateID,m_crateID,runID));

  int NCHANNELS, NSAMPLE;
  int pedestal[16][48*4] = {};
  for( int slotid = 0; slotid < 16; slotid++ ){
    tr[slotid] = new TTree(Form("slot%d",(slotid+3)),"");
    tr[slotid]->Branch("NCHANNELS",&NCHANNELS,"NCHANNELS/I");
    tr[slotid]->Branch("NSAMPLE",&NSAMPLE,"NSAMPLE/I");
    tr[slotid]->Branch("pedestal",pedestal,"pedestal[16][192]/I");
    if( adctype[slotid]==1 ){
      NCHANNELS = 16; NSAMPLE = 48;
    }
    else if( adctype[slotid]==2 ){
      NCHANNELS = 4; NSAMPLE = 48*4;
    }
    else continue;

    std::ifstream ifile;
    ifile.open( Form("/DAQcodes/e14daq/current/database/ped_data/crate%d/fadc%d.txt", m_crateID, slotid) );
    if(!ifile) continue;
    TH1F *hdata[16];
    for( int i = 0; i < NCHANNELS; i++ ){
      hdata[i] = new TH1F(Form("h%i", i), "data hist", 16383, 0.5, 16383.5);
    }
    int ich = 0, data, isample = 0, header, pre_header = 0;
    for(int i=0;i<16;i++){ for(int j=0;j<192;j++) pedestal[i][j]=0; }

//    int NEVENT = 0;
    while( ifile >> std::hex >> data ){
      if( data == 0xef ) break; // end of file
      header = data >> 14; // C000
      if( pre_header != 2 && header == 2 ) { // begin of data
        ich = 0; isample = 0;
      }

      if( header == 2 ) { // data
        data = data & 0x3FFF;
        pedestal[ich][isample] = data;
        ich++;
        if( ich == NCHANNELS ) { ich = 0; isample++; }
      }

      if( pre_header == 2 && header != 2 ) { // end of data
        tr[slotid]->Fill();
        for( int i = 0; i < NCHANNELS; i++ ) {
          for( int j = 0; j < isample; j++ ) { hdata[i]->Fill(pedestal[i][j]); }
        }
      }

      pre_header = header;
    }
    ifile.close();
    //// End of pedestal txt data read in

    double m=0;
    double s=0;
    double eta=0;

    //Gaussian Fitting Function
    TF1 *gaus;
    for(int ich=0;ich<NCHANNELS;ich++){
      if(hdata[ich]->Integral()==0) { continue; }
      double Xmax = hdata[ich]->GetBinCenter( hdata[ich]->GetMaximumBin() );
//      hdata[ich]->SetAxisRange(Xmax-25.,Xmax+25.,"X");
      double fmin = Xmax-15., fmax = Xmax+5.;

      hdata[ich]->Fit("gaus", "Q", "", fmin, fmax);
      gaus = (TF1*)hdata[ich]->GetFunction("gaus");

      //Fitting Results
      m = gaus->GetParameter(1);
      s = gaus->GetParameter(2);

      int binmin = (int)(m-3*s+0.5);  // With current binning setup, this binmin corresponds to the number of bin where m-3*s falls in, similar for binmax in next line
      int binmax = (int)(m+1*s+0.5);
      eta = hdata[ich]->Integral(binmin,binmax);
      eta -= ( (m-3*s) - (binmin-0.5) ) * hdata[ich]->GetBinContent(binmin);
      eta -= ( (binmax+0.5) - (m+s) ) * hdata[ich]->GetBinContent(binmax);
      eta = (IsLowGain[slotid][ich]==1) ? 0 : (eta/(hdata[ich]->Integral()));

      ped_mean[slotid][ich] = m;
      ped_sigma[slotid][ich] = s;
      ped_eta[slotid][ich] = eta;
      ped_file << slotid<<"\t"<<ich<<"\t"<<m<<"\t"<<s<<"\t"<<eta<<"\n";
    }
    //// Fitting finished

    for( int i = 0; i < NCHANNELS; i++ ){
      delete hdata[i];
    }

  }//// End of slot loop

  ped_file.close();
  fout->Write();
  fout->Close();
  return true;

}

