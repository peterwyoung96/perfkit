#pragma once

/**
 * @file branchless.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This contains a series of approximations of common functions that
 * are faster than the actual analytical solution.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <perfkit/math/fast_math.h>
#include <cmath>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::math
{

/// @brief A "Quake Arena"-style fast inverse square root (approximate only)
/// @param x the value to root
/// @return the inverse square root
inline float fast_inv_sqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float*)&i;
    return x * (1.5f - xhalf * x * x);
} // end-fast_inv_sqrt


/// @brief A fast version of the square root (approximate only)
/// @param x the value to root
/// @return the square root
inline float fast_sqrt(float x)
{ return x * fast_inv_sqrt(x); }


/// @brief A fast version of the sine function
/// @param x 
/// @param useStdAbs a flag for using std::abs. By default,
/// this algorithm uses the fast_abs defined in fast_math.h.
/// @return 
inline float fast_sin(float x, bool useStdAbs = false)
{
    const float B = 4 / 3.14159265f;
    const float C = -4 / (3.14159265f * 3.14159265f);

    if (useStdAbs) return B * x + C * x * std::abs(x);
    float y = B * x + C * x * fast_abs(x);
    return y;
}

} // namespace perfkit::math

// // EOF //////////////////////////////////////////////////////////////////////