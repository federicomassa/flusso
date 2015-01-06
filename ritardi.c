#include "TROOT.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TMath.h"
#include "TStyle.h"
#include "TPad.h"
#include <iostream>

void ritardi(){

  TCanvas *c = new TCanvas("canvas","Prova Canvas",1200,1200);
  c->Divide(3,2);
  
  TGraphErrors piano1("./rit12.dat","%lg %lg %lg");
  piano1.SetTitle("Curva di cavo - PIANO 1/2 ; Ritardo [ns]; Coincidenze");
  piano1.SetLineColor(kRed);
  c->cd(1); piano1.DrawClone("APE"); c->cd(1)->SetGrid();

  TGraphErrors piano2("./rit23.dat","%lg %lg %lg");
  piano2.SetTitle("Curva di cavo - PIANO 2/3; Ritardo [ns]; Coincidenze");
  piano2.SetLineColor(2);
  c->cd(2); piano2.DrawClone("APE"); c->cd(2)->SetGrid();

  TGraphErrors piano3("./rit34.dat","%lg %lg %lg");
  piano3.SetTitle("Curva di cavo - PIANO 3/4 ; Ritardo [ns]; Coincidenze");
  piano3.SetLineColor(kRed);
  c->cd(3); piano3.DrawClone("APE"); c->cd(3)->SetGrid();

  TGraphErrors piano4("./rit45.dat","%lg %lg %lg");
  piano4.SetTitle("Curva di cavo - PIANO 4/5 ; Ritardo [ns]; Coincidenze");
  piano4.SetLineColor(kRed);
  c->cd(4); piano4.DrawClone("APE"); c->cd(4)->SetGrid();

  TGraphErrors piano5("./rit56.dat","%lg %lg %lg");
  piano5.SetTitle("Curva di cavo - PIANO 5/6 ; Ritardo [ns]; Coincidenze");
  piano5.SetLineColor(kRed);
  c->cd(5); piano5.DrawClone("APE"); c->cd(5)->SetGrid();

  TGraphErrors piano6("./rit67.dat","%lg %lg %lg");
  piano6.SetTitle("Curva di cavo - PIANO 6/7 ; Ritardo [ns]; Coincidenze");
  piano6.SetLineColor(kRed);
  c->cd(6); piano6.DrawClone("APE"); c->cd(6)->SetGrid();

TCanvas *c2 = new TCanvas("canvascity","Canvas City",1800,400);
  c2->Divide(3,1);

  TGraphErrors rit89("./rit89.dat","%lg %lg %lg");
  rit89.SetTitle("Curva di cavo - PIANO 8/9 ; Ritardo [ns]; Coincidenze");
  rit89.SetLineColor(kRed);
  c2->cd(1); rit89.DrawClone("APE"); c2->cd(1)->SetGrid();

  TGraphErrors rit910("./rit910.dat","%lg %lg %lg");
  rit910.SetTitle("Curva di cavo - PIANO 9/10 ; Ritardo [ns]; Coincidenze");
  rit910.SetLineColor(kRed);
  c2->cd(2); rit910.DrawClone("APE"); c2->cd(2)->SetGrid();

  TGraphErrors rit59("./rit59.dat","%lg %lg %lg");
  rit59.SetTitle("Curva di cavo - PIANO 5/9 ; Ritardo [ns]; Coincidenze");
  rit59.SetLineColor(kRed);
  c2->cd(3); rit59.DrawClone("APE"); c2->cd(3)->SetGrid();


}
