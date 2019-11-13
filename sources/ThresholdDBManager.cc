#include "ThresholdDBManager.h"

ThresholdDBManager::ThresholdDBManager(void){ 
  init(); 
}

ThresholdDBManager::~ThresholdDBManager(void){
  ;
}

void ThresholdDBManager::init(void){
  //  crateID=9999;
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<16;j++)
	{
	  thr_offset_trg[i][j]=15000;//was 0xffff before 2013 jan 18
	  thr_offset_scaler[i][j]=15000;

	  for(int k=0;k<20;k++)
	    {
	      rms_mean[k][i][j]=0;
	    }
	}
    }

  COEthreshold[0]=0;
  COEthreshold[1]=0;
}

void ThresholdDBManager::ReadThresholdFromTxt(char* InFileName)
{
  //  init();

  FILE *fp;
  fp = fopen( InFileName ,"rt");
  if( fp == NULL ){
    printf("ThresholdDB file %s is not found.\n", InFileName);
    return;
  }
  //  printf("thresholdDB file is open as %s.\n",InFileName);
  int AllNum;  
  fscanf(fp,"%d\n",&AllNum);  
  for(int i=0;i<AllNum;i++){
    //    fscanf(fp,"%d",&crateID);
    int module;
    int ch;
    fscanf(fp,"%d %d", &module, &ch );    
    fscanf(fp,"%d %d\n", &thr_offset_trg[module][ch], &thr_offset_scaler[module][ch]  );    
    //    printf("%d %f %f\n", detID, GainMean[detID], GainSigma[detID] );    
  }
  fclose( fp );
}


void ThresholdDBManager::ReadRMSFromTxt(char* InFileName)
{
  //  init();

  FILE *fp;
  fp = fopen( InFileName ,"rt");
  if( fp == NULL ){
    printf("ThresholdDB file %s is not found.\n", InFileName);
    return;
  }
  //  printf("thresholdDB file is open as %s.\n",InFileName);
  int AllNum;  
  int crateID;
  fscanf(fp,"%d\n",&AllNum);  
  for(int i=0;i<AllNum;i++){
    //fscanf(fp,"%d",&crateID);
    int module;
    int ch;
    fscanf(fp,"%d %d %d",&crateID, &module, &ch );    
    fscanf(fp,"%lf \n", &rms_mean[crateID][module][ch]  );    
    //    printf("%d %f %f\n", detID, GainMean[detID], GainSigma[detID] );    
  }
  fclose( fp );
}

void ThresholdDBManager::ReadPedMeanSigmaFromTxt(char* InFileName){

        fstream fp(InFileName);
        if(!fp) { printf("ThresholdDB file %s is not found.\n", InFileName); return; }
        int icrate, islot, ich;
        double imean, isigma;
        while( fp >> icrate >> islot >> ich >> imean >> isigma ) {
                ped_mean[icrate][islot][ich] = imean;
                ped_sigma[icrate][islot][ich] = isigma;
//              cout << icrate <<"\t" << islot << "\t" << ich <<"\t" << imean <<"\t" << isigma << endl;
        }
        fp.close();
}

