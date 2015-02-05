#include <TH2F.h>

void eff_zone_5() {

  TH2F* h = new TH2F("Piano_5","Efficienza a zone: piano 5",3,1,3,3,1,3);
  h->SetBinContent(1,1,0.6121);
  h->SetBinContent(2,1,0.6620);
  h->SetBinContent(3,1,0.7621);
  h->SetBinContent(1,2,0.4255);
  h->SetBinContent(2,2,0.4701);
  h->SetBinContent(3,2,0.6124);
  h->SetBinContent(1,3,0.5743);
  h->SetBinContent(2,3,0.6176);
  h->SetBinContent(3,3,0.7229);
  h->SetEntries(1);
  h->GetXaxis()->SetLabelSize(0);
  h->GetXaxis()->SetNdivisions(0);
  h->GetYaxis()->SetLabelSize(0);
  h->GetYaxis()->SetNdivisions(0);
  h->Draw("COLZ");
}
