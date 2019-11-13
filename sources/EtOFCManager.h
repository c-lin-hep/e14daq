/*
   EtOFCManager.h, inherited from class VMEController 
   Basic commands for FADC boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.24

*/

#ifndef ETOFCMANAGER_H
#define ETOFCMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "TString.h"

#include "Register.h"
#include "E14DAQParameter.h"
#include "E14DAQParContainer.h"
#include "VMEController.h"


class EtOFCManager : public VMEController {

 public:

   EtOFCManager( void );
    ~EtOFCManager();

   void Init( void );
 
   void SetTestMode( void );
   void SetOperationMode( void );

   void SetnWordsPerSpill( int nwords ){ m_nwords_per_spill = nwords; }
   void RunMollyFile( int runID, int spill );

 private:

   bool  m_EnableMollyFile;
   int   m_runID;
   int   m_spill;
   int   m_init_word; 
   int   m_nwords_per_spill;

   unsigned long*  m_data;

};

#endif
