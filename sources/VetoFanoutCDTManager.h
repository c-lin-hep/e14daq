/*
   VetoFanoutCDTManager.h, inherited from class VMEController 
   Basic commands for CDT boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.24

*/

#ifndef VETOFANOUTCDTMANAGER_H
#define VETOFANOUTCDTMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "Register.h"
#include "E14DAQParameter.h"
#include "E14DAQParContainer.h"
#include "VMEController.h"


class VetoFanoutCDTManager : public VMEController {

 public:

   VetoFanoutCDTManager( void );
    ~VetoFanoutCDTManager();

   void Init( void );
 
   void SetTestMode( void );
   void SetOperationMode( void );

 private:
   std::string m_type;

};

#endif
