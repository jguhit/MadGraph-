# MadGraph-
Using MadGraph for generating polarized particles 

INSTALLATIONS 

All MadGraph tar files can be downloaded in this link: https://drive.google.com/drive/folders/1Rj31e2HTlckHM6OKe5Q5OLBm115o2sgZ?usp=sharing

I. Installing MG5_aMC_2.7.0 (Polarized Particles) 
1. cp /home/guhitj/bsmxsec3/Madgraph/mg5_pol.tar
2. tar xvf mg5_pol.tar (this creates a directory with the MadGraph files and executables) 
3. cd MG5_aMC_pol (or the name of the created directory) 
4. Type ./bin/mg5_aMC (MadGraph Prompt) 
* or to automate 4. you could create an alias in your .bashrc: 
alias Mad_Graph_pol='<Directory>/MG5_aMC_pol/bin/mg5_aMC'
5. After launching madgraph type the following: 
  - install lhapdf6 (for systematics) 
  - install pythia-pgs 
  - install pythia8 
6. Type 'exit' to exit the program   
7. In your .bashrc or .bash_profile, add the following lines: 
  
------------------------------------------------------------------------------------------------------------------------------
export PYTHIA8=path_to_PYTHIA8_installation
export LD_LIBRARY_PATH=$HOME/<Directory>/MG5_aMC_pol/HEPTools/hepmc/HepMC_install/lib:$LD_LIBRARY_PATH
export PATH=$PATH:/<Directory>/MG5_aMC_v2_6_6/HEPTools/lhapdf6/bin

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ROOTSYS/lib:/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6/lib:/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6/include

export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6/include:/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6/lib:/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6

PYTHONPATH="/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6/include:/lustre/umt3/user/guhitj/New/MG5_aMC_pol/HEPTools/lhapdf6/lib:/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6:/<Directory>/MG5_aMC_pol/HEPTools/lhapdf6/bin:$PYTHONPATH"

export PYTHONPATH  

------------------------------------------------------------------------------------------------------------------------------

II. Installing MadGraph5_v1.5.14 (Decay Package) 
1. cp /home/guhitj/bsmxsec3/Madgraph/MadGraph5_v1.5.14.tar
2. tar xvf MadGraph5_v1.5.14.tar
3. cd MadGraph5_v1_5_14
4. Type ./bin/mg5 (MadGraph Prompt)  
or alias Mad_Graphv5='<Directory>/MadGraph5_v1_5_14/bin/mg5'
  
I.II Configuring the DECAY Package 
1. cd  MadGraph5_v1_5_14/DECAY
2. Replace the original decay_couplings.f and decay.f files by the ones attached in the repository 
3. make (compile the decay code) 
This step creates an executable called "decay" 
4. ./decay 
or alias mad_decay='<Directory>/MadGraph5_v1_5_14/DECAY/decay'

III. 
RECIPE FOR GENERATING POLARIZED PARTICLES  
Part 1: Generating the different polarization modes 
1. Type MadGraph Prompt for version installed in I 
2. Type 'generate p p > Z{L} Z{L} j j QCD=0' , {L} is for Longitudinal and {T} is for Transverse 
3. To save process in an output file, type 'output <output folder>' 
4. cd "output folder>"
  
If you want to create multiple runs, then 
  1. ./bin/madevent 
  2. Type multi_run 5 (5 is an arbitrary number) 
  3. Proceed to 7. 
  
If you want to create just a single run, then proceed to 6.

6. ./bin/generate_events
7. Five (1-5) switches containing which programs are run and you could choose which one to activate, 
 e.g shower=Pythia8, activates the shower/hadronization program 
8. When finished choosing the programs to run in 7., Type done 
9. Prompts you to choose if you want to edit a Card (contains information about your process, the masses of particles, cuts, no. of events) 
  e.g Type 2, and edit Events = 10000 to Events = 15000
10. When finished editing the Cards, Type done 
11. Once the events are generated, Type exit 
  
