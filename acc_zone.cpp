#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <TH1F.h>
#include <TFile.h>
#include <TRandom3.h>
#include <TH2F.h>
#include <cell.h>

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
int nexp = 100; //numero pseudoesperimenti
//double stheta;
//double sphi;

using namespace std;

void acc_zone(){

	TRandom3 rndgen;

  //efficienze
    float eps1 [3][3] = {{0.7498,0.729,0.725},{0.746,0.713,0.7336},{0.7833,0.7471,0.7786}};
    float eps2 [3][3] = {{0.6204,0.5303,0.5673},{0.6307,0.5626,0.6080},{0.7440,0.6701,0.7241}};
    float eps3 [3][3] = {{0.5743,0.4255,0.6121},{0.6176,0.4701,0.6620},{0.7229,0.6124,0.7621}};
    double  rxmax, rymax, rD12, rD23, reps1[3][3], reps2[3][3], reps3[3][3];
    int cx1, cx2, cx3, cy1, cy2, cy3;
  float s_eps1 = 0.003;
  float s_eps2 = 0.003;
  float s_eps3 = 0.003;
  double theta, W1,W2,W3, phi,x1,x2,x3,y1,y2,y3;
  int j = 0;
  
 TH1F* hacc = new TH1F("a","Distribuzione accettanza; a; # esperimenti", 100, 0.2, 0.3);
 TH1F* haccA = new TH1F("aA","Distribuzione accettanza; aA (cm^2); # esperimenti", 100, 400, 600);

 TFile rfile("accettanza_zone.root","RECREATE");

  for (int a = 1; a <= nexp; a++) { 
    cout << "Experiment n. " << a << ": " << endl;
      rxmax = xmax + rndgen.Uniform(2*s_xmax)-s_xmax;
      rymax = ymax + rndgen.Uniform(2*s_ymax)-s_ymax;
      rD12 = D12 + rndgen.Uniform(2*s_D12)-s_D12;
      rD23 = D23 + rndgen.Uniform(2*s_D23)-s_D23;
      for (int m = 0; m < 3; m++) {
	for (int n = 0; n < 3; n++) {
	  reps1[m][n] = rndgen.Gaus(eps1[m][n],s_eps1); //inserire distribuzione corretta
	  reps2[m][n] = rndgen.Gaus(eps2[m][n],s_eps2);
	  reps3[m][n] = rndgen.Gaus(eps3[m][n],s_eps3);
	}
      }
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

	cx1 = cell(x1,rxmax);
	cx2 = cell(x2,rxmax);
	cx3 = cell(x3,rxmax);
	cy1 = cell(y1,rymax);
	cy2 = cell(y2,rymax);
	cy3 = cell(y3,rymax);

	if ((pow(x1,2) <= pow(rxmax,2)/4) && (pow(y1,2) <= pow(rymax,2)/4) && (pow(x3,2) <= pow(rxmax,2)/4) && (pow(y3,2) <= pow(rymax,2)/4) && W1 < reps1[cx1][cy1] && W2 < reps2[cx2][cy2] && W3 < reps3[cx3][cy3]){
	  
	  j+=1;}
      }
    }

    cout << "Generati: " << imax << endl;
    cout << "Accettati: " << j << endl;
    cout << "Accettanza: " << double(j)/double(imax) << endl;
hacc->Fill(double(j)/double(imax));   
haccA->Fill(double(j)/double(imax)*rxmax*rymax); //le moltiplico anche per l'area perché nel flusso accettanza e area compaiono insieme
    j = 0;
  }
  cout << "Accettanza media: " << hacc->GetMean()*xmax*ymax << endl;
  hacc->Write();
  haccA->Write();
}

void acc_media(){

	TRandom3 rndgen;

  //efficienze
  //  float eps1 [3][3] = {{0.612,0.662,0.762},{0.425,0.470,0.612},{0.574,0.618,0.722}};
	double  rxmax, rymax, rD12, rD23, reps1, reps2, reps3; 
  float eps1 = 0.745;
  float s_eps1 = 0.003;
  float eps2 = 0.5658;
  float s_eps2 = 0.003;
  float eps3 = 0.6066;
  float s_eps3 = 0.003;
  double theta, W1,W2,W3, phi,x1,x2,x3,y1,y2,y3;
  int j = 0;
  
 TH1F* hacc = new TH1F("a","Distribuzione accettanza; a; # esperimenti", 100, 0.2, 0.3);
 TH1F* haccA = new TH1F("aA","Distribuzione accettanza; aA (cm^2); # esperimenti", 100, 400, 600);

 TFile rfile("accettanza_media.root","RECREATE");

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
hacc->Fill(double(j)/double(imax));   
haccA->Fill(double(j)/double(imax)*rxmax*rymax); //le moltiplico anche per l'area perché nel flusso accettanza e area compaiono insieme
    j = 0;
  }
  cout << "Accettanza media: " << hacc->GetMean()*xmax*ymax << endl;
  hacc->Write();
  haccA->Write();
}
