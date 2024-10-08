//____________________________________________________________________________
/*!

\class    genie::NormInteractionListGenerator

\brief    Concrete implementations of the InteractionListGeneratorI interface.
          Generates a list of all the Interaction (= event summary) objects that
          can be generated by the NormGenerator.

\author   Igor Kakorin <kakorin@jinr.ru>
          Joint Institute for Nuclear Research

\created  May 16, 2022

\cpright  Copyright (c) 2003-2024, The GENIE Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
     
*/
//____________________________________________________________________________

#ifndef _NORM_INTERACTION_LIST_GENERATOR_H_
#define _NORM_INTERACTION_LIST_GENERATOR_H_

#include "Framework/EventGen/InteractionListGeneratorI.h"

namespace genie {

class NormInteractionListGenerator : public InteractionListGeneratorI {

public :

  NormInteractionListGenerator();
  NormInteractionListGenerator(string config);
  ~NormInteractionListGenerator();

  //-- implement the InteractionListGeneratorI interface
  InteractionList * CreateInteractionList(const InitialState & init) const;

  //-- overload the Algorithm::Configure() methods to load private data
  //   members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void LoadConfigData(void);


};

}      // genie namespace

#endif // _NORM_INTERACTION_LIST_GENERATOR_H_
