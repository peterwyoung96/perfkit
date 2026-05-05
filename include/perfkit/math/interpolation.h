#pragma once

/**
 * @file interpolation.h
 * @date 2026-05-04
 * @author Peter Young
 * 
 * @brief This contains a series of algorithms related to interpolation.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <string_view>
#include <vector>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::math
{

/// @brief Linearly interpolate from value a to b
/// @tparam T the variable type
/// @param a first value
/// @param b second value
/// @param t the step
/// @return the linearly-interpolated value
template <typename T>
inline constexpr T lerp(T a, T b, T t)
{ return a + t * (b - a); }


/// @brief Do the inverse of lerp, i.e. find a value of t
/// such that lerp(a, b, t) = v. This is useful for normalizing
/// onto a range of [0,1].
/// @tparam T 
/// @param a first value
/// @param b second value
/// @param v the interpolated value
/// @return the value of t such that lerp(a, b, t) = v
template <typename T>
inline constexpr T inv_lerp(T a, T b, T v)
{ return (v - a ) / (b - a);}


/// @brief Map a value that is in the range [in_min, in_max]
/// to a new value in the range [out_min, out_max].
/// @tparam T the variable type
/// @param in_min the minimum value in the input range
/// @param in_max the maximum value in the input range
/// @param out_min the minimum value in the output range
/// @param out_max the maximum value in the output range
/// @param v the value to remap
/// @return the remapped value
template <typename T>
inline constexpr T remap(T in_min, T in_max, T out_min, T out_max, T v)
{ return lerp(out_min, out_max, inv_lerp(in_min, in_max, v)); }

} // namespace perfkit::math

// // EOF //////////////////////////////////////////////////////////////////////