void ThresholdDBManager::CalculatePedMeanSigma( const int runID, const int icrate ) {


//  TFile *fout = new TFile(Form("/DAQcodes/FADC/2016/yuting/2017/peddata_root/ped_%d_crate%d.root",runID,icrate),"RECREATE");
  TFile *fout = new TFile(Form("/raw_data/ped_data/crate%d/ped_run%d_crate%d.root",icrate,runID,icrate),"RECREATE");
  TTree *tr[22];

  std::ofstream ped_file(Form("/DAQcodes/ped_record/crate%d/ped_crate%d_run%d",icrate,icrate,runID));
  std::ofstream ped_file2(Form("/raw_data/ped_record/crate%d/ped_crate%d_run%d",icrate,icrate,runID));

  int NCHANNELS, NSAMPLE;
  if( icrate>-1 && icrate<15 ) { NCHANNELS = 16; NSAMPLE = 48; } //Crate 0~14: 125MHz Boards
  if( icrate>14 && icrate<18 )  { NCHANNELS = 4; NSAMPLE = 48*4; } //Crate 15~17: 500MHz Boards

  //Output Data File
  ofstream ofile;
  ofile.open( Form("/DAQcodes/FADC/2017/April_ps/peddata/PedMeanSigma_crate%d",icrate) , ios::out);
  for( int slotid = 0; slotid < 22; slotid++ ){
//  for( int slotid = 8; slotid < 16; slotid++ ){
    //Input Data File
    tr[slotid] = new TTree(Form("slot%d",slotid),"");
    tr[slotid]->Branch("NCHANNELS",&NCHANNELS,"NCHANNELS/I");
    tr[slotid]->Branch("NSAMPLE",&NSAMPLE,"NSAMPLE/I");
    tr[slotid]->Branch("pedestal",m_pedestal,"pedestal[16][192]/I");
    
    ifstream ifile;
    ifile.open( Form("/DAQcodes/FADC/2017/April_ps/peddata/PedData_Crate%i_slot%i", icrate, slotid), ios::in);
    if(!ifile) continue;
    TH1F *hdata[16];
    for( int i = 0; i < NCHANNELS; i++ ){
      hdata[i] = new TH1F(Form("h%i", i), "data hist", 2000, 0, 2000);
    }
    //Data Readin Location Indicator
    int ich = 0, data, isample = 0, data_max[16], data_min[16], pre_header = 0;
    int data_matrix[16][48*4] = {};
/*
    for( int ifadc = 0; ifadc < 20; ifadc++ ) {
        for( int ich = 0; ich < 16; ich++ ) {
                for( int isample = 0; isample < 48; isample++ ) {
                        m_pedestal[ifadc][ich][isample] = -1;
                }
        }

    }
*/
    int NEVENT = 0;
    while( ifile >> hex >> data ){

        int header = data >> 14; // C000
        if( pre_header != 2 && header == 2 ) { // begin of data
                ich = 0; isample = 0;
                for( int i = 0; i < NCHANNELS; i++ ) {
//                      for( int j = 0; j < 48; j++ ) {
//                              data_matrix[i][j] = 0;
//                      }
                        data_min[i] = 0xffff;
                        data_max[i] = -1;
                }
        }

        if( header == 2 ) { // data
                data = data & 0x3FFF;
                data_matrix[ich%NCHANNELS][isample] = data;
//                cout << slotid <<"\t"<<ich%NCHANNELS <<"\t" << isample <<"\t" << data << endl;
                m_pedestal[ich%NCHANNELS][isample] = data;
                if(ich%NCHANNELS==NCHANNELS-1) {
//                      cout << isample << "\t"<< data << endl;
                        isample++;

                }
                data_min[ich%NCHANNELS] = data < data_min[ich%NCHANNELS]? data:data_min[ich%NCHANNELS];
                data_max[ich%NCHANNELS] = data > data_max[ich%NCHANNELS]? data:data_max[ich%NCHANNELS];
                ich++;
        }

        if( pre_header == 2 && header != 2 ) { // end of data
                tr[slotid]->Fill();
                for( int i = 0; i < NCHANNELS; i++ ) {
//                        cout << data_max[i] - data_min[i] << endl;
//			if( (data_max[i] - data_min[i])<50 ) {
                        	for( int j = 0; j < isample; j++ ) {
                                	hdata[i]->Fill(data_matrix[i][j]);
                        	}
//			}
                }
        }
        pre_header = header;
    }
    ifile.close();

    cout<<"Slot"<<slotid<<" data input complete\n";

    double m=0;
    double s=0;

    //Gaussian Fitting Function
    TF1 *gaus;

    for(int ich=0;ich<NCHANNELS;ich++){

      if(hdata[ich]->Integral()==0) { continue; }
      double Xmax = hdata[ich]->GetBinCenter( hdata[ich]->GetMaximumBin() );
      hdata[ich]->SetAxisRange(Xmax-25.,Xmax+25.,"X");
      double fmin = Xmax-15., fmax = Xmax+5.;
//      if(m_DetName[icrate][ifadc][ich]=="CV") {
//	fmax = Xmax+15;	
  //    }
      hdata[ich]->Fit("gaus", "Q", "", fmin, fmax);
      gaus = (TF1*)hdata[ich]->GetFunction("gaus");

//      hdata[ich]->Draw();
//      cout << hdata[ich]->Integral() << endl;

//      gPad->Update();
//      getchar();

      //Fitting Results
      m = gaus->GetParameter(1);
      s = gaus->GetParameter(2);

///////////////////////////////////////////////////////////////////
/// Jay added for CsI crates to distinguish noisy channels, 170426
  
  if( icrate > -1 && icrate < 11 ){
      double x_right = m + 3*s;
      int    xbin_right = hdata[ich]->GetXaxis()->FindBin( x_right );

      double integral = hdata[ich]->Integral(1,xbin_right);

      bool isLowArea = ( integral< 1960 * 0.8 ) ? true : false;
      bool isLargeSigma = ( s > 10 ) ? true : false;

      if( isLowArea || isLargeSigma ){
          if(isLargeSigma) x_right = Xmax;

          do{
             x_right += 5;
             xbin_right = hdata[ich]->GetXaxis()->FindBin( x_right );
             integral = hdata[ich]->Integral(1,xbin_right);

             m = x_right;

           }while( integral < 1960 *0.95);

           s = 0.;

        } // Bad mod criteria
    } // CsI crate 

/////////////////////////////////////////////////////////////////

      cout<<"Fit result "<< icrate <<"\t"<<slotid<<"\tMEAN="<<m<<", SIGMA="<<s<<endl;

      //File Output
      ofile<<icrate<<"\t"<<slotid<<"\t"<<ich<<"\t"<<m<<"\t"<<s<<endl;
      ped_file << slotid<<"\t"<<ich<<"\t"<<m<<"\t"<<s<<endl;
      ped_file2 << slotid<<"\t"<<ich<<"\t"<<m<<"\t"<<s<<endl;
    }

    for( int i = 0; i < NCHANNELS; i++ ){
        delete hdata[i];
    }
//    delete tr[slotid];
  } // End of slotid Loop

  ofile.close();
  fout->Write();
  fout->Close();

  ped_file.close();
  ped_file2.close();
 
/*
  for( int slotid = 0; slotid < 22; slotid++ ){
        delete tr[slotid];
  }
  delete fout;
*/
//  return 0;

}

