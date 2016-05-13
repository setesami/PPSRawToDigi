/****************************************************************************
 *
 * This is a part of TOTEM offline software.
 * Authors:
 *	Jan Kašpar (jan.kaspar@gmail.com)
 *
 ****************************************************************************/

#ifndef Alignment_RPDataFormats_RPAlignmentCorrections
#define Alignment_RPDataFormats_RPAlignmentCorrections

#include "DataFormats/CTPPSAlignment/interface/RPAlignmentCorrectionData.h"
#include "DataFormats/CTPPSAlignment/interface/RPAlignmentCorrectionsData.h"

#include <map>

#include <xercesc/dom/DOM.hpp>

namespace edm {
  class ParameterSet;
}

class AlignmentGeometry;


/**
 *\brief Container for RP alignment corrections.
 * The corrections are stored on two levels - RP and sensor. For every level,
 * there is a map: symbolic ID --> alignment correction. Sensors inherit the
 * alignment corrections for the corresponding RP, see GetFullSensorCorrection
 * method.
 **/
class RPAlignmentCorrectionsMethods
{

  public:
    RPAlignmentCorrectionsMethods() {}
  
    /// constructs object from an XML file
//    RPAlignmentCorrectionsMethods(const std::string &fileName)
//      { LoadXMLFile(fileName); }
//
//    /// constructs object from a block of alignment-sequence XML file
//    RPAlignmentCorrectionsMethods(xercesc::DOMNode *e)
//      { LoadXMLBlock(e); }
  
    static RPAlignmentCorrectionsData GetCorrectionsDataFromFile(const std::string &fileName);

    static RPAlignmentCorrectionsData GetCorrectionsData(xercesc::DOMNode *);

    /// writes corrections into a single XML file
    static void WriteXMLFile(const RPAlignmentCorrectionsData &, const std::string &fileName, bool precise=false, bool wrErrors=true, bool wrSh_r=true,
        bool wrSh_xy=true, bool wrSh_z=true, bool wrRot_z=true);
    
    /// writes a block of corrections into a file
    static void WriteXMLBlock(const RPAlignmentCorrectionsData &, FILE *, bool precise=false, bool wrErrors=true, bool wrSh_r=true,
        bool wrSh_xy=true, bool wrSh_z=true, bool wrRot_z=true);
  

    /// factors out the common shifts and rotations for every RP and saves these values as RPalignment
    /// (factored variable), the expanded alignments are created as a by-product
    static void FactorRPFromSensorCorrections(RPAlignmentCorrectionsData &expanded, RPAlignmentCorrectionsData &factored,
      const AlignmentGeometry &, bool equalWeights=false, unsigned int verbosity = 0);

};

#endif

