// -*- C++ -*-
#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/PromptFinalState.hh"
#include "Rivet/Projections/VetoedFinalState.hh"
#include "Rivet/Projections/DressedLeptons.hh"

namespace Rivet {

    /// @name M4lLineshape analysis
    class ATLAS_2019_I00001 : public Analysis {
    public:

      /// Constructor
      DEFAULT_RIVET_ANALYSIS_CTOR(ATLAS_2019_I00001);

      void init() {

        PromptFinalState photons(Cuts::abspid == PID::PHOTON);
        PromptFinalState elecs(Cuts::abspid == PID::ELECTRON);
        PromptFinalState muons(Cuts::abspid == PID::MUON);
	elecs.acceptTauDecays(true);
	muons.acceptTauDecays(true);
	
        // Selection
	Cut el_fid_sel = (Cuts::abseta < 2.47) && (Cuts::pT > 7*GeV); 
	Cut mu_fid_sel = (Cuts::abseta < 2.7) && (Cuts::pT > 5*GeV);

        DressedLeptons dressed_elecs(photons, elecs, 0.1, el_fid_sel, false);
        declare(dressed_elecs, "elecs");

        DressedLeptons dressed_muons(photons, muons, 0.1, mu_fid_sel, false);
        declare(dressed_muons, "muons");



	// All final state particles
	Cut eta_full = (Cuts::abseta < 5.0);
	FinalState fs(eta_full);
	// Jet clustering.
        VetoedFinalState vfs(fs);
        vfs.addVetoOnThisFinalState(dressed_elecs);
        vfs.addVetoOnThisFinalState(dressed_muons);
        FastJets jets(vfs, FastJets::ANTIKT, 0.4, JetAlg::ALL_MUONS, JetAlg::DECAY_INVISIBLES);
        declare(jets, "jets");

	//	const std::vector<double> bins {75,100,120,130,150,180,200,225,255,290,325,370,440,540,680,880,1120,1800};
	//	const std::vector<double> bins {75., 79., 87., 95., 108., 120., 130., 145., 160., 175., 190., 210., 230., 255., 280., 310., 345., 380., 420., 465., 520., 580., 650., 735., 830., 940., 1075., 1265., 2000.};
	const std::vector<double> bins {75., 80., 85., 89., 93., 98., 103., 109., 115., 122., 127., 133., 139., 145., 151., 158., 165., 172., 179., 186., 193., 201., 209., 217., 226., 235., 244., 254., 264., 275., 287., 299., 311., 324., 338., 352., 367., 383., 400., 418., 440., 460., 485., 510., 535., 560., 590., 620., 655., 690., 730., 785., 850., 930., 1080., 1275., 2000.};
	const std::vector<double> bins_vbs {75,100,130,200,225,255,290,370,540,1000};
	const std::vector<double> bins_pt {0,25,50,75,100,150,200,300,400,600,800,1000};

        // Book histos

	//_h["m4l_wrongcharge"] = bookHisto1D("m4l_wrongcharge", bins);
	//_h["m4l_wrongflavour"] = bookHisto1D("m4l_wrongflavour", bins);
	_h["m4l_paper"] = bookHisto1D("m4l_paper", bins);
	_h["m4l_onshell"] = bookHisto1D("m4l_onshell", bins);
	_h["m4l_highm4l"] = bookHisto1D("m4l_highm4l", bins);
	_h["m4l_secondquad"] = bookHisto1D("m4l_secondquad", bins);
	_h["m4l_thirdquad"] = bookHisto1D("m4l_thirdquad", bins);
	//_h["m4l_fourthquad"] = bookHisto1D("m4l_fourthquad", bins);
	_h["m4l_nodRll"] = bookHisto1D("m4l_nodRll", bins);
	_h["m4l_nodRll_secondquad"] = bookHisto1D("m4l_nodRll_secondquad", bins);
	_h["m4l_nodRll_thirdquad"] = bookHisto1D("m4l_nodRll_thirdquad", bins);
	_h["m4l_nodRll_fourthquad"] = bookHisto1D("m4l_nodRll_fourthquad", bins);

	_h["m4l_ptslice1_paper"] = bookHisto1D("m4l_ptslice1_paper",bins);
        _h["m4l_ptslice2_paper"] = bookHisto1D("m4l_ptslice2_paper",bins);
        _h["m4l_ptslice3_paper"] = bookHisto1D("m4l_ptslice3_paper",bins);
        _h["m4l_ptslice4_paper"] = bookHisto1D("m4l_ptslice4_paper",bins);

        _h["m4l_rapidityslice1_paper"] = bookHisto1D("m4l_rapidityslice1_paper",bins);
        _h["m4l_rapidityslice2_paper"] = bookHisto1D("m4l_rapidityslice2_paper",bins);
        _h["m4l_rapidityslice3_paper"] = bookHisto1D("m4l_rapidityslice3_paper",bins);
        _h["m4l_rapidityslice4_paper"] = bookHisto1D("m4l_rapidityslice4_paper",bins);

        _h["m4l_4mu_paper"]   = bookHisto1D("m4l_4mu_paper",bins);
        _h["m4l_4e_paper"]    = bookHisto1D("m4l_4me_paper",bins);
        _h["m4l_2e2mu_paper"] = bookHisto1D("m4l_2e2mu_paper",bins);

	_h["y4l_onshell"] = bookHisto1D("y4l_onshell",50, 0.0,5.0);
	_h["y4l_paper"] = bookHisto1D("y4l_paper", 50, 0.0,5.0);
	_h["y4l_highm4l"] = bookHisto1D("y4l_highm4l", 50, 0.0,5.0);
	//_h["y4l_lowm4l"] = bookHisto1D("y4l_lowm4l", 50, 0.0,5.0);
	_h["pt4l_onshell"] = bookHisto1D("pt4l_onshell", bins_pt);
	_h["pt4l_paper"] = bookHisto1D("pt4l_paper", bins_pt);
	_h["pt4l_highm4l"] = bookHisto1D("pt4l_highm4l", bins_pt);
	//_h["pt4l_lowm4l"] = bookHisto1D("pt4l_lowm4l", bins_pt);
	_h["ptZ1_onshell"] = bookHisto1D("ptZ1_onshell", bins_pt);
	_h["ptZ1_paper"] = bookHisto1D("ptZ1_paper", bins_pt);
	_h["ptZ1_highm4l"] = bookHisto1D("ptZ1_highm4l", bins_pt);
	//_h["ptZ1_lowm4l"] = bookHisto1D("ptZ1_lowm4l", bins_pt);
	_h["ptZ2_onshell"] = bookHisto1D("ptZ2_onshell", bins_pt);
	_h["ptZ2_paper"] = bookHisto1D("ptZ2_paper", bins_pt);
	_h["ptZ2_highm4l"] = bookHisto1D("ptZ2_highm4l", bins_pt);
	//_h["ptZ2_lowm4l"] = bookHisto1D("ptZ2_lowm4l", bins_pt);
        _h["dy_Z1Z2_onshell"]  = bookHisto1D("dy_Z1Z2_onshell",50, 0.0,5.0);
	_h["dy_Z1Z2_paper"]  = bookHisto1D("dy_Z1Z2_paper",50, 0.0,5.0);
	_h["dy_Z1Z2_highm4l"]  = bookHisto1D("dy_Z1Z2_highm4l",50, 0.0,5.0);
	//_h["dy_Z1Z2_lowm4l"]  = bookHisto1D("dy_Z1Z2_lowm4l",50, 0.0,5.0);
	_h["dphi_Z1Z2_onshell"]  = bookHisto1D("dphi_Z1Z2_onshell",30, 0.0,pi);
	_h["dphi_Z1Z2_paper"]  = bookHisto1D("dphi_Z1Z2_paper",30, 0.0,pi);
	_h["dphi_Z1Z2_highm4l"]  = bookHisto1D("dphi_Z1Z2_highm4l",30, 0.0,pi);
	//_h["dphi_Z1Z2_lowm4l"]  = bookHisto1D("dphi_Z1Z2_lowm4l",30, 0.0,pi);
	_h["mZ1_onshell"]  = bookHisto1D("mZ1_onshell",100,0.,200.);
	_h["mZ1_paper"]  = bookHisto1D("mZ1_paper",100,0.,200.);
	_h["mZ1_highm4l"]  = bookHisto1D("mZ1_highm4l",100,0.,200.);
	//_h["mZ1_lowm4l"]  = bookHisto1D("mZ1_lowm4l",100,0.,200.);
	_h["mZ2_onshell"]  = bookHisto1D("mZ2_onshell",100,0.,200.);
	_h["mZ2_paper"]  = bookHisto1D("mZ2_paper",100,0.,200.);	
	_h["mZ2_highm4l"]  = bookHisto1D("mZ2_highm4l",100,0.,200.);
	//_h["mZ2_lowm4l"]  = bookHisto1D("mZ2_lowm4l",100,0.,200.);
	_h["mZ1_secondquad"]  = bookHisto1D("mZ1_secondquad",100,0.,200.);
	_h["mZ2_secondquad"]  = bookHisto1D("mZ2_secondquad",100,0.,200.);
	_h["mZ1_thirdquad"]  = bookHisto1D("mZ1_thirdquad",100,0.,200.);
	_h["mZ2_thirdquad"]  = bookHisto1D("mZ2_thirdquad",100,0.,200.);
	//_h["mZ1_fourthquad"]  = bookHisto1D("mZ1_fourthquad",100,0.,200.);
	//_h["mZ2_fourthquad"]  = bookHisto1D("mZ2_fourthquad",100,0.,200.);
        
	//_h["costhetastar1_lowmass_paper"] = bookHisto1D("costhetastar1_lowmass_paper",50,-1.,1.);
	//_h["costhetastar2_lowmass_paper"] = bookHisto1D("costhetastar2_lowmass_paper",50,-1.,1.);
	//_h["costhetastar1_midmass_paper"] = bookHisto1D("costhetastar1_midmass_paper",50,-1.,1.);
	//_h["costhetastar2_midmass_paper"] = bookHisto1D("costhetastar2_midmass_paper",50,-1.,1.);
	_h["costhetastar1_highmass_paper"] = bookHisto1D("costhetastar1_highmass_paper",50,-1.,1.);
	_h["costhetastar2_highmass_paper"] = bookHisto1D("costhetastar2_highmass_paper",50,-1.,1.);


	_h["nQuad"] = bookHisto1D("nQuad",10,-0.5,9.5);

        //JEM'S ADDITIONAL CODE 
        //Booking additional histograms 
        _h["costhetastar1_highlumi"] = bookHisto1D("costhetastar1_highlumi", 20, -1.,1.);
        _h["costhetastar2_highlumi"] = bookHisto1D("costhetastar2_highlumi", 20, -1.,1.);
        //JEM'S ADDITIONAL CODE
         
         
	// jet and VBS related plots
	
	_h["costhetastar1_vbs"] = bookHisto1D("costhetastar1_vbs",5,-1.,1.);
	_h["costhetastar2_vbs"] = bookHisto1D("costhetastar2_vbs",5,-1.,1.);
	

	_h["m4l_inclusive_jet"] = bookHisto1D("m4l_inclusive_jet", bins);
	_h["m4l_inclusive_dijet"] = bookHisto1D("m4l_inclusive_dijet", bins);
	_h["m4l_inclusive_vbs"] = bookHisto1D("m4l_inclusive_vbs", bins_vbs);
	_h["m4l_inclusive_vbs_onshell"] = bookHisto1D("m4l_inclusive_vbs_onshell", bins_vbs);
	
	_h["m4l_inclusive_lowcostheta"] = bookHisto1D("m4l_inclusive_lowcostheta", bins);
	_h["m4l_inclusive_midcostheta"] = bookHisto1D("m4l_inclusive_midcostheta", bins);
	_h["m4l_inclusive_highcostheta"] = bookHisto1D("m4l_inclusive_highcostheta", bins);

	  
	_h["pT_jet1"] = bookHisto1D("pT_jet1",50,0.0,500.0);
	_h["pT_jet2"] = bookHisto1D("pT_jet2",50,0.0,500.0);
	_h["N_jets"] = bookHisto1D("N_jets",10,-0.5,9.5);
	_h["mass_dijet"] = bookHisto1D("mass_dijet",50,0.0,3000.0);
	_h["mass_dijet_vbs"] = bookHisto1D("mass_dijet_vbs",50,0.0,3000.0);
	_h["mass_dijet_lowzstar"] = bookHisto1D("mass_dijet_lowzstar",50,0.0,3000.0);
	_h["mass_dijet_medzstar"] = bookHisto1D("mass_dijet_medzstar",50,0.0,3000.0);
	_h["mass_dijet_highzstar"] = bookHisto1D("mass_dijet_highzstar",50,0.0,3000.0);
	_h["deltay_dijet"] = bookHisto1D("deltay_dijet",20,0.0,10.0);
	_h["yproduct"] = bookHisto1D("yproduct",40,-30.0,10.0);
	

      }

