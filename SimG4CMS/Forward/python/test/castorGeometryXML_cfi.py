import FWCore.ParameterSet.Config as cms

XMLIdealGeometryESSource = cms.ESSource("XMLIdealGeometryESSource",
    geomXMLFiles = cms.vstring('Geometry/CMSCommonData/data/materials.xml', 
        'Geometry/CMSCommonData/data/rotations.xml', 
        'Geometry/CMSCommonData/data/cms.xml', 
        'Geometry/CMSCommonData/data/beampipe.xml', 
        'Geometry/CMSCommonData/data/cavern.xml', 
        'Geometry/CMSCommonData/data/mgnt.xml', 
        'Geometry/ForwardCommonData/data/forward.xml', 
        'Geometry/ForwardCommonData/data/forwardshield.xml', 
        'Geometry/ForwardCommonData/data/castor.xml', 
        'SimG4CMS/Forward/test/data/CaloUtil.xml', 
        'Geometry/ForwardSimData/data/castorsens.xml', 
        'Geometry/ForwardSimData/data/CastorProdCuts.xml'),
    rootNodeName = cms.string('cms:OCMS')
)


