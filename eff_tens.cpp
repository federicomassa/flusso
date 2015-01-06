#include <TGraphErrors.h>
#include <TCanvas.h>

void eff_tens() {
  TCanvas* c = new TCanvas();
  TGraphErrors* g = new TGraphErrors("./eff_tens.dat", "%lg %lg %lg");
  g->SetLineColor(kRed);
  g->SetMarkerStyle(8);
  g->SetMarkerSize(1);
  g->SetMarkerColor(kRed);
  g->SetTitle("Efficienza;Tensione (V);Efficienza");
  c->SetGrid();
  
  g->DrawClone("APE");
}
