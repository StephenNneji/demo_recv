//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// processCustomFunction.cpp
//
// Code generation for function 'processCustomFunction'
//

// Include files
#include "processCustomFunction.h"
#include "RATMain_types.h"
#include "applyHydrationImag.h"
#include "applyHydrationReal.h"
#include "callCppFunction.h"
#include "rt_nonfinite.h"
#include "str2double.h"
#include "coder_array.h"
#include <cmath>

// Function Declarations
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_18, 1U> &r, ::coder::array<
                   cell_wrap_8, 1U> &r1);
}

// Function Definitions
namespace RAT
{
  static void cast(const ::coder::array<cell_wrap_18, 1U> &r, ::coder::array<
                   cell_wrap_8, 1U> &r1)
  {
    int32_T i;
    r1.set_size(r.size(0));
    i = r.size(0);
    for (int32_T i1{0}; i1 < i; i1++) {
      int32_T loop_ub;
      loop_ub = r[i1].f1.size(1);
      r1[i1].f1.set_size(r[i1].f1.size(0), r[i1].f1.size(1));
      for (int32_T i2{0}; i2 < loop_ub; i2++) {
        int32_T b_loop_ub;
        b_loop_ub = r[i1].f1.size(0);
        for (int32_T i3{0}; i3 < b_loop_ub; i3++) {
          r1[i1].f1[i3 + r1[i1].f1.size(0) * i2] = r[i1].f1[i3 + r[i1].f1.size(0)
            * i2];
        }
      }
    }
  }

  namespace nonPolarisedTF
  {
    namespace customLayers
    {
      void processCustomFunction(const ::coder::array<real_T, 2U>
        &contrastBulkIns, const ::coder::array<real_T, 2U> &contrastBulkOuts,
        const ::coder::array<real_T, 2U> &bulkIn, const ::coder::array<real_T,
        2U> &bulkOut, const ::coder::array<real_T, 2U> &cCustFiles, real_T
        numberOfContrasts, const ::coder::array<cell_wrap_1, 2U> &customFiles,
        const ::coder::array<real_T, 2U> &params, boolean_T useImaginary, ::
        coder::array<cell_wrap_8, 1U> &allLayers, ::coder::array<real_T, 1U>
        &allRoughs)
      {
        ::coder::array<cell_wrap_18, 1U> tempAllLayers;
        ::coder::array<real_T, 2U> allBulkOuts;
        ::coder::array<real_T, 2U> b_allBulkOuts;
        ::coder::array<real_T, 2U> b_params;
        ::coder::array<real_T, 2U> thisContrastLayers;
        int32_T i;
        int32_T loop_ub;

        //  Top-level function for processing custom layers for all the
        //  contrasts.
        //  Do some pre-definitions to keep the compiler happy...
        i = static_cast<int32_T>(numberOfContrasts);
        allRoughs.set_size(i);
        allBulkOuts.set_size(1, contrastBulkOuts.size(1));
        loop_ub = contrastBulkOuts.size(1);
        for (int32_T i1{0}; i1 < loop_ub; i1++) {
          allBulkOuts[i1] = bulkOut[static_cast<int32_T>(contrastBulkOuts[i1]) -
            1];
        }

        tempAllLayers.set_size(i);
        for (int32_T b_i{0}; b_i < i; b_i++) {
          creal_T x;
          real_T d;
          int32_T iv[2];

          //  TODO - the ambition is for parfor here, but would fail for Matlab and Python CM's..
          //  Choose which custom file is associated with this contrast
          //  Find values of 'bulkIn' and 'bulkOut' for this
          //  contrast...
          //  typeDef
          d = cCustFiles[b_i];
          iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                    static_cast<int32_T>(d) - 1].f1)->size())[0];
          iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)&customFiles[
                    static_cast<int32_T>(d) - 1].f1)->size())[1];
          x = coder::str2double((const char_T *)((::coder::array<char_T, 2U> *)
            &customFiles[static_cast<int32_T>(d) - 1].f1)->data(), iv);
          if ((!std::isnan(x.re)) && (!std::isnan(x.im))) {
            b_params.set_size(1, params.size(1));
            loop_ub = params.size(1) - 1;
            for (int32_T i1{0}; i1 <= loop_ub; i1++) {
              b_params[i1] = params[i1];
            }

            b_allBulkOuts.set_size(1, allBulkOuts.size(1));
            loop_ub = allBulkOuts.size(1) - 1;
            for (int32_T i1{0}; i1 <= loop_ub; i1++) {
              b_allBulkOuts[i1] = allBulkOuts[i1];
            }

            iv[0] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(d) - 1].f1)->size())[0];
            iv[1] = (*(int32_T (*)[2])((::coder::array<char_T, 2U> *)
                      &customFiles[static_cast<int32_T>(d) - 1].f1)->size())[1];
            callCppFunction((const char_T *)((::coder::array<char_T, 2U> *)
              &customFiles[static_cast<int32_T>(d) - 1].f1)->data(), iv,
                            b_params, bulkIn[static_cast<int32_T>
                            (contrastBulkIns[b_i]) - 1], b_allBulkOuts, (
              static_cast<real_T>(b_i) + 1.0) - 1.0, thisContrastLayers,
                            &allRoughs[b_i]);
          }

          //  If the output layers has 5 columns, then we need to do
          //  the hydration correction (the user has not done it in the
          //  custom function). Do that here....
          if (!useImaginary) {
            applyHydrationReal(thisContrastLayers, bulkIn[static_cast<int32_T>
                               (contrastBulkIns[b_i]) - 1], allBulkOuts[b_i]);
          } else {
            applyHydrationImag(thisContrastLayers, bulkIn[static_cast<int32_T>
                               (contrastBulkIns[b_i]) - 1], allBulkOuts[b_i]);
          }

          loop_ub = thisContrastLayers.size(1);
          tempAllLayers[b_i].f1.set_size(thisContrastLayers.size(0),
            thisContrastLayers.size(1));
          for (int32_T i1{0}; i1 < loop_ub; i1++) {
            int32_T b_loop_ub;
            b_loop_ub = thisContrastLayers.size(0);
            for (int32_T i2{0}; i2 < b_loop_ub; i2++) {
              tempAllLayers[b_i].f1[i2 + tempAllLayers[b_i].f1.size(0) * i1] =
                thisContrastLayers[i2 + thisContrastLayers.size(0) * i1];
            }
          }
        }

        cast(tempAllLayers, allLayers);
      }
    }
  }
}

// End of code generation (processCustomFunction.cpp)
