#include "utility.h"

Result result_new_ok(i32 data) {
  Result result;

  result._data = data;
  result._integrity = 0;

  return result;
}

Result result_new_not_ok(i32 integrity) {
  Result result;

  result._data = -1;
  result._integrity = integrity;

  return result;
}

bool result_new_is_valid(Result result) { return !result._integrity; }

i32 result_unwrap(Result result) { return result._data; }

i32 result_integrity(Result result) { return result._integrity; }
