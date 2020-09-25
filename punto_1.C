//Plot the number of average interactions per bunch-crossing (mu_average).

void punto_1(){

  // Let's open the TFile
  TFile *file = TFile::Open("Tracks_Clusters.root");
  TTree *tree = (TTree*) file->Get("JetRecoTree");
  tree->Print();
  // Declare variables
  Float_t mu_ave = -1;
  tree->SetBranchAddress("mu_average", &mu_ave);
  // Make a canva with 800x600
  TCanvas *canvas = new TCanvas("Canvas","Plot 1",800,600);
  // Make a 1D histogram
  TH1F *hist_mu_ave = new TH1F("#mu_{average}","Plot 1: Number of average interactions per bunch-crossing; #mu_{average}; Events ",100,0,100);
  // Loop
  int nentries, nbytes, i;
  nentries = (Int_t)tree->GetEntries();

  for (i = 0; i < nentries; i++)
    {
      nbytes = tree->GetEntry(i);
      hist_mu_ave->Fill(mu_ave);
    }

  std::cout << "Done!" << std::endl;
  
  // Choose the kind of plot you want
  
  hist_mu_ave->SetFillColor(9); hist_mu_ave->Draw();
  
  //Float_t scale = hist_mu_ave->Integral(); hist_mu_ave->Scale(1/scale); hist_mu_ave->SetFillColor(4); hist_mu_ave->DrawNormalized();

  // Plot and save
  canvas->Draw();
  canvas->Print("mu_ave.pdf");

}
