//____________________________________________________________________________
/*!

\namespace  genie::utils::nuclear

\brief      Simple nuclear physics empirical formulas

\author     Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
            CCLRC, Rutherford Appleton Laboratory

\created    May 06, 2004

*/
//____________________________________________________________________________

#ifndef _NUCLEAR_UTILS_H_
#define _NUCLEAR_UTILS_H_

#include <string>

using std::string;

namespace genie {

class Target;

namespace utils {

namespace nuclear
{
  double BindEnergy             (const Target & target);
  double BindEnergyPerNucleon   (const Target & target);
  double BindEnergyLastNucleon  (const Target & target);
  double Radius                 (const Target & target);

  double NuclQELXSecSuppression (string kftable, double pmax, const Interaction * in);

  double FmI1   (double alpha, double beta,
                  double a, double b,  double kFi, double kFf, double q);
  double FmI2   (double alpha, double beta,
                  double a, double b,  double kFi, double kFf, double q);
  double FmArea (double alpha, double beta, double kf, double pmax);

} // nuclear namespace
} // utils   namespace
} // genie   namespace

#endif // _NUCL_UTILS_H_
