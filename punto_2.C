// Make a 2D histogram of NPV vs. mu

void punto_2(){

  // Let's open the TFile
  TFile *file = TFile::Open("Tracks_Clusters.root");
  TTree *tree = (TTree*) file->Get("JetRecoTree");
  tree->Print();
  // Declare variables
  UInt_t npv = -1;
  tree->SetBranchAddress("NPV", &npv);
  Float_t mu = -1;
  tree->SetBranchAddress("mu_average", &mu);
  // Make some canvas 800x600
  TCanvas *canvas = new TCanvas("Canvas","Plot 2",800,600);
  // Make a 2D histogram
  TH2F *hist_npvmu = new TH2F("#mu_{ave}-NPV","Plot 2: 2D Histogram Numbers of events vs. #mu_{average} and NPV; NPV ; #mu_{average}; Events ",50,1,50,50,1,100);
  
  int nentries, nbytes, i;
  nentries = (Int_t)tree->GetEntries();

  for (i = 0; i < nentries; i++)
    {
      nbytes = tree->GetEntry(i);
      hist_npvmu->Fill(npv,mu);

    }

  std::cout << "Done!" << std::endl;

  // Let's plot
  hist_npvmu->Draw("Colz");
  canvas->Draw();
  canvas->Print("2dhisto_npvmu.pdf");
  

}
