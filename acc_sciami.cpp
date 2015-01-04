#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <TH1F.h>
#include <TFile.h>
#include <TRandom3.h>
#include <TH2F.h>

//lati lunghi = 48.5 cm, lati corti = 40 cm, spessore = 1.2 cm, distanze relative 10,2 cm (scintillatori per flusso raggi cosmici)
double xmax = 40; //cm
double s_xmax = 0.5; //risoluzione
double ymax = 48.5; //cm
double s_ymax = 0.5; //risoluzione
double D13 = 10.2*2;// cm
double s_D13 = 0.5; //risoluzione
int imax = 100000;
int nexp = 1000; //numero pseudoesperimenti
//double stheta;
//double sphi;

using namespace std;

void acc_sciami(){

	TRandom3 rndgen;

  //efficienze
  //  float eps1 [3][3] = {{0.612,0.662,0.762},{0.425,0.470,0.612},{0.574,0.618,0.722}};
	double  rxmax, rymax, rD13, reps1, reps_ext, reps3; 
  float eps1 = 0.8;
  float s_eps1 = 0.02;
  float eps_ext = 0.8;
  float s_eps_ext = 0.02;
  float eps3 = 0.8;
  float s_eps3 = 0.02;
  double theta, W1,W2,W3, phi,x1,x2,x3,y1,y2,y3;
  int j = 0;
  
 TH1F* hacc = new TH1F("dis_acc","Distribuzione accettanza sciami", 100, 0.22, 0.32);
 TFile rfile("accettanza_sciami.root","RECREATE");

  for (int a = 1; a <= nexp; a++) { 
    cout << "Experiment n. " << a << ": " << endl;
      rxmax = xmax + rndgen.Uniform(2*s_xmax)-s_xmax;
      rymax = ymax + rndgen.Uniform(2*s_ymax)-s_ymax;
      rD13 = D13 + rndgen.Uniform(2*s_D13)-s_D13;
      reps1 = rndgen.Gaus(eps1,1/3*s_eps1); //inserire distribuzione corretta
      reps_ext = rndgen.Gaus(eps_ext,1/3*s_eps_ext);
      reps3 = rndgen.Gaus(eps3,1/3*s_eps3);
    for (int i = 1; i <= imax;) {
            
      theta = rndgen.Uniform(2*atan(1.)); 
      W1 = rndgen.Uniform(1);
      if (sin(theta)*pow(cos(theta),2) > W1) { // distribuzione: cos^2(theta) dcos(theta)
	i+=1;
	//	if (i%int(double(imax)/10) == 0) cout << double(i)/double(imax)*100 << "%" << endl;
	phi = rndgen.Uniform(8*atan(1.));
	x1 = (rndgen.Uniform(rxmax)-rxmax/2.);
	y1 = (rndgen.Uniform(rymax)-rymax/2.);
	x3 = -tan(theta)*cos(phi)*rD13+x1;
	y3 = -tan(theta)*sin(phi)*rD13 + y1;
	W1 = rndgen.Uniform(1);
	W2 = rndgen.Uniform(1);
	W3 = rndgen.Uniform(1);
      
	if ((pow(x3,2) <= pow(rxmax,2)/4) && (pow(y3,2) <= pow(rymax,2)/4) && W1 < reps1 && W2 < reps3 && W3 < reps_ext){
	  
	  j+=1;}
      }
    }

    cout << "Generati: " << imax << endl;
    cout << "Accettati: " << j << endl;
    cout << "Accettanza: " << double(j)/double(imax) << endl;
    hacc->Fill(double(j)/double(imax));
    j = 0;
  }
  hacc->Write();
}
