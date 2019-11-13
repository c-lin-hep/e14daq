#include "EtOFCManager.h"

EtOFCManager::EtOFCManager( void ) : VMEController( e14::eofc_slot,"eofc"){

   Init();
   m_nwords_per_spill = 6000;

   m_data = new unsigned long [65536];

}

EtOFCManager::~EtOFCManager(){
   delete [] m_data;
}

void EtOFCManager::Init( void ){

   SetTestMode();

   write_reg("ena_lvds_cnt",0x0);

   write_reg("reset",1);
   write_reg("reset",1);

   //// ET ////
   write_reg("et_ptn_rx",e14::eofc_et_ptn_rx);
   write_reg("et_maxt",e14::eofc_et_ptn_maxt);
   write_reg("et_masking",e14::et_masking);
   write_reg("err_maxt",e14::eofc_err_maxt);

   //// VETO ////
   write_reg("veto_ptn_rx",e14::eofc_veto_ptn_rx);
   write_reg("veto_maxt",e14::eofc_veto_ptn_maxt);
   write_reg("veto_masking",e14::veto_masking);
 
   write_reg("err_maxt",e14::eofc_err_maxt);
   write_reg("ena_olrx",0x3ffff);

}

void EtOFCManager::SetTestMode( void ){

   write_reg("test_mode",1);

}

void EtOFCManager::SetOperationMode( void ){

   write_reg("test_mode",0);

}

void EtOFCManager::RunMollyFile( int runID, int spill ){

   const int nMaxWords = 65535;

   if( m_EnableMollyFile ){
      m_runID = runID;
      m_spill = spill + 1;
      write_reg("rawfile_en",1);
      m_EnableMollyFile = false;
      m_init_word = 0;
      return;
   }
   
   m_EnableMollyFile = false;
   write_reg("rawfile_en",0); 
   const unsigned long reg_addr = 0x900000; 
   int ntrig = read_reg("rawfile_ntrig");
   std::cout<<" Molly file: n words = " << ntrig << std::endl;

   int  init_word = m_init_word;
   int  end_word = m_nwords_per_spill + m_init_word;
   bool isReadAll = false;

   if( end_word > ntrig || end_word > nMaxWords ){
      end_word = ( ntrig > nMaxWords) ? nMaxWords : ntrig;
      m_EnableMollyFile = true;
      isReadAll = true;
   }

   for( int iword = init_word; iword < end_word; ++iword ){
       unsigned long addr = reg_addr + 4 * iword;
       m_data[iword] = read_word(addr);
   }   
   
   if( isReadAll ){
      std::string ofname = std::string("/raw_data/e14daq_data/molly_file")
                           + Form("/run%d_spill%d.txt",m_runID,m_spill);
      std::ofstream ofile( ofname.c_str() );

      /// add at 06/15 for protection
      int nwords = (ntrig > nMaxWords) ? nMaxWords : ntrig;  

      for( int iword=0; iword<nwords; ++iword ){
         ofile << m_data[iword] << std::endl;
      }

      ofile.close();
      for( int i=0; i<nMaxWords; ++i )
         m_data[i] = 0;

   }else{
      m_init_word = m_nwords_per_spill + m_init_word;
   } 

}