double ThresholdDBManager::GetPedMean(int crate,int slot,int ch)
{
        return ped_mean[crate][slot][ch];
}

double ThresholdDBManager::GetPedSigma(int crate,int slot,int ch)
{
        return ped_sigma[crate][slot][ch];
}

double ThresholdDBManager::GetRMS(int crate,int mod,int ch)
{
  return rms_mean[crate][mod][ch];
}


int ThresholdDBManager::GetThreshold_trg(int module,int ch)
{
  return thr_offset_trg[module][ch];

}

int ThresholdDBManager::GetThreshold_scaler(int module,int ch)
{
  return thr_offset_scaler[module][ch];
}

int ThresholdDBManager::GetMeVPerThreshold(char* InFileName)
{
  FILE *fp;
  fp = fopen( InFileName ,"rt");
  if( fp == NULL ){
    printf("Threshold file %s is not found.\n", InFileName);
    return 0;
  }
  int val;
  fscanf(fp,"%d\n",&val);
  /*  printf("%d",val);*/
  fclose( fp );
  return val;

}


double ThresholdDBManager::GetRMSmaskThreshold(char* InFileName)
{
  FILE *fp;
  fp = fopen( InFileName ,"rt");
  if( fp == NULL ){
    printf("Threshold file %s is not found.\n", InFileName);
    return 0;
  }
  double val;
  fscanf(fp,"%lf\n",&val);
  /*  printf("%d",val);*/
  fclose( fp );
  return val;

}

int* ThresholdDBManager::GetCOEdiscriThreshold(char* InFileName)
{
  FILE *fp;
  fp = fopen(InFileName ,"rt");
  if( fp == NULL ){
    printf("Threshold file %s is not found.\n", InFileName);
    return 0;
  }
  fscanf(fp,"%d\n",&COEthreshold[0]);
  fscanf(fp,"%d\n",&COEthreshold[1]);
  /*  printf("%d",val);*/
  fclose( fp );
  return COEthreshold;
}

class DelayDBManager{
 public:
  DelayDBManager();
  ~DelayDBManager(void);
  
  void ReadDelayFromTxt(char* filename);
  int GetDelay(int module,int ch);
 private:
  void init(void);
  int input_delay[20][16];
 
};

DelayDBManager::DelayDBManager(void)
  { init(); }