      /// Generic dilepton candidate
      struct Dilepton : public ParticlePair {
        Dilepton() { }
        Dilepton(ParticlePair _particlepair) : ParticlePair(_particlepair) {
          assert(first.abspid() == second.abspid());
        }
        FourMomentum mom() const { return first.momentum() + second.momentum(); }
        operator FourMomentum() const { return mom(); }
        static bool cmppT(const Dilepton& lx, const Dilepton& rx) { return lx.mom().pT() < rx.mom().pT(); }
        int flavour() const { return first.abspid(); }
        double pTl1() const { return first.pT(); }
        double pTl2() const { return second.pT(); }
      };

      struct Quadruplet {
        Quadruplet (Dilepton z1, Dilepton z2): _z1(z1), _z2(z2) { }
        enum class FlavCombi { mm=0, ee, me, em, undefined };
        FourMomentum mom() const { return _z1.mom() + _z2.mom(); }
        Dilepton getZ1() const { return _z1; }
        Dilepton getZ2() const { return _z2; }
        Dilepton _z1, _z2;
        FlavCombi type() const {
          if (     _z1.flavour() == 13 && _z2.flavour() == 13) { return FlavCombi::mm; }
          else if (_z1.flavour() == 11 && _z2.flavour() == 11) { return FlavCombi::ee; } 
          else if (_z1.flavour() == 13 && _z2.flavour() == 11) { return FlavCombi::me; }
          else if (_z1.flavour() == 11 && _z2.flavour() == 13) { return FlavCombi::em; }
          else  return FlavCombi::undefined;
        }
      };

