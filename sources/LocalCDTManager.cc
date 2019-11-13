#include "LocalCDTManager.h"

LocalCDTManager::LocalCDTManager( int crateID ) : VMEController(e14::lcdt_slot,"lcdt"){

   m_crateID = crateID;

}

LocalCDTManager::~LocalCDTManager(){
   ;
}

void LocalCDTManager::Init( void ){

   SetTestMode();

   write_reg("reset",1);
   write_reg("reset",1);

   write_reg("lvds_in_switch",0x0);
   write_reg("lvds_debug_mode",0);
   write_reg("ena_digout_debug",0);

}

void LocalCDTManager::SetTestMode( void ){

   write_reg("test_mode",1);

}

void LocalCDTManager::SetOperationMode( void ){

   write_reg("test_mode",0);

}

void LocalCDTManager::SetVeto( void ){

   write_reg("is_veto_crate",1);
   write_reg("ena_olrx",0x0);

}

void LocalCDTManager::SetVeto( E14DAQParContainer par ){

   SetVeto();
   SetErrMaxTime( e14::local_tlk_err_maxt , e14::local_dc_err_maxt );
   SetDetectorBit( par.detbit );
   SetMasking( e14::adc_input_mask[m_crateID] );

   /// max t for receiving pattern
   write_reg("veto_maxt",e14::veto_ptn_maxt);

}

void LocalCDTManager::SetMasking( int mask ){

   write_reg("veto_masking",mask); // ADC input mask
   write_reg("dc_olrx_masking",mask);

}

void LocalCDTManager::SetErrMaxTime( int tlk_err_maxt , int dc_err_maxt ){

   write_reg("tlk_err_max_time",tlk_err_maxt);
   write_reg("dc_err_max_time",dc_err_maxt);

}

void LocalCDTManager::SetDetectorBit( int* detbit ){

   // bug found in 06/08 
   // int nchs = ( e14::is500mhzCrate[m_crateID] ) ? e14::n500mhzChannels : e14::nChannels;

   // for( int ich=0; ich<nchs; ++ich ){
   for( int ifadc=0; ifadc<e14::nFADCs; ++ifadc ){
      char reg_name[100];
      sprintf( reg_name, "ch%d_detbit", ifadc);
      int reg_val = (detbit[ifadc] >= 0) ? detbit[ifadc] : 15;
      write_reg(reg_name,reg_val);
   }

}

void LocalCDTManager::SetEtSum( void ){

   write_reg("ena_olrx",0xf);
   write_reg("et_maxt",e14::et_ptn_maxt);

   write_reg("et_masking",0x0);
   write_reg("et_ptn_rx0",0xffff);
   write_reg("et_ptn_rx1",0xffff);
   write_reg("et_ptn_rx2",0xffff);
   write_reg("et_ptn_rx3",0xffff);
   write_reg("is_veto_crate",0);
   write_reg("err_adc_masking",0x0);
   write_reg("ena_err_sim_trig",0x0);

   SetErrMaxTime( e14::local_tlk_err_maxt , e14::local_dc_err_maxt );

   write_reg("tlk_olrx_masking",0x0);
   write_reg("dc_olrx_masking",0x0);

}
