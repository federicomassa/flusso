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
double ymax = 48.5; //cm
double D12 = 10.2;// cm
double D23 = 10.2; //cm
int imax = 20000000;
//double stheta;
//double sphi;

using namespace std;

void acc(){

	TRandom3 rndgen;

  //efficienze
  //  float eps1 [3][3] = {{0.612,0.662,0.762},{0.425,0.470,0.612},{0.574,0.618,0.722}};
  float eps1 = 0.8;
  float eps2 = 0.8;
  float eps3 = 0.8;
  double theta, W1,W2,W3, phi,x1,x2,x3,y1,y2,y3;
  int j = 0;


  for (int i = 1; i <= imax;) {
    theta = rndgen.Uniform(2*atan(1.)); 
    W1 = rndgen.Uniform(1);
    if (sin(theta)*pow(cos(theta),2) > W1) { // distribuzione: cos^2(theta) dcos(theta)
      i+=1;
      if (i%int(double(imax)/40) == 0) cout << double(i)/double(imax)*100 << "%" << endl;
      phi = rndgen.Uniform(8*atan(1.));
      x2 = (rndgen.Uniform(xmax)-xmax/2.);
      y2 = (rndgen.Uniform(ymax)-ymax/2.);
      x1 = tan(theta)*cos(phi)*D12 + x2;
      y1 = tan(theta)*sin(phi)*D12 + y2;
      x3 = -tan(theta)*cos(phi)*D23+x2;
      y3 = -tan(theta)*sin(phi)*D23 + y2;
      W1 = rndgen.Uniform(1);
      W2 = rndgen.Uniform(1);
      W3 = rndgen.Uniform(1);
      
      if ((pow(x1,2) <= pow(xmax,2)/4) && (pow(y1,2) <= pow(ymax,2)/4) && (pow(x3,2) <= pow(xmax,2)/4) && (pow(y3,2) <= pow(ymax,2)/4) && W1 < eps1 && W2 < eps2 && W3 < eps3){
	  
	j+=1;}
    }
  }

  cout << "Generati: " << imax << endl;
  cout << "Accettati: " << j << endl;
  cout << "Accettanza: " << double(j)/double(imax) << endl;
  }