      std::vector<Quadruplet> getBestQuads(Particles& particles, bool drcut = true) {
        // H->ZZ->4l pairing
        // - Two same flavor opposite charged leptons
        // - Ambiguities in pairing are resolved by choosing the combination
        //     that results in the smaller value of |mll - mZ| for each pair successively
        std::vector<Quadruplet> quads {};

        size_t n_parts = particles.size();
        if (n_parts < 4)  return quads; 

        // STEP 1: find SFOS pairs 
        std::vector<Dilepton> SFOS;
        for (size_t i = 0; i < n_parts; ++i) {
          for (size_t j = 0; j < i; ++j) {
            if (particles[i].pid() == -particles[j].pid()) {
              // sort such that the negative lepton is listed first
	      Dilepton sfos;
              if (particles[i].pid() > 0)  sfos = make_pair(particles[i], particles[j]);
              else                         sfos = make_pair(particles[j], particles[i]);

	      if (sfos.mom().mass() > _ll_mass*GeV && (!drcut || deltaR(particles[i],particles[j]) > _dRll)) SFOS.push_back(sfos);
            }
          }
        }
        if (SFOS.size() < 2)  return quads;

        // now we sort the SFOS pairs
        std::sort(SFOS.begin(), SFOS.end(), [](const Dilepton& p1, const Dilepton& p2) {
            return fabs(p1.mom().mass() - Z_mass) < fabs(p2.mom().mass() - Z_mass);
        });

        //form all possible quadruplets, passing the pt cuts, the dR cuts and the mll cuts
        for (size_t k = 0; k < SFOS.size(); ++k) {
          for (size_t l = k+1; l < SFOS.size(); ++l) {
	    if(drcut) {
	      if (deltaR(SFOS[k].first.mom(),  SFOS[l].first.mom())  < _dRll)  continue;
	      if (deltaR(SFOS[k].first.mom(),  SFOS[l].second.mom()) < _dRll)  continue;
	      if (deltaR(SFOS[k].second.mom(), SFOS[l].first.mom())  < _dRll)  continue;
	      if (deltaR(SFOS[k].second.mom(), SFOS[l].second.mom()) < _dRll)  continue;
	    }
	    if ( (SFOS[k].first.pid()   == -SFOS[l].first.pid())  && ((SFOS[k].first.mom()  + SFOS[l].first.mom()).mass()  < _ll_mass*GeV)) continue;
	    if ( (SFOS[k].first.pid()   == -SFOS[l].second.pid()) && ((SFOS[k].first.mom()  + SFOS[l].second.mom()).mass() < _ll_mass*GeV)) continue;
	    if ( (SFOS[k].second.pid()  == -SFOS[l].first.pid())  && ((SFOS[k].second.mom() + SFOS[l].first.mom()).mass()  < _ll_mass*GeV)) continue;
	    if ( (SFOS[k].second.pid()  == -SFOS[l].second.pid()) && ((SFOS[k].second.mom() + SFOS[l].second.mom()).mass() < _ll_mass*GeV)) continue;
                
            std::vector<double> lep_pt { SFOS[k].pTl1(), SFOS[k].pTl2(), SFOS[l].pTl1(), SFOS[l].pTl2() };
            std::sort(lep_pt.begin(), lep_pt.end(), std::greater<double>()); 
	    if (!(lep_pt[0] > _pt_lep1*GeV && lep_pt[1] > _pt_lep2*GeV && lep_pt[2] > _pt_lep3*GeV)) continue;
            quads.push_back( Quadruplet(SFOS[k], SFOS[l]) );
          }
        }
        return quads;
      }

