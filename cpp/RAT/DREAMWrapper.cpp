//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, educational organizations only. Not for
// government, commercial, or other organizational use.
//
// DREAMWrapper.cpp
//
// Code generation for function 'DREAMWrapper'
//

// Include files
#include "DREAMWrapper.h"
#include "RATMain_internal_types.h"
#include "RATMain_types.h"
#include "reflectivityCalculation.h"
#include "rt_nonfinite.h"
#include "unpackParams.h"
#include "coder_array.h"

// Function Definitions
namespace RAT
{
  real_T DREAMWrapper(const ::coder::array<real_T, 2U> &pars, const f_struct_T
                      *ratInputs_problemStruct, const cell_11
                      *ratInputs_problemCells, const struct1_T
                      *ratInputs_problemLimits, const struct2_T
                      *ratInputs_controls)
  {
    f_struct_T problemStruct;
    struct5_T expl_temp;
    int32_T loop_ub;

    //  Get the inputs for Reflectivity Calculation
    problemStruct = *ratInputs_problemStruct;

    //  Put the current parameters into problem
    problemStruct.fitParams.set_size(1, pars.size(1));
    loop_ub = pars.size(1);
    for (int32_T i{0}; i < loop_ub; i++) {
      problemStruct.fitParams[problemStruct.fitParams.size(0) * i] = pars[i];
    }

    //  Distribute them to the right parts
    unpackParams(&problemStruct, ratInputs_controls->checks.fitParam,
                 ratInputs_controls->checks.fitBackgroundParam,
                 ratInputs_controls->checks.fitQzshift,
                 ratInputs_controls->checks.fitScalefactor,
                 ratInputs_controls->checks.fitBulkIn,
                 ratInputs_controls->checks.fitBulkOut,
                 ratInputs_controls->checks.fitResolutionParam,
                 ratInputs_controls->checks.fitDomainRatio);

    //  Calculate....
    reflectivityCalculation(&problemStruct, ratInputs_problemCells,
      ratInputs_problemLimits, ratInputs_controls, &expl_temp);

    //  Function value is chi-squared....
    return -expl_temp.calculationResults.sumChi / 2.0;
  }
}

// End of code generation (DREAMWrapper.cpp)
