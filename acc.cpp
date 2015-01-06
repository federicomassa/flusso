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
double s_xmax = 1; //risoluzione
double ymax = 48.5; //cm
double s_ymax = 1; //risoluzione
double D12 = 10.2;// cm
double s_D12 = 1; //risoluzione
double D23 = 10.2; //cm
double s_D23 = 1; //risoluzione
int imax = 100000;
int nexp = 20000; //numero pseudoesperimenti
//double stheta;
//double sphi;

using namespace std;

void acc(){

	TRandom3 rndgen;

  //efficienze
  //  float eps1 [3][3] = {{0.612,0.662,0.762},{0.425,0.470,0.612},{0.574,0.618,0.722}};
	double  rxmax, rymax, rD12, rD23, reps1, reps2, reps3; 
  float eps1 = 0.85;
  float s_eps1 = 0.003;
  float eps2 = 0.65;
  float s_eps2 = 0.003;
  float eps3 = 0.81;
  float s_eps3 = 0.003;
  double theta, W1,W2,W3, phi,x1,x2,x3,y1,y2,y3;
  int j = 0;
  
 TH1F* hacc = new TH1F("dis_acc","Distribuzione accettanza; aA (cm^2); # esperimenti", 100, 400, 600);
 TFile rfile("accettanza.root","RECREATE");

  for (int a = 1; a <= nexp; a++) { 
    cout << "Experiment n. " << a << ": " << endl;
      rxmax = xmax + rndgen.Uniform(2*s_xmax)-s_xmax;
      rymax = ymax + rndgen.Uniform(2*s_ymax)-s_ymax;
      rD12 = D12 + rndgen.Uniform(2*s_D12)-s_D12;
      rD23 = D23 + rndgen.Uniform(2*s_D23)-s_D23;
      reps1 = rndgen.Gaus(eps1,s_eps1); //inserire distribuzione corretta
      reps2 = rndgen.Gaus(eps2,s_eps2);
      reps3 = rndgen.Gaus(eps3,s_eps3);
    for (int i = 1; i <= imax;) {
            
      theta = rndgen.Uniform(2*atan(1.)); 
      W1 = rndgen.Uniform(1);
      if (sin(theta)*pow(cos(theta),2) > W1) { // distribuzione: cos^2(theta) dcos(theta)
	i+=1;
	//	if (i%int(double(imax)/10) == 0) cout << double(i)/double(imax)*100 << "%" << endl;
	phi = rndgen.Uniform(8*atan(1.));
	x2 = (rndgen.Uniform(rxmax)-rxmax/2.);
	y2 = (rndgen.Uniform(rymax)-rymax/2.);
	x1 = tan(theta)*cos(phi)*rD12 + x2;
	y1 = tan(theta)*sin(phi)*rD12 + y2;
	x3 = -tan(theta)*cos(phi)*rD23+x2;
	y3 = -tan(theta)*sin(phi)*rD23 + y2;
	W1 = rndgen.Uniform(1);
	W2 = rndgen.Uniform(1);
	W3 = rndgen.Uniform(1);
      
	if ((pow(x1,2) <= pow(rxmax,2)/4) && (pow(y1,2) <= pow(rymax,2)/4) && (pow(x3,2) <= pow(rxmax,2)/4) && (pow(y3,2) <= pow(rymax,2)/4) && W1 < reps1 && W2 < reps2 && W3 < reps3){
	  
	  j+=1;}
      }
    }

    cout << "Generati: " << imax << endl;
    cout << "Accettati: " << j << endl;
    cout << "Accettanza: " << double(j)/double(imax) << endl;
    hacc->Fill(double(j)/double(imax)*rxmax*rymax); //le moltiplico anche per l'area perché nel flusso accettanza e area compaiono insieme
    j = 0;
  }
  cout << "Accettanza media: " << hacc->GetMean()*xmax*ymax << endl;
  hacc->Write();
}
