/****************************************************************************
 * Author: Seyed Mohsen Etesami 
 * Spetember 2016
 ****************************************************************************/


#include "DataFormats/CTPPSDetId/interface/CTPPSDiamondDetId.h"

#include "FWCore/Utilities/interface/Exception.h"

using namespace std;

//----------------------------------------------------------------------------------------------------

CTPPSDiamondDetId::CTPPSDiamondDetId(uint32_t id) : CTPPSDetId(id)
{
  if (! Check(id))
    {
      throw cms::Exception("InvalidDetId") << "CTPPSDiamondDetId ctor:"
					   << " det: " << det()
					   << " subdet: " << subdetId()
					   << " is not a valid CTPPS Timing Diamond id";  
    }
}

//----------------------------------------------------------------------------------------------------

CTPPSDiamondDetId::CTPPSDiamondDetId(uint32_t Arm, uint32_t Station, uint32_t RomanPot, uint32_t Plane, uint32_t Det) :       
  CTPPSDetId(sdTimingDiamond, Arm, Station, RomanPot)
{
  if (Arm > maxArm || Station > maxStation || RomanPot > maxRP || Plane > maxPlane || Det > maxDet)
    {
      throw cms::Exception("InvalidDetId") << "CTPPSDiamondDetId ctor:" 
					   << " Invalid parameters:" 
					   << " arm=" << Arm
					   << " station=" << Station
					   << " rp=" << RomanPot
					   << " plane=" << Plane
					   << " detector=" << Det
					   << std::endl;
    }

  uint32_t ok=0xfe000000;
  id_ &= ok;

  id_ |= ((Arm & maskArm) << startArmBit);
  id_ |= ((Station & maskStation) << startStationBit);
  id_ |= ((RomanPot & maskRP) << startRPBit);
  id_ |= ((Plane & maskPlane) << startPlaneBit);
  id_ |= ((Det & maskDet) << startDetBit);
}

//----------------------------------------------------------------------------------------------------

std::ostream& operator << (std::ostream& os, const CTPPSDiamondDetId& id)
{
  os << "arm=" << id.arm()
     << " station=" << id.station()
     << " rp=" << id.rp()
     << " plane=" << id.plane()
     << " Detector=" << id.det();

  return os;
}

