/*
   ThresholdDBManager.h, inherited from class VMEController 
   Basic commands for CDT boards

   Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
   2017.05.24

*/

#ifndef THRESHOLDDBMANAGER_H
#define THRESHOLDDBMANAGER_H

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>

#include "Register.h"
#include "E14DAQParameter.h"
#include "E14DAQParContainer.h"
#include "VMEController.h"


class ThresholdDBManager{

 public:
  ThresholdDBManager();
  ~ThresholdDBManager(void);

  void ReadThresholdFromTxt(char* InFileName);
  void ReadRMSFromTxt(char* InFileName);
  void ReadPedMeanSigmaFromTxt(char* InFileName);
  int GetThreshold_trg(int module,int ch);
  int GetThreshold_scaler(int module,int ch);

  int GetMeVPerThreshold(char* InFileName);
  int* GetCOEdiscriThreshold(char* InFileName);

  double GetRMSmaskThreshold(char* InFileName);
  double GetRMS(int crate,int mod,int ch);
  double GetPedMean(int crate,int slot,int ch);
  double GetPedSigma(int crate,int slot,int ch);
  void CalculatePedMeanSigma( const int runID, const int icrate );

 private:
  void init(void);

  int thr_offset_trg[20][16];
  int thr_offset_scaler[20][16];
  int COEthreshold[2];

  double rms_mean[20][20][16];
  double ped_mean[20][20][16];
  double ped_sigma[20][20][16];
  int    m_pedestal[16][48*4]; // [FADC][CH][SAMPLE]



};

#endif
