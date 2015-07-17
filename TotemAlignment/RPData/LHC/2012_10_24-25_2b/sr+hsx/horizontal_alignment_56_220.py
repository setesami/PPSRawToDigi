import FWCore.ParameterSet.Config as cms

process = cms.Process("ModifySingularModes")

# minimum of logs
process.load("Configuration.TotemCommon.LoggerMin_cfi")

# empty source
process.source = cms.Source("EmptySource")
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(1)
)

# geometry
#process.load("Configuration.TotemCommon.geometryRP_cfi")
process.load("Configuration.TotemCommon.geometryRP_real_cfi")
process.XMLIdealGeometryESSource.geomXMLFiles.append("Geometry/TotemRPData/data/2012_10_24-25_2b//RP_Dist_Beam_Cent.xml")
process.TotemRPGeometryESModule = cms.ESProducer("TotemRPGeometryESModule")

# include alignments, if any
process.load("TotemAlignment.RPDataFormats.TotemRPIncludeAlignments_cfi")
process.TotemRPIncludeAlignments.RealFiles = cms.vstring()

sector = "56"

sign = +1.
if sector == "45":
  sign = -1.

# worker
process.load("TotemAlignment.RPTrackBased.ModifySingularModes_cfi")
process.ModifySingularModes.inputFile = '/afs/cern.ch/exp/totem/scratch/jkaspar/software/offline/424/src/TotemAlignment/RPData/LHC/2012_10_24-25_2b//sr/56_220.xml'
process.ModifySingularModes.outputFile = '/afs/cern.ch/exp/totem/scratch/jkaspar/software/offline/424/src/TotemAlignment/RPData/LHC/2012_10_24-25_2b//sr+hsx/56_220.xml'

process.TotemRPIncludeAlignments.RealFiles = cms.vstring('/afs/cern.ch/exp/totem/scratch/jkaspar/software/offline/424/src/TotemAlignment/RPData/LHC/2012_10_24-25_2b//sr/56_220.xml')

process.ModifySingularModes.z1 = 214628*sign # near vert
process.ModifySingularModes.z2 = 220000*sign # far vert

process.ModifySingularModes.de_x1 = .080
process.ModifySingularModes.de_x2 = -.711

process.ModifySingularModes.de_y1 = 0
process.ModifySingularModes.de_y2 = 0

process.p = cms.Path(process.ModifySingularModes)
