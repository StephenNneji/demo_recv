//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xgehrd.h
//
// Code generation for function 'xgehrd'
//
#ifndef XGEHRD_H
#define XGEHRD_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace lapack
      {
        void xgehrd(::coder::array<real_T, 2U> &a, ::coder::array<real_T, 1U>
                    &tau);
      }
    }
  }
}

#endif

// End of code generation (xgehrd.h)
