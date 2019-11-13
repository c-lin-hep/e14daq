/*
   LocalCDTManager.h, inherited from class VMEController 
   Basic commands for CDT boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.24

*/

#ifndef LOCALCDTMANAGER_H
#define LOCALCDTMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "Register.h"
#include "E14DAQParameter.h"
#include "E14DAQParContainer.h"
#include "VMEController.h"


class LocalCDTManager : public VMEController {

 public:

   LocalCDTManager( int crateID );
    ~LocalCDTManager();

   void Init( void );
 
   void SetTestMode( void );
   void SetOperationMode( void );

   void SetVeto( void );
   void SetVeto( E14DAQParContainer par );
   void SetEtSum( void );

   void SetDetBit( int* detbit );
   void SetMasking( int mask );
   void SetErrMaxTime( int tlk_err_maxt , int dc_err_maxt );
   void SetDetectorBit( int* detbit );

 private:
   int m_crateID;

};

#endif
