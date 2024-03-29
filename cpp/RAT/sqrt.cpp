//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// sqrt.cpp
//
// Code generation for function 'sqrt'
//

// Include files
#include "sqrt.h"
#include "RATMain_rtwutil.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace scalar
      {
        void d_sqrt(creal_T *x)
        {
          real_T absxi;
          real_T xi;
          real_T xr;
          xr = x->re;
          xi = x->im;
          if (xi == 0.0) {
            if (xr < 0.0) {
              absxi = 0.0;
              xr = std::sqrt(-xr);
            } else {
              absxi = std::sqrt(xr);
              xr = 0.0;
            }
          } else if (xr == 0.0) {
            if (xi < 0.0) {
              absxi = std::sqrt(-xi / 2.0);
              xr = -absxi;
            } else {
              absxi = std::sqrt(xi / 2.0);
              xr = absxi;
            }
          } else if (std::isnan(xr)) {
            absxi = xr;
          } else if (std::isnan(xi)) {
            absxi = xi;
            xr = xi;
          } else if (std::isinf(xi)) {
            absxi = std::abs(xi);
            xr = xi;
          } else if (std::isinf(xr)) {
            if (xr < 0.0) {
              absxi = 0.0;
              xr = xi * -xr;
            } else {
              absxi = xr;
              xr = 0.0;
            }
          } else {
            real_T absxr;
            absxr = std::abs(xr);
            absxi = std::abs(xi);
            if ((absxr > 4.4942328371557893E+307) || (absxi >
                 4.4942328371557893E+307)) {
              absxr *= 0.5;
              absxi = rt_hypotd_snf(absxr, absxi * 0.5);
              if (absxi > absxr) {
                absxi = std::sqrt(absxi) * std::sqrt(absxr / absxi + 1.0);
              } else {
                absxi = std::sqrt(absxi) * 1.4142135623730951;
              }
            } else {
              absxi = std::sqrt((rt_hypotd_snf(absxr, absxi) + absxr) * 0.5);
            }

            if (xr > 0.0) {
              xr = 0.5 * (xi / absxi);
            } else {
              if (xi < 0.0) {
                xr = -absxi;
              } else {
                xr = absxi;
              }

              absxi = 0.5 * (xi / xr);
            }
          }

          x->re = absxi;
          x->im = xr;
        }
      }
    }
  }
}

// End of code generation (sqrt.cpp)