      bool passPtLeptons(const Particles& particles) {
	size_t n_parts = particles.size();
        if (n_parts < 4)  return false;
	// cut on pT of leptons
	return ( particles[0].mom().pt() > _pt_lep1*GeV && particles[1].mom().pt() > _pt_lep2*GeV && particles[2].mom().pt() > _pt_lep3*GeV) ;
      }
     

      bool isOnShell(const Quadruplet& theQuad){
	double mZ1 = theQuad.getZ1().mom().mass(); 
        double mZ2 = theQuad.getZ2().mom().mass();

	return (mZ1 > 66.*GeV && mZ1 < 116.*GeV && mZ2 > 66.*GeV && mZ2 < 116.*GeV); // abit wide, leave it 
      }
  

      // Do the analysis
      void analyze(const Event& event) {
	// fix crazy weights
      	const double weight = (fabs(event.weight())<100 ? event.weight() : event.weight()/fabs(event.weight())) ;
	//const double weight = event.weight();

        //preselection of leptons for ZZ-> llll final state
        Particles dressed_leptons;
        for (auto lep : apply<DressedLeptons>(event, "muons").dressedLeptons()) { dressed_leptons.push_back(lep); }
        for (auto lep : apply<DressedLeptons>(event, "elecs").dressedLeptons()) { dressed_leptons.push_back(lep); }

	// sort to put hishest pT first
	std::sort(dressed_leptons.begin(), dressed_leptons.end(), [](const Particle& l1, const Particle& l2) {
            return l1.pt() > l2.pt();
        });

	// make pT cuts and select events without two SFOS pairs.
	//if (dressed_leptons.size() > 3 && passPtLeptons(dressed_leptons)) {
	  //const FourMomentum mom4l = dressed_leptons.at(0).momentum() + dressed_leptons.at(1).momentum() + dressed_leptons.at(2).momentum() + dressed_leptons.at(3).momentum();	 
	  //if ((dressed_leptons.at(0).charge() + dressed_leptons.at(1).charge() + dressed_leptons.at(2).charge() + dressed_leptons.at(3).charge()) != 0) _h["m4l_wrongcharge"]->fill(mom4l.mass()/GeV, weight);
	  //else if ((dressed_leptons.at(0).pid() + dressed_leptons.at(1).pid() + dressed_leptons.at(2).pid() + dressed_leptons.at(3).pid()) != 0)        _h["m4l_wrongflavour"]->fill(mom4l.mass()/GeV, weight);
	//}

	auto foundDressedNoDrll = getBestQuads(dressed_leptons,false);

	if ( foundDressedNoDrll.size() >0) _h["m4l_nodRll"]->fill(foundDressedNoDrll[0].mom().mass()/GeV, weight);
	if ( foundDressedNoDrll.size() >1) _h["m4l_nodRll_secondquad"]->fill(foundDressedNoDrll[1].mom().mass()/GeV, weight);
	if ( foundDressedNoDrll.size() >2) _h["m4l_nodRll_thirdquad"]->fill(foundDressedNoDrll[2].mom().mass()/GeV, weight);
	if ( foundDressedNoDrll.size() >3) _h["m4l_nodRll_fourthquad"]->fill(foundDressedNoDrll[3].mom().mass()/GeV, weight);

	auto foundDressed = getBestQuads(dressed_leptons);
        // if we don't find any quad, we can stop here 
        if (foundDressed.empty())  vetoEvent;

	_h["nQuad"]->fill(foundDressed.size(), weight);
	if (foundDressed.size() > 1) {
	  _h["m4l_secondquad"]->fill(foundDressed[1].mom().mass()/GeV, weight);
	  _h["mZ1_secondquad"]->fill(foundDressed[1].getZ1().mom().mass()/GeV, weight);
	  _h["mZ2_secondquad"]->fill(foundDressed[1].getZ2().mom().mass()/GeV, weight);
	  
	}
	if (foundDressed.size() > 2) {
	  _h["m4l_thirdquad"]->fill(foundDressed[2].mom().mass()/GeV, weight);
	  _h["mZ1_thirdquad"]->fill(foundDressed[2].getZ1().mom().mass()/GeV, weight);
	  _h["mZ2_thirdquad"]->fill(foundDressed[2].getZ2().mom().mass()/GeV, weight);
	}
	//if (foundDressed.size() > 3) {
	//  _h["m4l_fourthquad"]->fill(foundDressed[3].mom().mass()/GeV, weight);
	//  _h["mZ1_fourthquad"]->fill(foundDressed[3].getZ1().mom().mass()/GeV, weight);
	//  _h["mZ2_fourthquad"]->fill(foundDressed[3].getZ2().mom().mass()/GeV, weight);
	//}
	
	double m4l = foundDressed[0].mom().mass()/GeV;
	double pt4l = foundDressed[0].mom().pT()/GeV;
	double y4l = foundDressed[0].mom().absrap();
	double mZ1 = foundDressed[0].getZ1().mom().mass()/GeV;
	double mZ2 = foundDressed[0].getZ2().mom().mass()/GeV;
	double ptZ1 = foundDressed[0].getZ1().mom().pT()/GeV;
	double ptZ2 = foundDressed[0].getZ2().mom().pT()/GeV;
	double dy_Z1Z2 = fabs(foundDressed[0].getZ1().mom().rapidity() - foundDressed[0].getZ2().mom().rapidity());
	double dphi_Z1Z2 = deltaPhi(foundDressed[0].getZ1().mom(),foundDressed[0].getZ2().mom());
	
	bool onShell = isOnShell(foundDressed[0]);
	if (onShell) {
	  _h["m4l_onshell"]->fill(m4l, weight);
	  _h["y4l_onshell"]->fill(y4l, weight);
	  _h["pt4l_onshell"]->fill(pt4l, weight);	   
	  _h["ptZ1_onshell"]->fill(ptZ1,weight);
	  _h["ptZ2_onshell"]->fill(ptZ2,weight);
	  _h["dy_Z1Z2_onshell"]->fill(dy_Z1Z2,weight);
	  _h["dphi_Z1Z2_onshell"]->fill(dphi_Z1Z2,weight);
	  _h["mZ1_onshell"]->fill(mZ1,weight);
	  _h["mZ2_onshell"]->fill(mZ2,weight);

	    
	}
	if (m4l > 150.) {
	  _h["m4l_highm4l"]->fill(m4l, weight);
	  _h["y4l_highm4l"]->fill(y4l, weight);
	  _h["pt4l_highm4l"]->fill(pt4l, weight);	   
	  _h["ptZ1_highm4l"]->fill(ptZ1,weight);
	  _h["ptZ2_highm4l"]->fill(ptZ2,weight);
	  _h["dy_Z1Z2_highm4l"]->fill(dy_Z1Z2,weight);
	  _h["dphi_Z1Z2_highm4l"]->fill(dphi_Z1Z2,weight);
	  _h["mZ1_highm4l"]->fill(mZ1,weight);
	  _h["mZ2_highm4l"]->fill(mZ2,weight);

	} //else if (m4l < 100.) {
	  //_h["y4l_lowm4l"]->fill(y4l, weight);
	  //_h["pt4l_lowm4l"]->fill(pt4l, weight);	   
	  //_h["ptZ1_lowm4l"]->fill(ptZ1,weight);
	  //_h["ptZ2_lowm4l"]->fill(ptZ2,weight);
	  //_h["dy_Z1Z2_lowm4l"]->fill(dy_Z1Z2,weight);
	  //_h["dphi_Z1Z2_lowm4l"]->fill(dphi_Z1Z2,weight);
	  //_h["mZ1_lowm4l"]->fill(mZ1,weight);
	  //_h["mZ2_lowm4l"]->fill(mZ2,weight);
	//}
	  
	_h["mZ1_paper"]->fill(mZ1,weight);
	_h["mZ2_paper"]->fill(mZ2,weight);
	_h["y4l_paper"]->fill(y4l,weight);
	_h["pt4l_paper"]->fill(pt4l,weight);
	_h["ptZ1_paper"]->fill(ptZ1,weight);
	_h["ptZ2_paper"]->fill(ptZ2,weight);
	_h["dy_Z1Z2_paper"]->fill(dy_Z1Z2,weight);
	_h["dphi_Z1Z2_paper"]->fill(dphi_Z1Z2,weight);

	_h["m4l_paper"]->fill(m4l, weight);
	if (     pt4l <  20.)  _h["m4l_ptslice1_paper"]->fill(m4l,weight);
	else if (pt4l <  50.)  _h["m4l_ptslice2_paper"]->fill(m4l,weight);
	else if (pt4l < 100.)  _h["m4l_ptslice3_paper"]->fill(m4l,weight);
	else if (pt4l < 600.)  _h["m4l_ptslice4_paper"]->fill(m4l,weight);

	if (     y4l < 0.4)  _h["m4l_rapidityslice1_paper"]->fill(m4l,weight);
	else if (y4l < 0.8)  _h["m4l_rapidityslice2_paper"]->fill(m4l,weight);
	else if (y4l < 1.2)  _h["m4l_rapidityslice3_paper"]->fill(m4l,weight);
	else if (y4l < 2.5)  _h["m4l_rapidityslice4_paper"]->fill(m4l,weight);
	
	Quadruplet::FlavCombi flavour = foundDressed[0].type();
	if (     flavour == Quadruplet::FlavCombi::mm) _h["m4l_4mu_paper"]->fill(m4l,weight);
	else if (flavour == Quadruplet::FlavCombi::ee) _h["m4l_4e_paper"]->fill(m4l,weight);
	else if (flavour == Quadruplet::FlavCombi::me || flavour == Quadruplet::FlavCombi::em) {
	  _h["m4l_2e2mu_paper"]->fill(m4l,weight);
	}
	
	// polarization variables
	// Get four-momentum of the first lepton pair
	const FourMomentum pcom = foundDressed.at(0).getZ1().mom();
	const Vector3 betacom = pcom.betaVec();
	const Vector3 unitboostvec = betacom.unit();
	const LorentzTransform comboost = LorentzTransform::mkFrameTransformFromBeta(betacom);
	// Get four-momentum of the negative lepton w.r.t. the first lepton pair
	const FourMomentum p1com = comboost.transform(foundDressed.at(0).getZ1().first.mom());
	float costhetastar1 = cos(p1com.p3().angle(unitboostvec));
	
	// Get four-momentum of the second lepton pair
	const FourMomentum pcom2 = foundDressed.at(0).getZ2().mom();
	const Vector3 betacom2 = pcom2.betaVec();
	const Vector3 unitboostvec2 = betacom2.unit();
	const LorentzTransform comboost2 = LorentzTransform::mkFrameTransformFromBeta(betacom2);
	// Get four-momentum of the negative lepton w.r.t. the second lepton pair
	const FourMomentum p2com = comboost2.transform(foundDressed.at(0).getZ2().first.mom());
	float  costhetastar2 = cos(p2com.p3().angle(unitboostvec2));


	if (costhetastar1 < -0.35) _h["m4l_inclusive_lowcostheta"]->fill(m4l, weight);
	else if (costhetastar1 < 0.35) _h["m4l_inclusive_midcostheta"]->fill(m4l, weight);
	else _h["m4l_inclusive_highcostheta"]->fill(m4l, weight);
	
	//if (m4l < 100.) {
	  //_h["costhetastar1_lowmass_paper"]->fill(costhetastar1 , weight);
	  //_h["costhetastar2_lowmass_paper"]->fill(costhetastar2 , weight);

	//} else if (m4l < 150.) {
	  //_h["costhetastar1_midmass_paper"]->fill(costhetastar1 , weight);
	  //_h["costhetastar2_midmass_paper"]->fill(costhetastar2 , weight);
	//} else {
	  //_h["costhetastar1_highmass_paper"]->fill(costhetastar1 , weight);
	  //_h["costhetastar2_highmass_paper"]->fill(costhetastar2 , weight);
	//}
	
         _h["costhetastar1_highmass_paper"]->fill(costhetastar1 , weight);
         _h["costhetastar2_highmass_paper"]->fill(costhetastar2 , weight);
	
	// Do jet selection in events that pass to make some VBF / VBS plots
	const Jets& jets = apply<FastJets>(event, "jets").jetsByPt(Cuts::pT > 30*GeV && Cuts::abseta < 4.5);
	    
	// Number of jets
	_h["N_jets"]->fill(jets.size(), weight);
	if (jets.empty())  vetoEvent;           
	_h["pT_jet1"]->fill(jets.front().pt()/GeV, weight);
	_h["m4l_inclusive_jet"]->fill(m4l, weight);
	// If at least two jets present
	if (jets.size() < 2)  vetoEvent;

	_h["pT_jet2"]->fill(jets.at(1).pt()/GeV, weight);
	double mjj  = (jets.at(0).mom() + jets.at(1).mom()).mass()/GeV;
	double deltay = fabs(jets.at(0).rapidity() - jets.at(1).rapidity());
	_h["mass_dijet"]->fill(mjj, weight);
	_h["deltay_dijet"]->fill(deltay, weight);
	_h["m4l_inclusive_dijet"]->fill(m4l, weight);
	float yproduct = jets.at(0).mom().rapidity() * jets.at(1).mom().rapidity();
	_h["yproduct"]->fill(yproduct, weight);
	
        //JEM'S ADDITIONAL CODE 
        if (onShell && m4l > 180.*GeV && mjj > 1500){
        _h["costhetastar1_highlumi"]->fill(costhetastar1, weight);
        _h["costhetastar2_highlumi"]->fill(costhetastar2, weight);
        } 
        //JEM'S ADDITIONAL CODE 
       

        //insert histogram costhetastar1/2_HighLumi before filling
        //if (onShell) m4l > 180.*GeV mjj > 1500.)
        //fill costhetastar1/2_HighLumi 
        //yodascale 3000x label (3000*0.56 and 3000*583) nvents 
        //run for madgraph and sherpa and compare them (cross section) 
        //run Madgraph with different polarization states and compare again with sherpa 
        //Then after this, we can take off sherpa 
        //Compare madgraph total with madgraph ZLZL and with ZLZT and ZTZT 
        //
        //1. madgraph total and sherpa 
        //2. madgraph total and madgraph ZLZL 
        //3. madgraph total and madgraph ZLZT
        //4. madgraph total and madgraph ZTZT
        //5. madgraph total and madgraph (ZLZL, ZLZT, and ZTZT) which could be done by yodamerge --add *scaled.yoda -o all-scaled.yoda

        // VBS selection
	if (deltay < 2) vetoEvent;
	if (jets.at(0).pt()/GeV < 80.) vetoEvent;
	if (jets.at(1).pt()/GeV < 60.) vetoEvent;	
	if (yproduct > 0.0F )  vetoEvent;
	
	_h["mass_dijet_vbs"]->fill(mjj, weight);
	double jet_avgy = 0.5*(jets.at(0).rapidity() + jets.at(1).rapidity());
	double ystar4l = fabs(y4l - jet_avgy);
	double zstar4l = ystar4l / deltay;
	if (zstar4l < 0.3) _h["mass_dijet_lowzstar"]->fill(mjj,weight);
	else if (zstar4l < 0.6) _h["mass_dijet_medzstar"]->fill(mjj,weight);
	else  _h["mass_dijet_highzstar"]->fill(mjj,weight);
	
	_h["m4l_inclusive_vbs"]->fill(m4l, weight);
	// make on-shell mass cuts
	   
	if (onShell) _h["m4l_inclusive_vbs_onshell"]->fill(m4l, weight);
	if (m4l > 180.*GeV) {
	  _h["costhetastar1_vbs"]->fill(costhetastar1 , weight);
	  _h["costhetastar2_vbs"]->fill(costhetastar2 , weight);
	}
	
	
      }//end analysis

      /// Finalize
      void finalize() {
        const double sf = /*crossSection()/ femtobarn*/ 1.0 / sumOfWeights();
        for (auto hist : _h) { scale(hist.second, sf); }
      }

      private:

        map<string, Histo1DPtr> _h;
        static constexpr double Z_mass = 91.1876;
        static constexpr float _pt_lep1 = 20.;
        static constexpr float _pt_lep2 = 10.;
        static constexpr float _pt_lep3 = 0.;
        static constexpr float _ll_mass = 5.;
        static constexpr float _dRll = 0.05;
     
    };  // end class ATLAS_2019_I00001

    DECLARE_RIVET_PLUGIN(ATLAS_2019_I00001);
}  // end namespace rivet
