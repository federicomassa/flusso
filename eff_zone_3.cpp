#include <TH2F.h>

void eff_zone_3() {

  TH2F* h = new TH2F("Piano_3","Efficienza a zone: piano 3",3,1,3,3,1,3);
  h->SetBinContent(1,1,0.7498);
  h->SetBinContent(2,1,0.7460);
  h->SetBinContent(3,1,0.7833);
  h->SetBinContent(1,2,0.7290);
  h->SetBinContent(2,2,0.7130);
  h->SetBinContent(3,2,0.7471);
  h->SetBinContent(1,3,0.7250);
  h->SetBinContent(2,3,0.7336);
  h->SetBinContent(3,3,0.7786);
  h->SetEntries(1);
  h->GetXaxis()->SetLabelSize(0);
  h->GetXaxis()->SetNdivisions(0);
  h->GetYaxis()->SetLabelSize(0);
  h->GetYaxis()->SetNdivisions(0);
  h->Draw("COLZ");
}
