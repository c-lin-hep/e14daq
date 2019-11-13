/*
   TopCDTManager.h, inherited from class VMEController 
   Basic commands for FADC boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.24

*/

#ifndef TOPCDTMANAGER_H
#define TOPCDTMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "TTree.h"

#include "Register.h"
#include "E14DAQParameter.h"
#include "E14DAQParContainer.h"
#include "VMEController.h"


class TopCDTManager : public VMEController {

 public:

   TopCDTManager( void );
    ~TopCDTManager();

   void Init( void );
   void SetTree( TTree* tr );
 
   void SetTestMode( void );
   void SetOperationMode( void );

//   void SetDisplayErr( bool isDisplayErr ){ m_isDisplayErr = isDisplayErr; }
//   void SetDisplayTrigCnt( bool isDisplayTrigCnt ){ m_isDisplayTrigCnt = isDisplayTrigCnt; }
//   void SetSaveErr( bool isSaveErr ){ m_isSaveErr = isSaveErr; }
//   void SetSaveTrigCnt( bool isSaveTrigCnt ){ m_isSaveTrigCnt = isSaveTrigCnt; }

   bool SetTrigType(char const* runtype , int typeno );
   bool SetExtTrigType(char const* runtype, int typeno );

   void UpdateErr( int spill );
   void UpdateCounters( int spill );

   void SaveErr( int runID, int spill );
   void SaveCounters( int runID, int spill );

   void PrintErr( void );
   void PrintCounter( void );

 private:

   Int_t  m_spill;

   Bool_t m_isTLKErr;
   Bool_t m_isDCErr;
   Bool_t m_isLocalAlignErr;
   Bool_t m_isGlobalAlignErr;
   Bool_t m_isClusDeltaErr;
   Bool_t m_isClusIdErr;
   Bool_t m_isClusTimeErr;

   Int_t  m_EtAlignPtnTime;
   Int_t  m_VetoAlignPtnTime;
   Int_t  m_EtDeltaPtnTime;
   Int_t  m_VetoDeltaPtnTime;
   Int_t  m_DelayClusTime;
   Int_t  m_EarlyLv1Time;

   Int_t  m_EtDeltaPtn;
   Int_t  m_VetoDeltaPtn;
   Int_t  m_EtDeltaLv1aTime;
   Int_t  m_VetoDeltaLv1aTime;

   Int_t  m_ndelta;
   Int_t  m_lv1a_raw_cnt;
   Int_t  m_lv1a_cnt;
   Int_t  m_lv1a_rej_cnt;
   Int_t  m_lv1_cnt;
   Int_t  m_lv1_ps_cnt;
   Int_t  m_lv2_rej_cnt;

   Int_t  m_raw_clus_cnt[10];
   Int_t  m_scaled_clus_cnt[10];
   Int_t  m_type_lv1a_raw_cnt[8];
   Int_t  m_type_lv1a_scaled_cnt[8];
   Int_t  m_type_lv1b_raw_cnt[8];
   Int_t  m_type_lv1b_scaled_cnt[8];
   Int_t  m_veto_cnt[16];
   Int_t  m_et_cnt;
   Int_t  m_ext_cnt[2];
   Int_t  m_ext_data[2];

   Int_t  m_csi_cnt;

//   bool    m_isDisplayErr;
//   bool    m_isDisplayTrigCnt;
//   bool    m_isSaveErr;
//   bool    m_isSaveTrigCnt;
 
//   void    ErrDisplay( int val , int nbits , bool isReverse );
//   void    ErrOfstream( int val , int nbits , bool isReverse, std::ofstream ofile);
  
};

#endif
