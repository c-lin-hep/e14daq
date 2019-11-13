/*
   VMEController.h 
   Interface of VME bus

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)

*/

#ifndef VMECONTROLLER_H
#define VMECONTROLLER_H

#include <iostream>
#include <cstdio>
#include <string>

#include <vme/vme.h>
#include <vme/vme_api.h>

#include "Register.h"

#define ADDRESS_MODIFIER  VME_A32SD
#define ADDRESS_MODIFIER_BLOCK VME_A32SB

class VMEController{

 public:
    VMEController(int slot, std::string bdname );
    ~VMEController();

 public: 
   bool isError( void ){ return m_isError; }
   std::string boardname( void ){ return m_bdname; }

   void init( void );

   int read_word( int addr );
   int write_word( int addr, int value);

   int read_reg( struct reg::control_reg const *ctrl_reg, char const name[32] );
   int write_reg( struct reg::control_reg const *ctrl_reg, char const name[32], unsigned long new_value );

   int read_reg( char const name[32] );
   int write_reg( char const name[32], unsigned long new_value );

   int read_blt( unsigned long addr, unsigned long *buffer, unsigned long nwords );

   int version( void );
   void SetCheckFlag( bool isCheckFlag ){ m_isCheckFlag = isCheckFlag; }
//   void SetCrateID( int crateID ){ m_crateID = crateID; }

 protected:
   int m_crateID;
   int m_slotID;
   std::string m_bdname;
   
 private:
   struct reg::control_reg const *m_ctrl_reg;
  
   bool m_adc_flag;
   bool m_isError;
   bool m_isCheckFlag; 

   static const int NBYTES = 0x01;
   static const int NWORDS = 32; 
 
};

#endif
