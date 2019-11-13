#include "ClusOFCManager.h"

ClusOFCManager::ClusOFCManager( void ) : VMEController( e14::cofc_slot,"cofc"){

   Init();

}

ClusOFCManager::~ClusOFCManager(){
   ;
}

void ClusOFCManager::Init( void ){

   SetTestMode();

   write_reg("reset",1);
   write_reg("reset",1);

   write_reg("ena_lvds_cnt",0x0);
   write_reg("ena_olrx",0x007ff);

}

void ClusOFCManager::SetTestMode( void ){

   write_reg("test_mode",1);

}

void ClusOFCManager::SetOperationMode( void ){

   write_reg("test_mode",0);

}
