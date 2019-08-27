Specific Example: 
Goal: Practice to generate a polarized particle in the transverse mode (also applies to longitudinal mode) 
and compare it to a previously made sample to cross-check if all the installations are correct 

Additional Comments: README.md file talks about how to install the programs and introduces other terms used in this file 

1. Launch MG5_aMC_pol
2. Type 'generate p p > Z{T} Z{T} j j QCD=0'
3. To save this process in a folder, type 'output <output folder>' e.g 'output ZTZT'
4. Type exit, to quit the program 
5. cd ZTZT
6. ./bin/generate_events (we are only doing 1 run) 
7. When prompted, Type 'shower=Pythia8', then enter
8. Type 'done'
9. When prompted, Type '2', then enter
10. Change number of events from 10000 to 1000, 1000 = nevents, since we are only doing a practice run 
11. Type 'done'
12. cd Events/run_0x (where x = no. of run) 
13. Type 'gunzip unweighted_events.lhe.gz'
14. Launch MG_decay 
15. Type 1 (for decay events in file)
16. Type the filename of the .lhe file to decay 
17. Type the output filename of .lhe file (e.g dec-ZTZT.lhe) 
18. Type z (since in this process we are decaying the Z Boson) 
19. Type 4 (z -> l+ l-)
20. cd ../ (Leave MG5_aMC_pol directory) 
21. cd lhef2hepmc directory
22. export LD_LIBRARY_PATH=$HOME/bsmxsec3/hepmc/HepMC_install/lib:$LD_LIBRARY_PATH
23. ./lhef2hepmc /<directory>/dec-ZTZT.lhe fifo.hepmc &
24. Type source ${ATLAS_LOCAL_ROOT_BASE}/user/atlasLocalSetup.sh
25. asetup 21.6.6,AthGeneration
26  source setupRivet.sh
21. mkdir Rivet
22. cd Rivet 
23. Download files on the folder Rivet_Analysis_2 folder (uploaded in the repository) 
24. rivet -a ATLAS_2019_I00001 --pwd fifo.hepmc
25. rivet-mkhtml --mc-errs -o Test Rivet.yoda
26. Compare with plots in this link: http://www.hep.ucl.ac.uk/~guhitj/Test_Official/ATLAS_2019_I00001/index.html

