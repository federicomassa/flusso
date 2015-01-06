#include "TROOT.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TMath.h"
#include "TStyle.h"
#include <iostream>

void plateau_graph(){

  TCanvas *c= new TCanvas("c","c",396,700);
  c->Divide(1,3);

  TGraphErrors piano2("./pl_piano2.dat","%lg %lg %lg");
  piano2.SetTitle("Curva di alimentazione - PIANO 2; Tension [V]; counts");
  piano2.SetLineColor(2);
  c->cd(1); c->cd(1)->SetGrid(); piano2.DrawClone("APE");

  TGraphErrors piano3("./pl_piano3.dat","%lg %lg %lg");
  piano3.SetTitle("Curva di alimentazione - PIANO 3; Tension [V]; counts");
  piano3.SetLineColor(2);
  c->cd(2); c->cd(2)->SetGrid(); piano3.DrawClone("APE");


  TGraphErrors piano4("./pl_piano4.dat","%lg %lg %lg");
  piano4.SetTitle("Curva di alimentazione - PIANO 4; Tension [V]; counts");
  piano4.SetLineColor(2);
  c->cd(3); c->cd(3)->SetGrid(); piano4.DrawClone("APE");

  
TCanvas *c2= new TCanvas("c2","c2",396,700);
  c2->Divide(1,3);

  TGraphErrors piano5("./pl_piano5.dat","%lg %lg %lg");
  piano5.SetTitle("Curva di alimentazione - PIANO 5; Tension [V]; counts");
  piano5.SetLineColor(2);
  c2->cd(1); c2->cd(1)->SetGrid(); piano5.DrawClone("APE");

  TGraphErrors piano6("./pl_piano6.dat","%lg %lg %lg");
  piano6.SetTitle("Curva di alimentazione - PIANO 6; Tension [V]; counts");
  piano6.SetLineColor(2);
  c2->cd(2); c2->cd(2)->SetGrid();  piano6.DrawClone("APE");



  TGraphErrors piano7("./pl_piano7.dat","%lg %lg %lg");
  piano7.SetTitle("Curva di alimentazione - PIANO 7; Tension [V]; counts");
  piano7.SetLineColor(2);
  c2->cd(3); c2->cd(3)->SetGrid();  piano7.DrawClone("APE");

TCanvas *c3= new TCanvas("c3","c3",396,700);
  c3-> Divide(1,3);
  TGraphErrors piano8("./pl_piano8.dat","%lg %lg %lg");
  piano8.SetTitle("Curva di alimentazione - PIANO 8; Tension [V]; counts");
  piano8.SetLineColor(2);
  c3->cd(1); c3->cd(1)->SetGrid(); piano8.DrawClone("APE");

  TGraphErrors piano9("./pl_piano9.dat","%lg %lg %lg");
  piano9.SetTitle("Curva di alimentazione - PIANO 9; Tension [V]; counts");
  piano9.SetLineColor(2);
  c3->cd(2); c3->cd(2)->SetGrid(); piano9.DrawClone("APE");

  TGraphErrors piano10("./pl_piano10.dat","%lg %lg %lg");
  piano10.SetTitle("Curva di alimentazione - PIANO 10; Tension [V]; counts");
  piano10.SetLineColor(2);
  c3->cd(3); c3->cd(3)->SetGrid(); piano10.DrawClone("APE");

}