Part 2: Decaying Polarized Particles 
1. In your output folder directory, cd /Events/run_01 (or the appropriate run folder) 
2. Type 'gunzip unweighted_events.lhe.gz' to unzip the Les Houches Event Files 
3. You should have an output called unweighted_events.lhe
(you could choose to rename the .lhe file to something more specific if generating more than one .lhe file)
4. Execute the decay package, Type mad_decay or ./<Directory>/DECAY/decay
5. You are given a prompt to choose an "Input run mode", to decay events in the file, Type 1
6. Then you are asked the name of the event file to decay, Type unweighted_events.lhe (or the appropriate name of your .lhe file) 
7. Type your desired output .lhe filename, Type <output.lhe> 
8. Choose the particle you are decaying, e.g Type Z 
9. Choose the appropriate decay mode, e.g Type 4 ( z -> l+ l-)
10. Done! 

ANALYIS USING RIVET 
Part 1: Converting .lhe to .hepmc file

Installing HepMC 
1. Download source code from http://lcgapp.cern.ch/project/simu/HepMC/download/
2. Create a directory called 'hepmc' in your machine and save the above tar ball here. Type mkdir hepmc 
3. On a terminal, cd to this 'hepmc' folder and type 'tar -xzf HepMC-2.06.09.tar.gz'
4. Type 'mkdir HepMC_build HepMC_install'
5. Type 'cd HepMC_build'
6 ../HepMC-2.06.09/configure -prefix=<Directory>/hepmc/HepMC_install -with-momentum=GEV -with-length=MM
7. Now type 'make'
8. Do 'make check'
9. Do 'make install'
10. If everything goes smooth, then done!
  
  To continue with part 2, the following .h files have to be modified 
  - GenEvent.h
  - GenVertex.h
  - GenParticle.h
  - SimpleVector.h
  - Polarization.h
  - IO-GenEvent.h
  - IO-BaseClass.h
  
  When opening these .h file, change the "include" lines to the correct directory. For example, 
  change
  #include "/home/HepMC-2.06.09/HepMC/GenVertex.h" 
  to 
  #include "/<directory>/hepmc/HepMC-2.06.09/HepMC/GenVertex.h"

  These files are located in the following directories: (you must modify both files in these directories) 
  - ../hepmc/HepMC-2.06.09/HepMC 
  - ../hepmc/HepMC-2.06.09/include/HepMC

Part 2: Installing the lhef to hepmc converter  
1. Make a directory lhef2hepmc, Type mkdir lhef2hepmc
2. cd lhef2hepmc 
3. hg clone https://phab.hepforge.org/source/rivetcontribhg/browse/default/lhef2hepmc/
You should have four files in the directory: ChangeLog, Makefile, lhef2hepmc.cc, and ttbar.lhe
if hg command not found, instructions for installing hg (if working proceed to step 4)
  Part 2.5: Installing Mercurial 
  1. Download source code at https://www.mercurial-scm.org/downloads (download the Mercurial 5.1 source release) 
  2. gunzip mercurial-5.1.tar.gz
  3. tar -xvf mercurial-5.1.tar
  4. cd mercurial-5.1
  5. make local 
  6. check if working by ./hg --version 
  7. Leave directory and go back to lhef2hepmc directory and type ./mercurial-5.1/hg clone https://phab.hepforge.org/source/rivetcontribhg/browse/default/lhef2hepmc/
    
4. cd ../lhef2hepmc/ 
5. Type make HEPMC_PREFIX=/home/HepMC-2.06.09/
6. This should create an executable called "lhef2hepmc"

Part 3: Using the lhef to hepmc converter 
1. In the lhef2hepmc directory, Type mkfifo fifo.hepmc 
2. export LD_LIBRARY_PATH=$HOME/bsmxsec3/hepmc/HepMC_install/lib:$LD_LIBRARY_PATH
3. ./lhef2hepmc ttbar.lhe fifo.hepmc &
4. source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
or 
export ATLAS_LOCAL_ROOT_BASE=/cvmfs/atlas.cern.ch/repo/ATLASLocalRootBase
alias setupATLAS='source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh'
5. asetup 21.6.6,AthGeneration
6. source setupRivet.sh
7. mkdir Rivet
8. cd Rivet 
9. Download files on the folder RivetFiles folder (uploaded in the repository) 
10. rivet-buildplugin --with-root RivetATLAS_2019_I00001.so  ATLAS_2019_I00001.cc
11. rivet -a ATLAS_2019_I00001 --pwd fifo.hepmc (The output file is a Rivet.yoda file) 
12. rivet-mkhtml --mc-errs -o Test Rivet.yoda
 

