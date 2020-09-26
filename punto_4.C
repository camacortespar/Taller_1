// Plot all track, cluster and particle variables.

void punto_4(){

  // Let's open the TFile
  TFile *file = TFile::Open("Tracks_Clusters.root");
  TTree *tree = (TTree*) file->Get("JetRecoTree");
  tree->Print();
  // Declare variables

  //Tracks
  vector<float> *tracks_pt=0;
  vector<float> *tracks_eta=0;
  vector<float> *tracks_phi=0;
  vector<float> *tracks_m=0;
  vector<int> *tracks_vtx=0;
  tree->SetBranchAddress("Tracks_pt", &tracks_pt);
  tree->SetBranchAddress("Tracks_eta", &tracks_eta);
  tree->SetBranchAddress("Tracks_phi", &tracks_phi);
  tree->SetBranchAddress("Tracks_m", &tracks_m);
  tree->SetBranchAddress("Tracks_vtx", &tracks_vtx);
  
  //Clusters
  vector<float> *clusters_pt=0;
  vector<float> *clusters_eta=0;
  vector<float> *clusters_phi=0;
  vector<float> *clusters_m=0;
  tree->SetBranchAddress("Clusters_pt", &clusters_pt);
  tree->SetBranchAddress("Clusters_eta", &clusters_eta);
  tree->SetBranchAddress("Clusters_phi", &clusters_phi);
  tree->SetBranchAddress("Clusters_m", &clusters_m);
  
  //Particles
  vector<float> *particles_pt=0;
  vector<float> *particles_eta=0;
  vector<float> *particles_phi=0;
  vector<float> *particles_m=0;
  vector<int> *particles_pdg=0;
  tree->SetBranchAddress("Particles_pt", &particles_pt);
  tree->SetBranchAddress("Particles_eta", &particles_eta);
  tree->SetBranchAddress("Particles_phi", &particles_phi);
  tree->SetBranchAddress("Particles_m", &particles_m);
  tree->SetBranchAddress("Particles_pdgID", &particles_pdg);
  
  // Make a canvas 800x600
  TCanvas *c1 = new TCanvas("Canvas1","Plot 4: Track, clusters and particle variables",800,600);
  
  // Make some 1D histograms

  //Tracks
  TH1F *hist_track_pT = new TH1F("Track p_{T}","Plot 4: Track p_{T}; p_{T} (MeV) ; Events ",100,0,2500);
  TH1F *hist_track_eta = new TH1F("Track #eta","Plot 4: Track #eta; #eta ; Events ",50,-6,6);
  TH1F *hist_track_phi = new TH1F("Track #phi","Plot 4: Track #phi; #phi  ; Events ",50,-6,-6);
  TH1F *hist_track_m = new TH1F("Track m","Plot 4: Track m; m (MeV) ; Events ",100,-2000,2000);
  TH1F *hist_track_vtx = new TH1F("Track vtx","Plot 4: Track vtx; vtx  ; Events ",100,-10,50);

  //Clusters
  TH1F *hist_clust_pT = new TH1F("Cluster p_{T}","Plot 4: Cluster p_{T}; p_{T} (MeV) ; Events ",100,0,2500);
  TH1F *hist_clust_eta = new TH1F("Cluster #eta","Plot 4: Cluster #eta; #eta  ; Events ",50,-6,6);
  TH1F *hist_clust_phi = new TH1F("Cluster #phi","Plot 4: Cluster #phi; #phi  ; Events ",50,-6,-6);
  TH1F *hist_clust_m = new TH1F("Cluster m","Plot 4: Cluster m; m (MeV) ; Events ",100,-2000,2000);
  
  //Particles
  TH1F *hist_part_pT = new TH1F("Particle p_{T}","Plot 4: Particle p_{T}; p_{T} (MeV) ; Events ",100,0,2500);
  TH1F *hist_part_eta = new TH1F("Particle #eta","Plot 4: Particle #eta; #eta  ; Events ",50,-6,6);
  TH1F *hist_part_phi = new TH1F("Particle #phi","Plot 4: Particle #phi; #phi  ; Events ",50,-6,-6);
  TH1F *hist_part_m = new TH1F("Particle m","Plot 4: Particle m; m (MeV) ; Events ",100,-100,2000);
  TH1F *hist_part_pdg = new TH1F("Particle pdgID","Plot 4: Particle pdgID; pdgID  ; Events ",100,-3500,3500);
  
  int nentries, nbytes, i;
  nentries = (Int_t)tree->GetEntries();

  // Here come the loops
  for (i = 0; i < nentries; i++)
    {
      nbytes = tree->GetEntry(i);
      //Tracks
      for(int tr=0; tr<tracks_pt->size(); tr++)
	{
	  hist_track_pT->Fill(tracks_pt->at(tr));
	}
      for(int tr=0; tr<tracks_eta->size(); tr++)
	{
	  hist_track_eta->Fill(tracks_eta->at(tr));
	}
      for(int tr=0; tr<tracks_phi->size(); tr++)
	{
	  hist_track_phi->Fill(tracks_phi->at(tr));
	}
      for(int tr=0; tr<tracks_m->size(); tr++)
	{
	  hist_track_m->Fill(tracks_m->at(tr));
	}
      for(int tr=0; tr<tracks_vtx->size(); tr++)
	{
	  hist_track_vtx->Fill(tracks_vtx->at(tr));
	}

      //Clusters
      for(int tr=0; tr<clusters_pt->size(); tr++)
	{
	  hist_clust_pT->Fill(clusters_pt->at(tr));
	}
      for(int tr=0; tr<clusters_eta->size(); tr++)
	{
	  hist_clust_eta->Fill(clusters_eta->at(tr));
	}
      for(int tr=0; tr<clusters_phi->size(); tr++)
	{
	  hist_clust_phi->Fill(clusters_phi->at(tr));
	}
      for(int tr=0; tr<clusters_m->size(); tr++)
	{
	  hist_clust_m->Fill(clusters_m->at(tr));
	}

      //Particles
      for(int tr=0; tr<particles_pt->size(); tr++)
	{
	  hist_part_pT->Fill(particles_pt->at(tr));
	}
      for(int tr=0; tr<particles_eta->size(); tr++)
	{
	  hist_part_eta->Fill(particles_eta->at(tr));
	}
      for(int tr=0; tr<particles_phi->size(); tr++)
	{
	  hist_part_phi->Fill(particles_phi->at(tr));
	}
      for(int tr=0; tr<particles_m->size(); tr++)
	{
	  hist_part_m->Fill(particles_m->at(tr));
	}
      for(int tr=0; tr<particles_pdg->size(); tr++)
	{
	  hist_part_pdg->Fill(particles_pdg->at(tr));
	}
      
     
    }

  std::cout << "Done!" << std::endl;

  // Choose a histogram

  //track_pT
  //hist_track_pT->SetFillColor(9); hist_track_pT->Draw();
  //track_eta
  //hist_track_eta->SetFillColor(8); hist_track_eta->Draw();
  //track_phi
  //hist_track_phi->SetFillColor(30); hist_track_phi->Draw();
  //track_m
  //hist_track_m->SetFillColor(46); hist_track_m->Draw();
  //track_vtx
  //hist_track_vtx->SetFillColor(41); hist_track_vtx->Draw();

  //cluster_pT
  //hist_clust_pT->SetFillColor(9); hist_clust_pT->Draw();
  //cluster_eta
  //hist_clust_eta->SetFillColor(8); hist_clust_eta->Draw();
  //clust_phi
  //hist_clust_phi->SetFillColor(30); hist_clust_phi->Draw();
  //cluster_m
  hist_clust_m->SetFillColor(46); hist_clust_m->Draw();
  
  //particle_pT
  //hist_part_pT->SetFillColor(9); hist_part_pT->Draw();
  //particle_eta
  //hist_part_eta->SetFillColor(8); hist_part_eta->Draw();
  //particle_phi
  //hist_part_phi->SetFillColor(30); hist_part_phi->Draw();
  //particle_m
  //hist_part_m->SetFillColor(46); hist_part_m->Draw();
  //particle_pdgID
  //hist_part_pdg->SetFillColor(41); hist_part_pdg->Draw();
  
  // Let's draw and save
  c1->Draw();
  //c1->Print("track_pt.pdf");


}
