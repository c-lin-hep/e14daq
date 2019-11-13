#include "VetoFanoutCDTManager.h"

VetoFanoutCDTManager::VetoFanoutCDTManager( void ) : VMEController(e14::vfcdt_slot,"fcdt"){

   Init();

}

VetoFanoutCDTManager::~VetoFanoutCDTManager(){
   ;
}

void VetoFanoutCDTManager::Init( void ){

   SetTestMode();

   write_reg("reset",1);
   write_reg("reset",1);

   write_reg("ena_sim_trig",0x0);
   write_reg("lvds_in_switch",0x0);
   write_reg("ena_digout_debug",0x0);

   write_reg("dc_err_max_time",e14::fanout_dc_err_maxt);

   write_reg("err_masking",e14::veto_masking);

}

void VetoFanoutCDTManager::SetTestMode( void ){

   write_reg("test_mode",1);

}

void VetoFanoutCDTManager::SetOperationMode( void ){

   write_reg("test_mode",0);

}
