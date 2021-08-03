//____________________________________________________________________________
/*!

\class    genie::CascadeReweight

\brief    In this module, the event weight is set depending on the FSI fate. 
          The weights are set depending on the xml configuration defined by the user
\author    Julia Tena-Vidal <j.tena-vidal \at liverpool.ac.uk>

\created  July 2020

\cpright  Copyright (c) 2003-2020, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          
*/
//____________________________________________________________________________

#ifndef _CASCADE_REWEIGHT_H_
#define _CASCADE_REWEIGHT_H_

#include "Framework/EventGen/EventRecordVisitorI.h"
#include "Physics/HadronTransport/INukeHadroFates2018.h" 

namespace genie {

class CascadeReweight : public EventRecordVisitorI {

public :
  CascadeReweight();
  CascadeReweight(string config);
 ~CascadeReweight();

  // implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  // override the Algorithm::Configure methods to load configuration
  // data to private data members
  void Configure (const Registry & config);
  void Configure (string param_set);
 protected:
  double GetEventWeight (const GHepRecord & ev) const; ///< get weight from fate and configuration

private:
  void LoadConfig     (void); ///< read configuration from xml file

  // Class member
  double fDefaultWeight ; 
  std::map< int , double > fDefaultMap ; // fate, weight 
  std::map< int , map<int,double> > fFateWeightsMap ; // < fate, <pdg,weight> > 

};

}      // genie namespace
#endif // _CASCADE_REWEIGHT_H_
