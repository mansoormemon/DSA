#ifndef DSA_UTILITY_H_
#define DSA_UTILITY_H_

#include "core.h"

typedef struct Result {
  i32 _data;
  i32 _integrity;
} Result;

Result result_new_ok(i32 data);

Result result_new_not_ok(i32 integrity);

bool result_is_ok(Result result);

i32 result_unwrap(Result result);

i32 result_integrity(Result result);

#endif
