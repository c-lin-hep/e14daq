#include "VMEController.h"

VMEController::VMEController( int slot, std::string bdname ) : m_slotID(slot) ,
                                                               m_bdname(bdname)
{

   m_adc_flag = false;
   m_isError = false;

   if( m_bdname == "adc" )
   {
      m_adc_flag = true;
      m_ctrl_reg = reg::adc_reg;
   }
   else if( m_bdname == "tcdt" )
      m_ctrl_reg = reg::tcdt_reg;
   else if( m_bdname ==  "fcdt" )
      m_ctrl_reg = reg::fcdt_reg;
   else if( m_bdname == "lcdt" )
      m_ctrl_reg = reg::lcdt_reg;
   else if( m_bdname == "eofc" )
      m_ctrl_reg = reg::eofc_reg;
   else if( m_bdname == "cofc" )
      m_ctrl_reg = reg::cofc_reg;
   else
   { 
      std::cout<<" [Error] No such b ! " << std::endl;
      m_isError = true;
   }

   m_isCheckFlag = false;
   m_crateID = -1;

}

VMEController::~VMEController(){
   ;
}

void VMEController::init( void ){

  int ireg = 0;

   while( strcmp(m_ctrl_reg[ireg].name,"END") == 0  ){
      write_reg(m_ctrl_reg[ireg].name,m_ctrl_reg[ireg].default_value);
      ++ireg;
   }   

}


int VMEController::read_word( int user_addr ) {

    int addr = m_slotID*(0x8000000) + user_addr;
    if( m_adc_flag )
       addr = m_slotID*(0x8000000);

    vme_bus_handle_t bus_handle;
    vme_master_handle_t window_handle;
    uint32_t *ptr, data_word;

    for( int iloop = 0; iloop<3; ++iloop ){

    if (vme_init(&bus_handle)) {
                perror("Error initializing the VMEbus");
                return -1;
    }

    int val = (m_adc_flag) ? NWORDS * 4 : NBYTES;

    if (vme_master_window_create(bus_handle, &window_handle,
                                 addr, ADDRESS_MODIFIER, val,
                                 VME_CTL_PWEN, NULL)) {
                perror("Error creating the window");
                vme_term(bus_handle);
                return -1;
    }

    ptr = (uint32_t*)vme_master_window_map(bus_handle, window_handle, 0);

    if (!ptr) {
         perror("Error mapping the window");
         vme_master_window_release(bus_handle, window_handle);
         vme_term(bus_handle);
         return -1;
    }

    data_word= (m_adc_flag) ? *(ptr + user_addr) : *(ptr);

    if (vme_master_window_unmap(bus_handle, window_handle)) {
                perror("Error unmapping the window");
                vme_master_window_release(bus_handle, window_handle);
                vme_term(bus_handle);
                return -1;
        }

        if (vme_master_window_release(bus_handle, window_handle)) {
                perror("Error releasing the window");
                vme_term(bus_handle);
                return -1;
        }

        if (vme_term(bus_handle)) {
                perror("Error terminating");
                return -1;
        }

  }

  return data_word;

}

int VMEController::write_word( int user_addr, int value ) {

    int addr = m_slotID * (0x8000000) + user_addr;
    if( m_adc_flag ) 
       addr = m_slotID * (0x8000000);

    vme_bus_handle_t bus_handle;
    vme_master_handle_t window_handle;
    uint32_t *ptr;

    if (vme_init(&bus_handle)) {
                perror("Error initializing the VMEbus");
                return -1;
        }

    int val = (m_adc_flag) ? NWORDS * 4 : NBYTES;

    if (vme_master_window_create(bus_handle, &window_handle,
                                 addr, ADDRESS_MODIFIER, val,
                                 VME_CTL_PWEN, NULL)) {
             perror("Error creating the window");
             vme_term(bus_handle);
             return -1;
    }

    ptr = (uint32_t*)vme_master_window_map(bus_handle, window_handle, 0);
    
    if (!ptr) {
                perror("Error mapping the window");
                vme_master_window_release(bus_handle, window_handle);
                vme_term(bus_handle);
                return -1;
    }

    if( m_adc_flag )
       *(ptr + user_addr) = value;
    else
       *(ptr) = value;

    if (vme_master_window_unmap(bus_handle, window_handle)) {
                perror("Error unmapping the window");
                vme_master_window_release(bus_handle, window_handle);
                vme_term(bus_handle);
                return -1;
        }

        if (vme_master_window_release(bus_handle, window_handle)) {
                perror("Error releasing the window");
                vme_term(bus_handle);
                return -1;
        }

        if (vme_term(bus_handle)) {
                perror("Error terminating");
                return -1;
        }

   return 0;

}

