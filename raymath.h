/*
   Changes made (logged here):
   - Removed malformed/partial code (including an accidental `main()` and stray stream writes).
   - Added compact, safe implementations of the vector math helpers
     used by `main.cpp` to reduce compile-time errors.
   - All removed lines were either broken fragments or duplicative
     code that conflicted with `main.cpp` definitions.

   Notes:
   - These helpers are light-weight and defined `static inline`
     so they won't add link-time requirements.
   - If you use the real raylib/rlgl, prefer the original raymath module.
*/

#ifndef SKYPROC_RAYMATH_H
#define SKYPROC_RAYMATH_H

#include <cmath>
#include "raylib.h"

static inline float Clamp(float v, float lo, float hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}

static inline Vector3 Vector3Add(Vector3 a, Vector3 b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}
static inline Vector3 Vector3Subtract(Vector3 a, Vector3 b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
static inline Vector3 Vector3Scale(Vector3 v, float s) {
    return {v.x * s, v.y * s, v.z * s};
}
static inline float Vector3Length(Vector3 v) {
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
static inline Vector3 Vector3Normalize(Vector3 v) {
    float L = Vector3Length(v);
    if (L == 0.0f) return {0.0f, 0.0f, 0.0f};
    return Vector3Scale(v, 1.0f / L);
}
static inline float Vector3Distance(Vector3 a, Vector3 b) {
    return Vector3Length(Vector3Subtract(a, b));
}
static inline Vector3 Vector3CrossProduct(Vector3 a, Vector3 b) {
    return {a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z,
            a.x * b.y - a.y * b.x};
}

#endif // SKYPROC_RAYMATH_H
