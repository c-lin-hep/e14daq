/*
   ClusOFCManager.h, inherited from class VMEController 
   Basic commands for OFC boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.24

*/

#ifndef CLUSOFCMANAGER_H
#define CLUSOFCMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "Register.h"
#include "E14DAQParameter.h"
#include "E14DAQParContainer.h"
#include "VMEController.h"


class ClusOFCManager : public VMEController {

 public:

   ClusOFCManager( void );
    ~ClusOFCManager();

   void Init( void );
 
   void SetTestMode( void );
   void SetOperationMode( void );

 private:

};

#endif