int VMEController::read_reg(struct reg::control_reg const *ctrl_reg, char const name[32] )
{
     unsigned long       data_word,address;
     int                 i;

     for(i=0;i<350;i++)                                                      // Find Register Name
     {
             if(strcmp(name,ctrl_reg[i].name)==0)break;
             if(strcmp(ctrl_reg[i].name,"END")==0)break;
     }
        
     if(strcmp(ctrl_reg[i].name,"END")==0)
        { printf(" Register Name not found :  %s \n",name); return -1 ;}
     else
        {
             address = ctrl_reg[i].address;      // Set address offset
             data_word = read_word( address );
             if( data_word < 0 ){ return -1; }    // Check for ERROR

             data_word = (data_word & ctrl_reg[i].mask) >> ctrl_reg[i].start_bit;

        }

     return data_word;
}

int VMEController::write_reg(struct reg::control_reg const *ctrl_reg, char const name[32], unsigned long new_value)
{
     unsigned long       address,data_word,value,mask;
     int                 status = -1 ,i;

     for(i=0;i<350;i++)  // Find Register Name
     {
          if(strcmp(name,ctrl_reg[i].name)==0)break;
          if(strcmp(ctrl_reg[i].name,"END")==0)break;
     }
        
     if(strcmp(ctrl_reg[i].name,"END")==0)
     { 
        printf(" Register Name not found :  %s \n",name); return -1 ;
     }
     else
     {
          address = ctrl_reg[i].address;   // Set address offset
          mask = ctrl_reg[i].mask;
          value = read_word( address );    // Get existing word

          data_word = (value & (~mask)) | 
                      ((new_value & (mask>>ctrl_reg[i].start_bit)) << ctrl_reg[i].start_bit);

          if( strcmp(ctrl_reg[i].type,"rw") !=0 )
          { 
             printf("    <%s>  %i %s register is Read Only\n",ctrl_reg[i].name,i,name);
          }
          else
          {
             status = write_word( address, data_word );  // Write VME Bus
             value = read_word( address );               // Get existing word
          }
                
          if( status < 0 ) return -1; // Check for ERROR
     }
        
     return 0;
}

int VMEController::read_reg( char const name[32] ){
   
   return read_reg(m_ctrl_reg,name);

}

int VMEController::write_reg( char const name[32] , unsigned long new_value ){

   /// added at 02/24
   int val = 0, trial_cnt = 0;
   val = write_reg(m_ctrl_reg,name,new_value);
   while( m_bdname=="adc" && m_isCheckFlag && new_value != read_reg(name) ){
      val = write_reg(m_ctrl_reg,name,new_value);
      std::cout<<" Register writing error : " << name 
               <<" for board in crate" << m_crateID << "-slot " << m_slotID 
               <<" ( trial # : " << ++trial_cnt << " ) " << std::endl;    
      std::cout<<" *** Now re-initialize ... " << std::endl;
   }

   return val;
}

int VMEController::version( void ){

   if( m_bdname == "adc" ){
      return read_reg("code_revision");
   }
   else{
      return read_reg("version");
   }

}

int VMEController::read_blt(unsigned long addr, unsigned long *buffer, unsigned long nwords){

  if( m_bdname != "adc" )
     return -1;

        vme_bus_handle_t bus_handle;
        vme_dma_handle_t dma_handle;
        uint32_t *ptr;
        int nbytes=4*nwords;

        addr=m_slotID*(0x8000000) + addr;

        if (vme_init(&bus_handle)) {
                perror("Error initializing the VMEbus");
                return -1;
        }

        if (vme_dma_buffer_create(bus_handle, &dma_handle, nbytes, 0, NULL)) {
                perror("Error creating the buffer");
                vme_term(bus_handle);
                return -1;
        }

        ptr = (uint32_t*)vme_dma_buffer_map(bus_handle, dma_handle, 0);
        if (!ptr) {
                perror("Error mapping the buffer");
                vme_dma_buffer_release(bus_handle, dma_handle);
                vme_term(bus_handle);
                return -1;
        }

        /* Transfer the data */
        if (vme_dma_read(bus_handle, dma_handle, 0, addr, ADDRESS_MODIFIER_BLOCK, nbytes, 0) ) {
                perror("Error reading data");
                vme_dma_buffer_unmap(bus_handle, dma_handle);
                vme_dma_buffer_release(bus_handle, dma_handle);
                vme_term(bus_handle);
                return -1;
        }

       for (unsigned int i = 0; i < nwords; i++) {
                buffer[i]=*(ptr+i);  // Move data from dma buffer to data buffer
        }

        if (vme_dma_buffer_unmap(bus_handle, dma_handle)) {
                perror("Error unmapping the buffer");
                vme_dma_buffer_release(bus_handle, dma_handle);
                vme_term(bus_handle);
                return -1;
        }

        if (vme_dma_buffer_release(bus_handle, dma_handle)) {
                perror("Error releasing the buffer");
                vme_term(bus_handle);
                return -1;
        }
        if (vme_term(bus_handle)) {
                perror("Error terminating");
                return -1;
        }
        return 0;

}
