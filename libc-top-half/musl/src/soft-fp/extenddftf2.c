/* Software floating-point emulation.
   Return a converted to IEEE quad
   Copyright (C) 1997-2019 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Richard Henderson (rth@cygnus.com) and
		  Jakub Jelinek (jj@ultra.linux.cz).

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   In addition to the permissions in the GNU Lesser General Public
   License, the Free Software Foundation gives you unlimited
   permission to link the compiled version of this file into
   combinations with other programs, and to distribute those
   combinations without any restriction coming from the use of this
   file.  (The Lesser General Public License restrictions do apply in
   other respects; for example, they cover modification of the file,
   and distribution when not linked into a combine executable.)

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#include "fp_extend.h"

#define CRT_HAS_128BIT
#define CRT_LDBL_128BIT

static __inline dst_t __extendXfYf2__(src_t a) {
  // Various constants whose values follow from the type parameters.
  // Any reasonable optimizer will fold and propagate all of these.
  const int srcBits = sizeof(src_t) * CHAR_BIT;
  const int srcExpBits = srcBits - srcSigBits - 1;
  const int srcInfExp = (1 << srcExpBits) - 1;
  const int srcExpBias = srcInfExp >> 1;

  const src_rep_t srcMinNormal = SRC_REP_C(1) << srcSigBits;
  const src_rep_t srcInfinity = (src_rep_t)srcInfExp << srcSigBits;
  const src_rep_t srcSignMask = SRC_REP_C(1) << (srcSigBits + srcExpBits);
  const src_rep_t srcAbsMask = srcSignMask - 1;
  const src_rep_t srcQNaN = SRC_REP_C(1) << (srcSigBits - 1);
  const src_rep_t srcNaNCode = srcQNaN - 1;

  const int dstBits = sizeof(dst_t) * CHAR_BIT;
  const int dstExpBits = dstBits - dstSigBits - 1;
  const int dstInfExp = (1 << dstExpBits) - 1;
  const int dstExpBias = dstInfExp >> 1;

  const dst_rep_t dstMinNormal = DST_REP_C(1) << dstSigBits;

  // Break a into a sign and representation of the absolute value.
  const src_rep_t aRep = srcToRep(a);
  const src_rep_t aAbs = aRep & srcAbsMask;
  const src_rep_t sign = aRep & srcSignMask;
  dst_rep_t absResult;

  // If sizeof(src_rep_t) < sizeof(int), the subtraction result is promoted
  // to (signed) int.  To avoid that, explicitly cast to src_rep_t.
  if ((src_rep_t)(aAbs - srcMinNormal) < srcInfinity - srcMinNormal) {
    // a is a normal number.
    // Extend to the destination type by shifting the significand and
    // exponent into the proper position and rebiasing the exponent.
    absResult = (dst_rep_t)aAbs << (dstSigBits - srcSigBits);
    absResult += (dst_rep_t)(dstExpBias - srcExpBias) << dstSigBits;
  }

  else if (aAbs >= srcInfinity) {
    // a is NaN or infinity.
    // Conjure the result by beginning with infinity, then setting the qNaN
    // bit (if needed) and right-aligning the rest of the trailing NaN
    // payload field.
    absResult = (dst_rep_t)dstInfExp << dstSigBits;
    absResult |= (dst_rep_t)(aAbs & srcQNaN) << (dstSigBits - srcSigBits);
    absResult |= (dst_rep_t)(aAbs & srcNaNCode) << (dstSigBits - srcSigBits);
  }

  else if (aAbs) {
    // a is denormal.
    // renormalize the significand and clear the leading bit, then insert
    // the correct adjusted exponent in the destination type.
    const int scale = src_rep_t_clz(aAbs) - src_rep_t_clz(srcMinNormal);
    absResult = (dst_rep_t)aAbs << (dstSigBits - srcSigBits + scale);
    absResult ^= dstMinNormal;
    const int resultExponent = dstExpBias - srcExpBias - scale + 1;
    absResult |= (dst_rep_t)resultExponent << dstSigBits;
  }

  else {
    // a is zero.
    absResult = 0;
  }

  // Apply the signbit to the absolute value.
  const dst_rep_t result = absResult | (dst_rep_t)sign << (dstBits - srcBits);
  return dstFromRep(result);
}

//===-- lib/extenddftf2.c - double -> quad conversion -------------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#define QUAD_PRECISION
#include "fp_lib.h"

#if defined(CRT_HAS_128BIT) && defined(CRT_LDBL_128BIT)
#define SRC_DOUBLE
#define DST_QUAD


COMPILER_RT_ABI long double __extenddftf2(double a) {
  return __extendXfYf2__(a);
}

#endif
