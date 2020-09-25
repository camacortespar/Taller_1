//Make a 2D histogram of NPV and mu vs. nTracks and nClusters: NPV vs. nTrack, NPV vs. nClusters, mu vs. nTrack, mu vs. NClusters

void punto_3(){

  // Let's open the TFile
  TFile *file = TFile::Open("Tracks_Clusters.root");
  TTree *tree = (TTree*) file->Get("JetRecoTree");
  tree->Print();
  // Declare variables
  UInt_t npv = -1;
  Float_t mu_ave=0;
  vector<float> *tracks_pt=0;
  vector<float> *clusters_pt=0;
  tree->SetBranchAddress("mu_average", &mu_ave);
  tree->SetBranchAddress("NPV", &npv);
  tree->SetBranchAddress("Tracks_pt", &tracks_pt);
  tree->SetBranchAddress("Clusters_pt", &clusters_pt);
  // Make a canva 800x600
  TCanvas *canvas = new TCanvas("Canvas","Punto 3",800,600);
  // Make some 2D histograms
  TH2F *hist_npvtracks = new TH2F("NPV-NTracks","Plot 3.1: Number of events vs. NPV and NTracks; NPV ; NTracks; Events ",50,0,50,50,0,1800);
  TH2F *hist_npvclusters = new TH2F("NPV-NCluster", "Plot 3.2: Number of events vs. NPV and NClusters ; NPV; NClusters; Events",50,0,50,50,0,1800);
  TH2F *hist_mutracks = new TH2F("#mu_{ave}-NTracks", "Plot 3.3: Number of events vs. #mu_{average} and NTracks; #mu_{average}; NTracks; Events",50,0,100,50,0,1800);
  TH2F *hist_muclusters = new TH2F("#mu_{ave}-NClusters", "Plot 3.4: Number of events vs. #mu_{average} and NClusters; #mu_{average}; NClusters; Events",50,0,100,50,0,1800);
  
  int nentries, nbytes, i;
  nentries = (Int_t)tree->GetEntries();

  for (i = 0; i < nentries; i++)
    {
      nbytes = tree->GetEntry(i);
      hist_npvtracks->Fill(npv, tracks_pt->size());
      hist_npvclusters->Fill(npv, clusters_pt->size());
      hist_mutracks->Fill(mu_ave, tracks_pt->size());
      hist_muclusters->Fill(mu_ave, clusters_pt->size());

    }

  std::cout << "Done!" << std::endl;

  // Choose a 2d histogram
  
  //hist_npvtracks->Draw("Colz");
  //hist_npvclusters->Draw("Colz");
  //hist_mutracks->Draw("Colz");
  hist_muclusters->Draw("Colz");

  // Let's plot and save
  canvas->Draw();
  canvas->Print("2dhisto_muclusters.pdf");

}
