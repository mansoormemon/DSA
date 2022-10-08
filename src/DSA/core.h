#ifndef DSA_CORE_H_
#define DSA_CORE_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define _Unused(param) (void)(param)

#define _TMalloc(type) (type *)malloc(sizeof(type))

#define _Cast(var, dtype) (dtype)(var)

#define _AlphaBool(val) val ? "true" : "false"

#define nil NULL

typedef uint8_t u8;

typedef uint16_t u16;

typedef uint32_t u32;

typedef uint64_t u64;

typedef int8_t i8;

typedef int16_t i16;

typedef int32_t i32;

typedef int64_t i64;

typedef size_t usize;

typedef ptrdiff_t isize;

typedef float f32;

typedef double f64;

#endif
