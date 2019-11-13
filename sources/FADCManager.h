/*
   FADCManager.h, inherited from class VMEController 
   Basic commands for FADC boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.23

*/

#ifndef FADCMANAGER_H
#define FADCMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "TROOT.h"
#include "TMath.h"

#include "Register.h"
#include "E14DAQParameter.h"
#include "VMEController.h"
#include "DetParContainer.h"


class FADCManager : public VMEController {

 public:

   FADCManager( int crateID , int slotNo , int runID );
    ~FADCManager();

   void Init( void );
   int  boardtype( void ){ return m_boardtype; }  

   void SetDaisyChain( int ifadc ); 
   void SetVeto( void );
   void ResetSpill( void );

   void SetPeakScan( int init_delay );
   void SetPeakWindow( void );
   void SetPeakWindow( int tleft, int tright);
   void SetPeakThreshold( int* thr );
   void SetPeakWindowDelay( int delay ); 
   void SetBitMapDelay( int delay );
   void SetMasking( bool* mask );
   void SetLinearFunc( int* p0, int* p1 );
   void SetChannelDelay( int* delay );
   void SetPedMeanSigma( double* mean, double* sigma, double* eta, int* ch_det, DetParContainer* DPC );

   void RunPeakScan( void );

   void SetDBMode( void );   

   void RunDBCaptureForPed( void );
   void RunDBCapture( int runID );
   void RunDBCaptureSpillBase( int runID, int SpillNo );

 private:
   int m_runID;
   int m_boardtype; 

   void SetBoardType( void );

};

#endif
