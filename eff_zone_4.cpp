#include <TH2F.h>

void eff_zone_4() {

  TH2F* h = new TH2F("Piano_4","Efficienza a zone: piano 4",3,1,3,3,1,3);
  h->SetBinContent(1,1,0.6204);
  h->SetBinContent(2,1,0.6307);
  h->SetBinContent(3,1,0.7440);
  h->SetBinContent(1,2,0.5303);
  h->SetBinContent(2,2,0.5626);
  h->SetBinContent(3,2,0.6701);
  h->SetBinContent(1,3,0.5673);
  h->SetBinContent(2,3,0.6080);
  h->SetBinContent(3,3,0.7241);
  h->SetEntries(1);
  h->GetXaxis()->SetLabelSize(0);
  h->GetXaxis()->SetNdivisions(0);
  h->GetYaxis()->SetLabelSize(0);
  h->GetYaxis()->SetNdivisions(0);
  h->Draw("COLZ");
}