DelayDBManager::~DelayDBManager(void){
  ;
}

void DelayDBManager::init(void){
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<16;j++)
	{
	  input_delay[i][j]=0;
	}
    }
}

void DelayDBManager::ReadDelayFromTxt(char* InFileName)
{
  //  init();

  FILE *fp;
  fp = fopen( InFileName ,"rt");
  if( fp == NULL ){
    printf("DelayDB file %s is not found.\n", InFileName);
    return;
  }
  int AllNum;  
  fscanf(fp,"%d\n",&AllNum);  
  for(int i=0;i<AllNum;i++){
    int module;
    int ch;
    fscanf(fp,"%d %d", &module, &ch );    
    fscanf(fp,"%d\n", &input_delay[module][ch]  );    
  }
  fclose( fp );
}

int DelayDBManager::GetDelay(int module,int ch)
{
  return input_delay[module][ch];
}




class ModConfDBManager{
 public:
  ModConfDBManager();
  ~ModConfDBManager(void);
  
  void ReadModConfFromTxt(char* filename);
  int Check_UseHitInfo(int crate,int module);
  int Check_PrintScalerInfo(int crate,int module);
 private:
  void init(void);
  int use_HitInfo[20][20];
  int use_PrintScaler[20][20];
 
};

ModConfDBManager::ModConfDBManager(void)
  { init(); }

ModConfDBManager::~ModConfDBManager(void){
  ;
}

void ModConfDBManager::init(void){
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
	{
	  use_HitInfo[i][j]=0;
	  use_PrintScaler[i][j]=0;
	}
    }
}

void ModConfDBManager::ReadModConfFromTxt(char* InFileName)
{
  FILE *fp;
  fp = fopen( InFileName ,"rt");
  if( fp == NULL ){
    printf("ModuleConfig file %s is not found.\n", InFileName);
    return;
  }
  int AllNum;  
  fscanf(fp,"%d\n",&AllNum);  
  for(int i=0;i<AllNum;i++){
    int module;
    int crate;
    fscanf(fp,"%d %d", &crate, &module );    
    fscanf(fp,"%d %d\n", &use_HitInfo[crate][module], &use_PrintScaler[crate][module]  );    
  }
  fclose( fp );
}

int  ModConfDBManager::Check_UseHitInfo(int crate,int module)
{
  return  use_HitInfo[crate][module];
}
int  ModConfDBManager::Check_PrintScalerInfo(int crate,int module)
{
  return use_PrintScaler[crate][module];
}






/////XY position reader


class XYposDBManager{
 public:
  XYposDBManager();
  ~XYposDBManager(void);
  void ReadXYposFromTxt(char* filename);
  unsigned int GetXpos(int crate, int module, int channel);
  unsigned int GetYpos(int crate, int module, int channel);

 private:
  void init(void);
  unsigned int Xpos[20][20][16];
  unsigned int Ypos[20][20][16];
};

XYposDBManager::XYposDBManager(void)
  { init(); }

XYposDBManager::~XYposDBManager(void){
  ;
}

void XYposDBManager::init(void){
  for(int i=0;i<20;i++)
    {
      for(int j=0;j<20;j++)
	{
	  for(int k=0;k<16;k++)
	    {
	      Xpos[i][j][k]=0;
	      Ypos[i][j][k]=0;
	    }
	}
    }
}

void XYposDBManager::ReadXYposFromTxt(char* InFileName)
{
  FILE *fp;
  fp = fopen( InFileName ,"rt");
  if( fp == NULL ){
    printf("ModuleConfig file %s is not found.\n", InFileName);
    return;
  }
  int AllNum;  
  fscanf(fp,"%d\n",&AllNum);  
  for(int i=0;i<AllNum;i++){
    int crate;
    int module;
    int channel;

    fscanf(fp,"%d %d %d", &crate, &module, &channel );    
    fscanf(fp,"%d %d\n", &Xpos[crate][module][channel], &Ypos[crate][module][channel]  );    
  }
  fclose( fp );
}


unsigned int XYposDBManager::GetXpos(int crate,int module , int channel)
{
  return Xpos[crate][module][channel];
}
unsigned int XYposDBManager::GetYpos(int crate,int module , int channel)
{
  return Ypos[crate][module][channel];
}


