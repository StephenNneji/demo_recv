//
// Non-Degree Granting Education License -- for use at non-degree
// granting, nonprofit, education, and research organizations only. Not
// for commercial or industrial use.
//
// xzhgeqz.cpp
//
// Code generation for function 'xzhgeqz'
//

// Include files
#include "xzhgeqz.h"
#include "RATMain_data.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "xzlanhs.h"
#include "xzlartg.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace RAT
{
  namespace coder
  {
    namespace internal
    {
      namespace reflapack
      {
        void xzhgeqz(::coder::array<creal_T, 2U> &A, int32_T ilo, int32_T ihi, ::
                     coder::array<creal_T, 2U> &Z, int32_T *info, ::coder::array<
                     creal_T, 1U> &alpha1, ::coder::array<creal_T, 1U> &beta1)
        {
          ::coder::array<creal_T, 2U> b_A;
          creal_T ctemp;
          creal_T stemp;
          creal_T y;
          real_T anorm;
          real_T ascale;
          real_T b_atol;
          real_T bscale;
          real_T eshift_im;
          real_T eshift_re;
          real_T temp;
          real_T tempr;
          int32_T i;
          int32_T ilast;
          int32_T j;
          int32_T jm1;
          int32_T jp1;
          int32_T n;
          boolean_T compz;
          boolean_T failed;
          boolean_T guard1;
          boolean_T guard2;
          *info = 0;
          compz = ((Z.size(0) != 0) && (Z.size(1) != 0));
          if ((A.size(0) == 1) && (A.size(1) == 1)) {
            ihi = 1;
          }

          n = A.size(0);
          jm1 = A.size(0);
          alpha1.set_size(jm1);
          for (i = 0; i < jm1; i++) {
            alpha1[i].re = 0.0;
            alpha1[i].im = 0.0;
          }

          jm1 = A.size(0);
          beta1.set_size(jm1);
          for (i = 0; i < jm1; i++) {
            beta1[i].re = 1.0;
            beta1[i].im = 0.0;
          }

          eshift_re = 0.0;
          eshift_im = 0.0;
          ctemp.re = 0.0;
          ctemp.im = 0.0;
          anorm = xzlanhs(A, ilo, ihi);
          tempr = 2.2204460492503131E-16 * anorm;
          b_atol = 2.2250738585072014E-308;
          if (tempr > 2.2250738585072014E-308) {
            b_atol = tempr;
          }

          tempr = 2.2250738585072014E-308;
          if (anorm > 2.2250738585072014E-308) {
            tempr = anorm;
          }

          ascale = 1.0 / tempr;
          bscale = 1.0 / std::sqrt(static_cast<real_T>(A.size(0)));
          failed = true;
          i = ihi + 1;
          for (j = i; j <= n; j++) {
            alpha1[j - 1] = A[(j + A.size(0) * (j - 1)) - 1];
          }

          guard1 = false;
          guard2 = false;
          if (ihi >= ilo) {
            int32_T ifirst;
            int32_T ifrstm;
            int32_T iiter;
            int32_T ilastm;
            int32_T ilastm1;
            int32_T istart;
            int32_T jiter;
            boolean_T goto60;
            boolean_T goto70;
            boolean_T goto90;
            ifirst = ilo;
            istart = ilo;
            ilast = ihi - 1;
            ilastm1 = ihi - 2;
            if (compz) {
              ifrstm = 1;
              ilastm = n;
            } else {
              ifrstm = ilo;
              ilastm = ihi;
            }

            iiter = 0;
            goto60 = false;
            goto70 = false;
            goto90 = false;
            jiter = 0;
            int32_T exitg1;
            do {
              exitg1 = 0;
              if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
                boolean_T b_guard1;
                boolean_T exitg2;
                b_guard1 = false;
                if (ilast + 1 == ilo) {
                  goto60 = true;
                  b_guard1 = true;
                } else if (std::abs(A[ilast + A.size(0) * ilastm1].re) + std::
                           abs(A[ilast + A.size(0) * ilastm1].im) <= std::fmax
                           (2.2250738585072014E-308, 2.2204460492503131E-16 *
                            ((std::abs(A[ilast + A.size(0) * ilast].re) + std::
                              abs(A[ilast + A.size(0) * ilast].im)) + (std::abs
                              (A[ilastm1 + A.size(0) * ilastm1].re) + std::abs
                              (A[ilastm1 + A.size(0) * ilastm1].im))))) {
                  A[ilast + A.size(0) * ilastm1].re = 0.0;
                  A[ilast + A.size(0) * ilastm1].im = 0.0;
                  goto60 = true;
                  b_guard1 = true;
                } else {
                  boolean_T guard3;
                  j = ilastm1;
                  guard3 = false;
                  exitg2 = false;
                  while ((!exitg2) && (j + 1 >= ilo)) {
                    if (j + 1 == ilo) {
                      guard3 = true;
                      exitg2 = true;
                    } else if (std::abs(A[j + A.size(0) * (j - 1)].re) + std::
                               abs(A[j + A.size(0) * (j - 1)].im) <= std::fmax
                               (2.2250738585072014E-308, 2.2204460492503131E-16 *
                                ((std::abs(A[j + A.size(0) * j].re) + std::abs
                                  (A[j + A.size(0) * j].im)) + (std::abs(A[(j +
                        A.size(0) * (j - 1)) - 1].re) + std::abs(A[(j + A.size(0)
                      * (j - 1)) - 1].im))))) {
                      A[j + A.size(0) * (j - 1)].re = 0.0;
                      A[j + A.size(0) * (j - 1)].im = 0.0;
                      guard3 = true;
                      exitg2 = true;
                    } else {
                      j--;
                      guard3 = false;
                    }
                  }

                  if (guard3) {
                    ifirst = j + 1;
                    goto70 = true;
                  }

                  if (goto70) {
                    b_guard1 = true;
                  } else {
                    jm1 = alpha1.size(0);
                    alpha1.set_size(jm1);
                    for (i = 0; i < jm1; i++) {
                      alpha1[i].re = rtNaN;
                      alpha1[i].im = 0.0;
                    }

                    jm1 = beta1.size(0);
                    beta1.set_size(jm1);
                    for (i = 0; i < jm1; i++) {
                      beta1[i].re = rtNaN;
                      beta1[i].im = 0.0;
                    }

                    if (compz) {
                      jm1 = Z.size(0);
                      jp1 = Z.size(1);
                      Z.set_size(jm1, jp1);
                      for (i = 0; i < jp1; i++) {
                        for (int32_T i1{0}; i1 < jm1; i1++) {
                          Z[i1 + Z.size(0) * i].re = rtNaN;
                          Z[i1 + Z.size(0) * i].im = 0.0;
                        }
                      }
                    }

                    *info = 1;
                    exitg1 = 1;
                  }
                }

                if (b_guard1) {
                  if (goto60) {
                    goto60 = false;
                    alpha1[ilast] = A[ilast + A.size(0) * ilast];
                    ilast = ilastm1;
                    ilastm1--;
                    if (ilast + 1 < ilo) {
                      failed = false;
                      guard2 = true;
                      exitg1 = 1;
                    } else {
                      iiter = 0;
                      eshift_re = 0.0;
                      eshift_im = 0.0;
                      if (!compz) {
                        ilastm = ilast + 1;
                        if (ifrstm > ilast + 1) {
                          ifrstm = ilo;
                        }
                      }

                      jiter++;
                    }
                  } else {
                    if (goto70) {
                      real_T ad22_im;
                      real_T ad22_re;
                      real_T temp2;
                      real_T y_im_tmp;
                      goto70 = false;
                      iiter++;
                      if (!compz) {
                        ifrstm = ifirst;
                      }

                      if (iiter - iiter / 10 * 10 != 0) {
                        tempr = ascale * A[ilast + A.size(0) * ilast].re;
                        anorm = ascale * A[ilast + A.size(0) * ilast].im;
                        if (anorm == 0.0) {
                          ad22_re = tempr / bscale;
                          ad22_im = 0.0;
                        } else if (tempr == 0.0) {
                          ad22_re = 0.0;
                          ad22_im = anorm / bscale;
                        } else {
                          ad22_re = tempr / bscale;
                          ad22_im = anorm / bscale;
                        }

                        tempr = ascale * A[ilastm1 + A.size(0) * ilast].re;
                        anorm = ascale * A[ilastm1 + A.size(0) * ilast].im;
                        if (anorm == 0.0) {
                          stemp.re = tempr / bscale;
                          stemp.im = 0.0;
                        } else if (tempr == 0.0) {
                          stemp.re = 0.0;
                          stemp.im = anorm / bscale;
                        } else {
                          stemp.re = tempr / bscale;
                          stemp.im = anorm / bscale;
                        }

                        scalar::d_sqrt(&stemp);
                        tempr = ascale * A[ilast + A.size(0) * ilastm1].re;
                        anorm = ascale * A[ilast + A.size(0) * ilastm1].im;
                        if (anorm == 0.0) {
                          y.re = tempr / bscale;
                          y.im = 0.0;
                        } else if (tempr == 0.0) {
                          y.re = 0.0;
                          y.im = anorm / bscale;
                        } else {
                          y.re = tempr / bscale;
                          y.im = anorm / bscale;
                        }

                        scalar::d_sqrt(&y);
                        ctemp.re = stemp.re * y.re - stemp.im * y.im;
                        ctemp.im = stemp.re * y.im + stemp.im * y.re;
                        if ((ctemp.re != 0.0) || (ctemp.im != 0.0)) {
                          real_T x_im;
                          real_T x_re;
                          tempr = ascale * A[ilastm1 + A.size(0) * ilastm1].re;
                          anorm = ascale * A[ilastm1 + A.size(0) * ilastm1].im;
                          if (anorm == 0.0) {
                            tempr /= bscale;
                            anorm = 0.0;
                          } else if (tempr == 0.0) {
                            tempr = 0.0;
                            anorm /= bscale;
                          } else {
                            tempr /= bscale;
                            anorm /= bscale;
                          }

                          x_re = 0.5 * (tempr - ad22_re);
                          x_im = 0.5 * (anorm - ad22_im);
                          temp2 = std::abs(x_re) + std::abs(x_im);
                          temp = std::fmax(std::abs(ctemp.re) + std::abs
                                           (ctemp.im), temp2);
                          if (x_im == 0.0) {
                            stemp.re = x_re / temp;
                            stemp.im = 0.0;
                          } else if (x_re == 0.0) {
                            stemp.re = 0.0;
                            stemp.im = x_im / temp;
                          } else {
                            stemp.re = x_re / temp;
                            stemp.im = x_im / temp;
                          }

                          if (ctemp.im == 0.0) {
                            y.re = ctemp.re / temp;
                            y.im = 0.0;
                          } else if (ctemp.re == 0.0) {
                            y.re = 0.0;
                            y.im = ctemp.im / temp;
                          } else {
                            y.re = ctemp.re / temp;
                            y.im = ctemp.im / temp;
                          }

                          anorm = stemp.re * stemp.re - stemp.im * stemp.im;
                          tempr = stemp.re * stemp.im;
                          y_im_tmp = y.re * y.im;
                          stemp.re = anorm + (y.re * y.re - y.im * y.im);
                          stemp.im = (tempr + tempr) + (y_im_tmp + y_im_tmp);
                          scalar::d_sqrt(&stemp);
                          y.re = temp * stemp.re;
                          y.im = temp * stemp.im;
                          if (temp2 > 0.0) {
                            if (x_im == 0.0) {
                              tempr = x_re / temp2;
                              anorm = 0.0;
                            } else {
                              if (x_re == 0.0) {
                                tempr = 0.0;
                              } else {
                                tempr = x_re / temp2;
                              }

                              anorm = x_im / temp2;
                            }

                            if (tempr * y.re + anorm * y.im < 0.0) {
                              y.re = -y.re;
                              y.im = -y.im;
                            }
                          }

                          tempr = x_re + y.re;
                          temp = x_im + y.im;
                          if (temp == 0.0) {
                            if (ctemp.im == 0.0) {
                              y_im_tmp = ctemp.re / tempr;
                              tempr = 0.0;
                            } else if (ctemp.re == 0.0) {
                              y_im_tmp = 0.0;
                              tempr = ctemp.im / tempr;
                            } else {
                              y_im_tmp = ctemp.re / tempr;
                              tempr = ctemp.im / tempr;
                            }
                          } else if (tempr == 0.0) {
                            if (ctemp.re == 0.0) {
                              y_im_tmp = ctemp.im / temp;
                              tempr = 0.0;
                            } else if (ctemp.im == 0.0) {
                              y_im_tmp = 0.0;
                              tempr = -(ctemp.re / temp);
                            } else {
                              y_im_tmp = ctemp.im / temp;
                              tempr = -(ctemp.re / temp);
                            }
                          } else {
                            temp2 = std::abs(tempr);
                            anorm = std::abs(temp);
                            if (temp2 > anorm) {
                              anorm = temp / tempr;
                              tempr += anorm * temp;
                              y_im_tmp = (ctemp.re + anorm * ctemp.im) / tempr;
                              tempr = (ctemp.im - anorm * ctemp.re) / tempr;
                            } else if (anorm == temp2) {
                              if (tempr > 0.0) {
                                tempr = 0.5;
                              } else {
                                tempr = -0.5;
                              }

                              if (temp > 0.0) {
                                anorm = 0.5;
                              } else {
                                anorm = -0.5;
                              }

                              y_im_tmp = (ctemp.re * tempr + ctemp.im * anorm) /
                                temp2;
                              tempr = (ctemp.im * tempr - ctemp.re * anorm) /
                                temp2;
                            } else {
                              anorm = tempr / temp;
                              tempr = temp + anorm * tempr;
                              y_im_tmp = (anorm * ctemp.re + ctemp.im) / tempr;
                              tempr = (anorm * ctemp.im - ctemp.re) / tempr;
                            }
                          }

                          ad22_re -= ctemp.re * y_im_tmp - ctemp.im * tempr;
                          ad22_im -= ctemp.re * tempr + ctemp.im * y_im_tmp;
                        }
                      } else {
                        if (iiter - iiter / 20 * 20 == 0) {
                          tempr = ascale * A[ilast + A.size(0) * ilast].re;
                          anorm = ascale * A[ilast + A.size(0) * ilast].im;
                          if (anorm == 0.0) {
                            tempr /= bscale;
                            anorm = 0.0;
                          } else if (tempr == 0.0) {
                            tempr = 0.0;
                            anorm /= bscale;
                          } else {
                            tempr /= bscale;
                            anorm /= bscale;
                          }

                          eshift_re += tempr;
                          eshift_im += anorm;
                        } else {
                          tempr = ascale * A[ilast + A.size(0) * ilastm1].re;
                          anorm = ascale * A[ilast + A.size(0) * ilastm1].im;
                          if (anorm == 0.0) {
                            tempr /= bscale;
                            anorm = 0.0;
                          } else if (tempr == 0.0) {
                            tempr = 0.0;
                            anorm /= bscale;
                          } else {
                            tempr /= bscale;
                            anorm /= bscale;
                          }

                          eshift_re += tempr;
                          eshift_im += anorm;
                        }

                        ad22_re = eshift_re;
                        ad22_im = eshift_im;
                      }

                      j = ilastm1;
                      jp1 = ilastm1 + 1;
                      exitg2 = false;
                      while ((!exitg2) && (j + 1 > ifirst)) {
                        istart = j + 1;
                        ctemp.re = ascale * A[j + A.size(0) * j].re - ad22_re *
                          bscale;
                        ctemp.im = ascale * A[j + A.size(0) * j].im - ad22_im *
                          bscale;
                        temp = std::abs(ctemp.re) + std::abs(ctemp.im);
                        temp2 = ascale * (std::abs(A[jp1 + A.size(0) * j].re) +
                                          std::abs(A[jp1 + A.size(0) * j].im));
                        tempr = temp;
                        if (temp2 > temp) {
                          tempr = temp2;
                        }

                        if ((tempr < 1.0) && (tempr != 0.0)) {
                          temp /= tempr;
                          temp2 /= tempr;
                        }

                        if ((std::abs(A[j + A.size(0) * (j - 1)].re) + std::abs
                             (A[j + A.size(0) * (j - 1)].im)) * temp2 <= temp *
                            b_atol) {
                          goto90 = true;
                          exitg2 = true;
                        } else {
                          jp1 = j;
                          j--;
                        }
                      }

                      if (!goto90) {
                        istart = ifirst;
                        ctemp.re = ascale * A[(ifirst + A.size(0) * (ifirst - 1))
                          - 1].re - ad22_re * bscale;
                        ctemp.im = ascale * A[(ifirst + A.size(0) * (ifirst - 1))
                          - 1].im - ad22_im * bscale;
                      }

                      goto90 = false;
                      stemp.re = ascale * A[istart + A.size(0) * (istart - 1)].
                        re;
                      stemp.im = ascale * A[istart + A.size(0) * (istart - 1)].
                        im;
                      xzlartg(ctemp, stemp, &temp, &y);
                      j = istart;
                      jm1 = istart - 2;
                      while (j < ilast + 1) {
                        if (j > istart) {
                          xzlartg(A[(j + A.size(0) * jm1) - 1], A[j + A.size(0) *
                                  jm1], &temp, &y, &A[(j + A.size(0) * jm1) - 1]);
                          A[j + A.size(0) * jm1].re = 0.0;
                          A[j + A.size(0) * jm1].im = 0.0;
                        }

                        for (jp1 = j; jp1 <= ilastm; jp1++) {
                          anorm = A[j + A.size(0) * (jp1 - 1)].im;
                          tempr = A[j + A.size(0) * (jp1 - 1)].re;
                          temp2 = A[(j + A.size(0) * (jp1 - 1)) - 1].re;
                          stemp.re = temp * temp2 + (y.re * tempr - y.im * anorm);
                          y_im_tmp = A[(j + A.size(0) * (jp1 - 1)) - 1].im;
                          stemp.im = temp * y_im_tmp + (y.re * anorm + y.im *
                            tempr);
                          A[j + A.size(0) * (jp1 - 1)].re = temp * tempr - (y.re
                            * temp2 + y.im * y_im_tmp);
                          A[j + A.size(0) * (jp1 - 1)].im = temp * A[j + A.size
                            (0) * (jp1 - 1)].im - (y.re * y_im_tmp - y.im *
                            temp2);
                          A[(j + A.size(0) * (jp1 - 1)) - 1] = stemp;
                        }

                        y.re = -y.re;
                        y.im = -y.im;
                        jp1 = j;
                        if (ilast + 1 < j + 2) {
                          jp1 = ilast - 1;
                        }

                        for (jm1 = ifrstm; jm1 <= jp1 + 2; jm1++) {
                          anorm = A[(jm1 + A.size(0) * (j - 1)) - 1].im;
                          tempr = A[(jm1 + A.size(0) * (j - 1)) - 1].re;
                          temp2 = A[(jm1 + A.size(0) * j) - 1].re;
                          stemp.re = temp * temp2 + (y.re * tempr - y.im * anorm);
                          stemp.im = temp * A[(jm1 + A.size(0) * j) - 1].im +
                            (y.re * anorm + y.im * tempr);
                          tempr = A[(jm1 + A.size(0) * j) - 1].im;
                          anorm = A[(jm1 + A.size(0) * j) - 1].re;
                          A[(jm1 + A.size(0) * (j - 1)) - 1].re = temp * A[(jm1
                            + A.size(0) * (j - 1)) - 1].re - (y.re * temp2 +
                            y.im * tempr);
                          A[(jm1 + A.size(0) * (j - 1)) - 1].im = temp * A[(jm1
                            + A.size(0) * (j - 1)) - 1].im - (y.re * tempr -
                            y.im * anorm);
                          A[(jm1 + A.size(0) * j) - 1] = stemp;
                        }

                        if (compz) {
                          b_A.set_size(Z.size(0), Z.size(1));
                          jp1 = Z.size(1);
                          for (i = 0; i < jp1; i++) {
                            jm1 = Z.size(0);
                            for (int32_T i1{0}; i1 < jm1; i1++) {
                              b_A[i1 + b_A.size(0) * i] = Z[i1 + Z.size(0) * i];
                            }
                          }

                          for (jm1 = 1; jm1 <= n; jm1++) {
                            anorm = b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].im;
                            tempr = b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].re;
                            temp2 = b_A[(jm1 + b_A.size(0) * j) - 1].re;
                            stemp.re = temp * temp2 + (y.re * tempr - y.im *
                              anorm);
                            y_im_tmp = b_A[(jm1 + b_A.size(0) * j) - 1].im;
                            stemp.im = temp * y_im_tmp + (y.re * anorm + y.im *
                              tempr);
                            b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].re = temp *
                              tempr - (y.re * temp2 + y.im * y_im_tmp);
                            b_A[(jm1 + b_A.size(0) * (j - 1)) - 1].im = temp *
                              anorm - (y.re * y_im_tmp - y.im * temp2);
                            b_A[(jm1 + b_A.size(0) * j) - 1] = stemp;
                          }

                          Z.set_size(b_A.size(0), b_A.size(1));
                          jp1 = b_A.size(1);
                          for (i = 0; i < jp1; i++) {
                            jm1 = b_A.size(0);
                            for (int32_T i1{0}; i1 < jm1; i1++) {
                              Z[i1 + Z.size(0) * i] = b_A[i1 + b_A.size(0) * i];
                            }
                          }
                        }

                        jm1 = j - 1;
                        j++;
                      }
                    }

                    jiter++;
                  }
                }
              } else {
                guard2 = true;
                exitg1 = 1;
              }
            } while (exitg1 == 0);
          } else {
            guard1 = true;
          }

          if (guard2) {
            if (failed) {
              *info = ilast + 1;
              for (jm1 = 0; jm1 <= ilast; jm1++) {
                alpha1[jm1].re = rtNaN;
                alpha1[jm1].im = 0.0;
                beta1[jm1].re = rtNaN;
                beta1[jm1].im = 0.0;
              }

              if (compz) {
                jm1 = Z.size(0);
                jp1 = Z.size(1);
                Z.set_size(jm1, jp1);
                for (i = 0; i < jp1; i++) {
                  for (int32_T i1{0}; i1 < jm1; i1++) {
                    Z[i1 + Z.size(0) * i].re = rtNaN;
                    Z[i1 + Z.size(0) * i].im = 0.0;
                  }
                }
              }
            } else {
              guard1 = true;
            }
          }

          if (guard1) {
            for (j = 0; j <= ilo - 2; j++) {
              alpha1[j] = A[j + A.size(0) * j];
            }
          }
        }
      }
    }
  }
}

// End of code generation (xzhgeqz.cpp)
