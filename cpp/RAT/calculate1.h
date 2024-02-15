//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// calculate1.h
//
// Code generation for function 'calculate1'
//
#ifndef CALCULATE1_H
#define CALCULATE1_H

// Include files
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace RAT
{
  namespace nonPolarisedTF
  {
    namespace customLayers
    {
      void calculate(const c_struct_T *problemStruct, const cell_11
                     *problemCells, const struct2_T *controls, d_struct_T
                     *contrastParams, ::coder::array<cell_wrap_20, 1U>
                     &reflectivity, ::coder::array<cell_wrap_20, 1U> &simulation,
                     ::coder::array<cell_wrap_8, 1U> &shiftedData, ::coder::
                     array<cell_wrap_8, 1U> &layerSlds, ::coder::array<
                     cell_wrap_8, 1U> &sldProfiles, ::coder::array<cell_wrap_8,
                     1U> &allLayers);
    }
  }
}

#endif

// End of code generation (calculate1.h)
