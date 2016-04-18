/****************************************************************************
*
* This is a part of TOTEM offline software.
* Authors:
* 	Hubert Niewiadomski
*   Jan Kašpar (jan.kaspar@gmail.com)
*
****************************************************************************/

#ifndef RecoTotemRP_RPRecoHitProducer_TotemRPRecHitProducerAlgorithm_h
#define RecoTotemRP_RPRecoHitProducer_TotemRPRecHitProducerAlgorithm_h

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/DetSet.h"
#include "DataFormats/CTPPSReco/interface/TotemRPCluster.h"
#include "DataFormats/CTPPSReco/interface/TotemRPRecHit.h"

#include "Geometry/VeryForwardRPTopology/interface/RPTopology.h"

class TotemRPRecHitProducerAlgorithm
{
  public:
    TotemRPRecHitProducerAlgorithm(const edm::ParameterSet& conf)
    {
    }

    void BuildRecoHits(const edm::DetSet<TotemRPCluster>& input, edm::DetSet<TotemRPRecHit>& output);

  private:
    RPTopology rp_topology_;
};

#endif
