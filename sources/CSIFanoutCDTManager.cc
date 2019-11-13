#include "CSIFanoutCDTManager.h"

CSIFanoutCDTManager::CSIFanoutCDTManager( void ) : VMEController(e14::cfcdt_slot,"fcdt"){

   Init();

}

CSIFanoutCDTManager::~CSIFanoutCDTManager(){
   ;
}

void CSIFanoutCDTManager::Init( void ){

   SetTestMode();

   write_reg("reset",1);
   write_reg("reset",1);

   write_reg("ena_sim_trig",0x0);
   write_reg("lvds_in_switch",0x0);
   write_reg("ena_digout_debug",0x0);

   write_reg("tlk_err_max_time",e14::fanout_tlk_err_maxt);
   write_reg("dc_err_max_time",e14::fanout_dc_err_maxt);

   write_reg("err_masking",e14::et_masking);

}

void CSIFanoutCDTManager::SetTestMode( void ){

   write_reg("test_mode",1);

}

void CSIFanoutCDTManager::SetOperationMode( void ){

   write_reg("test_mode",0);

}
