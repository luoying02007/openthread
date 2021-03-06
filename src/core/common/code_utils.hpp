/*
 *  Copyright (c) 2016, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file includes macros for validating runtime conditions.
 */

#ifndef CODE_UTILS_HPP_
#define CODE_UTILS_HPP_

#include <stdbool.h>

// Calculates the aligned variable size.
#define otALIGNED_VAR_SIZE(size, align_type)            \
    (((size) + (sizeof (align_type) - 1)) / sizeof (align_type))

// Allocate the structure using "raw" storage.
#define otDEFINE_ALIGNED_VAR(name, size, align_type)            \
    align_type name[(((size) + (sizeof (align_type) - 1)) / sizeof (align_type))]

/* Check the input `ERR` against zero and go to `exit` label if it is non-zero. */
#define SuccessOrExit(ERR)                      \
  do {                                          \
    if ((ERR) != 0) {                           \
      goto exit;                                \
    }                                           \
  } while (false)

/* Verify that the `COND` is true, otherwise go to `exit` label. */
#define VerifyOrExit(COND, ACTION)              \
  do {                                          \
    if (!(COND)) {                              \
      ACTION;                                   \
      goto exit;                                \
    }                                           \
  } while (false)

/* Run the passed in statement(s) and go to `exit` label. */
#define ExitNow(...)                            \
  do {                                          \
    __VA_ARGS__;                                \
    goto exit;                                  \
  } while (false)

/*
 * Run the `statement` and ignore the return value.
 *
 * This is primarily used to indicate the intention of developer that the return value of function/method can be
 * safely ignored.
 *
 */
#define IgnoreReturnValue(statement)           \
  do {                                         \
    if (statement) {}                          \
  } while (false)


#endif  // CODE_UTILS_HPP_
