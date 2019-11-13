#include "DetParContainer.h"

DetParContainer::DetParContainer( int crate, int run, std::string runtype ){
  m_crateID = crate;
  m_runID = run;
  Init(runtype);
}

DetParContainer::~DetParContainer( void ){
  ;
}

void DetParContainer::Init( std::string runtype ){
  std::string ifname_det = e14::setdir + "/DetectorConfig/DetPSConfig_" + runtype + ".txt" ;
  std::ifstream ifile_det( ifname_det.c_str() );

  if( ifile_det.fail() ){
    std::cout << " [Error] DetParContainer, crate "<< m_crateID
              << " Cannot Open: " << ifname_det << std::endl;
    TotalNumofDet = 0;
    return;
  }

  int ndet = 0;
  int tdetid;
  short tuseps, tusefixthr;
  double tsigthr, tetathr, tthrsetup;
  while( ifile_det >> tdetid ){
    while( ndet < tdetid ){
      Pedestal_SigmaThr.push_back(0.0);
      Pedestal_EtaThr.push_back(1.0);
      Use_PS.push_back(0);
      Use_FixPSThr.push_back(1);
      PSThrSetupValue.push_back(0.0);
      ndet++;
    }
    if( !(ifile_det >> tsigthr >> tetathr >> tuseps >> tusefixthr >> tthrsetup) ) {break;}
    Pedestal_SigmaThr.push_back(tsigthr);
    Pedestal_EtaThr.push_back(tetathr);
    Use_PS.push_back(tuseps);
    Use_FixPSThr.push_back(tusefixthr);
    PSThrSetupValue.push_back(tthrsetup);
    ndet++;
  }

  ifile_det.close();
  return;
}


short DetParContainer::GetUsePS( int DetID ){
  if( DetID>=TotalNumofDet ) { return 0; }
  return Use_PS[DetID];
}


double DetParContainer::GetSigThr( int DetID ){
  if( DetID>=TotalNumofDet ) { return 0; }
  return Pedestal_SigmaThr[DetID];
}


double DetParContainer::GetEtaThr( int DetID ){
  if( DetID>=TotalNumofDet ) { return 0; }
  return Pedestal_EtaThr[DetID];
}


int DetParContainer::GetPSThr( int DetID, double ch_sigma ){
  int reg_s;
  if( DetID>=TotalNumofDet ) { reg_s = (int)(3*ch_sigma); return reg_s; }

  if( Use_FixPSThr[DetID]==1 ) { reg_s = (int)PSThrSetupValue[DetID]; }
  else { reg_s = (int)(PSThrSetupValue[DetID]*ch_sigma); }
  return reg_s;
}

