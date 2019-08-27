theApp.EvtMax = -1
# theApp.EvtMax = -1

import os
import AthenaPoolCnvSvc.ReadAthenaPool

import glob
print "running with "
# print glob.glob("/home/goblirsc/Datasets/H4l/EVNT/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/*")
#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc16_13TeV.364283.Sherpa_222_NNPDF30NNLO_lllljj_EW6.merge.EVNT.e6055_e5984/*")
#svcMgr.EventSelector.InputCollections = glob.glob("/home/guhitj/bsmxsec3/Jobs2.0/output_20190712/EVNT_test10575.pool.root")

svcMgr.EventSelector.InputCollections = glob.glob("/home/guhitj/bsmxsec3/Rivet_Analysis/plot.root_files/EVNT_test110719.pool.root")
#svcMgr.EventSelector.InputCollections = glob.glob("/home/guhitj/bsmxsec3/Jobs2.0/output_20190712/EVNT_test14081.pool.root")
#svcMgr.EventSelector.InputCollections = glob.glob("/home/guhitj/bsmxsec3/Jobs2.0/output_20190712/EVNT_test16877.pool.root")
#svcMgr.EventSelector.InputCollections = glob.glob("/home/guhitj/bsmxsec3/Jobs2.0/output_20190712/EVNT_test18606.pool.root")
#svcMgr.EventSelector.InputCollections = glob.glob("/home/guhitj/bsmxsec3/Jobs2.0/output_20190712/EVNT_test18691.pool.root")

#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc16_13TeV.363724.MadGraphPythia8EvtGen_ZZllvv2jEWK.merge.EVNT.e5712_e5984/EVNT.12627656._000001.pool.root.1")

#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc16_13TeV.345071.MGPy8EvtGen_A14_NNPDF23LO_VBFH125_sbi_4l_m4l130_EW6.merge.EVNT.e5994_e5984/EVNT.12629152._000001.pool.root.1")
#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._022894.pool.root.1")

#svcMgr.EventSelector.InputCollections = glob.glob("/home/guhitj/bsmxsec3/Jobs2.0/output_20190711/EVNT_test27274.pool.root")

#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.410142.Sherpa_NNPDF30NNLO_ttll_mll5.evgen.EVNT.e4686/EVNT.11827820._000001.pool.root.1")

#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.361621.Sherpa_CT10_WWZ_4l2v.evgen.EVNT.e4053/EVNT.05724581._000001.pool.root.1")

#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc16_13TeV.345071.MGPy8EvtGen_A14_NNPDF23LO_VBFH125_sbi_4l_m4l130_EW6.merge.EVNT.e5994_e5984/EVNT.12629152._000001.pool.root.1")

#FILES = "/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._001097.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._002431.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._007437.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._007982.pool.root.1"
#"/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._009621.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._009712.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._011402.pool.root.1"

#/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._022894.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._026262.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._032360.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._041838.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._042679.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._046417.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._056778.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._070843.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._072871.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._073071.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._077796.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._080746.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._083843.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._087315.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._087509.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._088480.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._093165.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._093713.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._103629.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._104166.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._107023.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._110907.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._114821.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._121147.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._121766.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._126196.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._126966.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._131228.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._132739.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._137810.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._142956.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._144677.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._148349.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._152192.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._158472.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._170953.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._174351.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._186925.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._188056.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._191424.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._192689.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._207219.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._218001.pool.root.1,/unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/EVNT.11041837._218250.pool.root.1"

#svcMgr.EventSelector.InputCollections = FILES.split(',')
# /unix/bsmxsec2/zgrout/Samples/mc15_13TeV.364250.Sherpa_222_NNPDF30NNLO_llll.evgen.EVNT.e5894/
#svcMgr.EventSelector.InputCollections = glob.glob("/unix/bsmxsec2/zgrout/Samples/mc16_13TeV.345706.Sherpa_222_NNPDF30NNLO_ggllll_130M4l.merge.EVNT.e6213_e5984/EVNT.12842743._000027.pool.root.1")

# svcMgr.EventSelector.InputCollections = glob.glob("/home/goblirsc/Datasets/H4l/EVNT/mc15_13TeV.361603.PowhegPy8EG_CT10nloME_AZNLOCTEQ6L1_ZZllll_mll4.evgen.EVNT.e4475/*")[0:2]


from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

from GaudiSvc.GaudiSvcConf import THistSvc
ServiceMgr += THistSvc()
ServiceMgr.THistSvc.Output = ["Rivet DATAFILE='Rivet.root' OPT='RECREATE'"]


from Rivet_i.Rivet_iConf import Rivet_i

rivet = Rivet_i()
rivet.AnalysisPath = os.environ['PWD']
#rivet.Analyses += [ 'ATLAS_2019_VBS' ]
rivet.Analyses += [ 'ATLAS_2019_I00001' ]
#rivet.Analyses += [ 'ATLAS_2019_I1720442' ]
rivet.Analyses += [ 'MC_XS' ]
rivet.RunName = ""

#rivet.WeightName=" nnlops-nominal "
#rivet.WeightName= ' nominal '
#rivet.WeightName = ' PDF set = 90420 '

rivet.HistoFile = "myanalysis"
rivet.DoRootHistos = True
#rivet.CrossSection = 9.1185E+03
job += rivet
