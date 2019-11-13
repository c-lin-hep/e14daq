/*
   CSIFanoutCDTManager.h, inherited from class VMEController 
   Basic commands for CDT boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.24

*/

#ifndef CSIFANOUTCDTMANAGER_H
#define CSIFANOUTCDTMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "Register.h"
#include "E14DAQParameter.h"
#include "E14DAQParContainer.h"
#include "VMEController.h"


class CSIFanoutCDTManager : public VMEController {

 public:

   CSIFanoutCDTManager( void );
    ~CSIFanoutCDTManager();

   void Init( void );
 
   void SetTestMode( void );
   void SetOperationMode( void );

 private:

};

#endif
