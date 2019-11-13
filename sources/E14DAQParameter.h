/*
    E14DAQSettings.h 
    All of the fundemental parameters are listed here for board settings.

    Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
    Date  : 2018.05.22

*/

#ifndef E14DAQPARAMETER_H
#define E14DAQPARAMETER_H

#include <string>

namespace e14{

   typedef enum { CC03=0, CC04, CC05, CC06,
		  CBAR,   FBAR, CSI,  BHPV, 
		  CV,     NCCIndi, NCCComm, NCCScin,
		  OEV,    LCV,  DCV,  newBHCV,
		  BHGC,   IB,   IBCV, MBCV, 
		  MPPC,   COSMIC, ExtTrig } DetectorID;

   const int nDet = 23;  // Total 21 detector in use; +2 (NCC => Individual Common Scintilator)

   const std::string DetName[nDet]={ /*0*/"CC03",  /*1*/"CC04", /*2*/"CC05",  /*3*/"CC06",
				/*4*/"CBAR",  /*5*/"FBAR", /*6*/"CSI",   /*7*/"BHPV",
				/*8*/"CV",    /*10*/"NCCIndi", /*10*/"NCCComm", /*11*/"NCCScin",
				/*12*/"OEV",  /*13*/"LCV", /*14*/"DCV",  /*15*/"newBHCV",
				/*16*/"BHGC", /*17*/"IB",  /*18*/"IBCV", /*19*/"MBCV",
				/*20*/"MPPC", /*21*/"COSMIC", /*22*/"ExtTrig" };

/////////////////////////////////////////////////
// Below are thresholds to identify noisy channels for various detectors
// If detector characteristics unknown, for 125MHz set SigThr=>4.0 EtaThr=>0.75, for 500MHz set SigThr=>2.0 EtaThr=>0.80
// If one detector would not be applied pedestal-suppression, then set SigThr=>0.0 EtaThr=>1.00 (e.g. newBHCV NCC-Scintilator)
// If one detector would not need noisy channels to be identified, then set SigThr=>999 EtaThr=>0.01 (e.g. CV) 
   const double PedSigThr[nDet]={ 4.0, 3.5, 3.5, 4.0, 
				  3.5, 4.0, 4.0, 2.0,
				  999, 3.0, 4.0, 0.0,
				  4.0, 3.5, 4.0, 0.0,
				  2.0, 2.0, 3.5, 3.0,
				  4.0, 4.0, 4.0 };
   const double PedEtaThr[nDet]={ 0.75, 0.70, 0.75, 0.65,
				  0.75, 0.70, 0.75, 0.75,
				  0.01, 0.80, 0.65, 1.00,
				  0.80, 0.75, 0.75, 1.00,
				  0.80, 0.80, 0.75, 0.75,
				  0.75, 0.75, 0.75 };
/////////////////////////////////////////////////

   const std::string setdir = "/DAQcodes/e14daq/current/setting/current";
   const std::string rctrl_db_dir = "/DAQcodes/e14daq/current/run_ctrl/db_mode/current";
   const std::string trigcnt_dir = "/raw_data/e14daq_data/trigcnt";
   const std::string errlog_dir = "/raw_data/e14daq_data/errlog";
   const std::string parlog_dir = "/raw_data/e14daq_data/parlog";
   const std::string config_dir = "/DAQcodes/e14daq/current/run_ctrl/collect_data/current/run_config";
   //const std::string mon_dir = "/raw_data/monitor_data";
   const std::string mon_dir = "/DAQcodes/e14daq/current/monitor";

   const int nFADCs = 16;
   const int nCrates = 18;
   const int nChannels = 16;
   const int n500mhzChannels = 4;
   const int nDaisyChains = 4;
   const int nDaisyChainMembers = 4;
   const int nTrigTypes = 8;
   const int nExtTrig   = 4;

   const int tcdt_slot  = 2 ;
   const int cfcdt_slot = 5 ;
   const int vfcdt_slot = 8 ;
   const int eofc_slot  = 11;
   const int cofc_slot  = 14;
   const int lcdt_slot  = 1;

   //// run81 settings ////
   const int et_masking = 0x0;
   const int veto_masking = 0xffb0;

   const int delay_raw       = 370;
   const int delay_lv1b_req  = 210;
   const int delay_lv1       = 44; 

   //// test for run81
   const int delay_cb     = 361;
   const int delay_cb_map = 256;

   /// run79 settings 
   // const int delay_cb     = 361;
   // const int delay_cb_map = 256;

   const int delay_vb     = 150;
   const int delay_vb_map = 256; // 2018.06.04: change from 463 -> 256

   //const int delay_vb
  
   /// run81, 01/30 test 
   const int delay_offset_125mhz = 4;  // VB delay has 4 clock offset btw 125 and 500 mhz
   const int veto_ptn_maxt = 100;
   const int et_ptn_maxt = 250;
   const int et_dc_maxt = 50;

   /*     
    *  crate 13, board 4  - 12 : NCC individuals, board 15 : MPPC
    *  crate 14, board 12      : Trigger Tag Board (MUST BE MASKED!!!)
    *  crate 15, board 0       : Special BHPV channel 40-41
    *            board 11 - 15 : MPPCs
    *  crate 16, board 12 - 15 : MPPCs
    *     */
   const int adc_input_mask[nCrates] =
   {   0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000
     , 0x0000 , 0x0000 , 0x0000 , 0x0000 , 0x0000
     , 0x0000 , 0xf000 , 0x0000 , 0x9ff0 , 0x1000
     , 0xf801 , 0xf000 , 0x0000 };


   const bool isVetoCrate[nCrates] = 
   {   false , false , false , false , false 
     , false , false , false , false , false 
     , false , true  , true  , true  , true
     , true  , true  , true  };

   const bool is500mhzCrate[nCrates] =
   {   false , false , false , false , false
     , false , false , false , false , false
     , false , false , false , false , false
     , true  , true  , true  };

   const int local_tlk_err_maxt = 11250000;
   const int local_dc_err_maxt  = 12500500;

   const int fanout_tlk_err_maxt = 11875000;
   const int fanout_dc_err_maxt = 12500700;

   const int spill_off_time = 350000000;

   const int local_et_thr = 196608; // ( 3 MeV << 16 )

   const int eofc_et_ptn_rx = 0xfefe;
   const int eofc_et_ptn_maxt = 250;
   const int eofc_veto_ptn_rx = 0xfefe;
   const int eofc_veto_ptn_maxt = 250;
   const int eofc_err_maxt = 500;


};

#endif
