#ifndef Forward_TotemTestHistoClass_h
#define Forward_TotemTestHistoClass_h 1
// -*- C++ -*-
//
// Package:     Forward
// Class  :     TotemTestHistoClass
//
/**\class TotemTestHistoClass TotemTestHistoClass.h SimG4CMS/Forward/interface/TotemTestHistoClass.h
 
 Description: Content of the Root file for Totem Tests
 
 Usage:
    Used in testing Totem simulation
 
*/
//
// Original Author: 
//         Created:  Tue May 16 10:14:34 CEST 2006
// $Id: TotemTestHistoClass.h,v 1.1.1.1 2007/05/16 15:44:30 hniewiad Exp $
//
 
#include <vector>

class TotemTestHistoClass {

public:
  TotemTestHistoClass();
  ~TotemTestHistoClass();

  void setEVT(int v)      {evt=v;}

  void fillHit(int uID, int pType, int tID, int pID, float eLoss, float pAbs,
	       float vX, float vY, float vZ, float x, float y, float z);

  struct Hit {
    Hit() {}
    int   UID;
    int   Ptype;
    int   TID;
    int   PID;
    float ELoss;
    float PABS;
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
  };

private:
  int              evt, hits;
  std::vector<Hit> hit;
};

#endif
