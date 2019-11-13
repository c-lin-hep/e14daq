/*
   E14DAQCrateContainer.h 
   Use to save all of the DAQ parameters

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)

*/

#ifndef E14DAQPARCONTAINER_H
#define E14DAQPARCONTAINER_H

#include <iostream>
#include <fstream>
#include <string>

#include <TROOT.h>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TF1.h"
#include "TMath.h"

#include "E14DAQParameter.h"

class E14DAQParContainer{

 public:
    E14DAQParContainer(int crateID, int runID );
    ~E14DAQParContainer();

    void Init( void );

    void SetADCType( int slot , int type );
    bool SetADCSlot( void );
    bool SetPeakThreshold( std::string runtype );
    bool SetTimingWindow( std::string runtype );
    bool SetMasking( std::string runtype );
    bool SetDetectorBit( void );
    bool SetETLinearFunc( void );
    bool SetChannelDelay( void );
    bool SetPedestal( int runID );
    bool SetChannelDetector( void );

 private:
    static const int s_nfadc = 16;
    static const int s_nch   = 16;
    
    int  m_crateID;
    int  m_runID;
 
 public:
    int   adctype[s_nfadc];
    int   slot[s_nfadc];
    int   thr[s_nfadc][s_nch];
    int   tleft[s_nfadc];
    int   tright[s_nfadc];
    bool  mask[s_nfadc][s_nch];
    int   detbit[s_nfadc];
    int   p0[s_nfadc][s_nch];
    int   p1[s_nfadc][s_nch];
    int   ch_delay[s_nfadc][s_nch];
    int   ch_detid[s_nfadc][s_nch];
    double ped_mean[s_nfadc][s_nch];
    double ped_sigma[s_nfadc][s_nch];
    double ped_eta[s_nfadc][s_nch];

};

#endif
