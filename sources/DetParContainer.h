

#ifndef DETPARCONTAINER_H
#define DETPARCONTAINER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "E14DAQParameter.h"

#include <TROOT.h>
#include "TFile.h"
#include "TTree.h"
#include "TH1.h"
#include "TF1.h"
#include "TMath.h"

class DetParContainer{

  public:
	DetParContainer( int crate, int run, std::string runtype );
	~DetParContainer();

	void Init( std::string runtype );
	short GetUsePS( int DetID );
	double GetSigThr( int DetID );
	double GetEtaThr( int DetID );
	int GetPSThr( int DetID, double ch_sigma );

  private:
	int m_crateID;
	int m_runID;

	int TotalNumofDet;
	std::vector<short> Use_PS;
	std::vector<double> Pedestal_SigmaThr;
	std::vector<double> Pedestal_EtaThr;
	std::vector<short> Use_FixPSThr;
	std::vector<double> PSThrSetupValue;

};

#endif

