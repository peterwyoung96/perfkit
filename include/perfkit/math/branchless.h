#pragma once

/**
 * @file branchless.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This contains a series of branchless versions of functions (i.e. ones
 * that don't require if statements or similar.)
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <string_view>
#include <vector>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::math
{

/// @brief Get the minimum between two values using bit operators to avoid
/// the need for branching if statements. Only use this in cases where:
/// 1) You've got a bottleneck
/// 2) branches are unpredictable
/// 3) you feel like it
/// @tparam T the variable type
/// @param a variable #1
/// @param b variable #2
/// @return the smaller of the two variables
template <typename T>
inline T branchless_min(T a, T b)
{
    return b ^ ((a^b) & -(a < b));
} // end-branchless_min


/// @brief Get the maximum between two values using bit operators to avoid
/// the need for branching if statements. Only use this in cases where:
/// 1) You've got a bottleneck
/// 2) branches are unpredictable
/// 3) you feel like it
/// @tparam T the variable type
/// @param a variable #1
/// @param b variable #2
/// @return the larger of the two variables
template <typename T>
inline T branchless_max(T a, T b)
{
    return a ^ ((a^b) & -(a < b));
} // end-branchless_max


/// @brief Clamp a value between two values.
/// @tparam T the variable type
/// @param x the variable to clamp
/// @param lo the minimum value allowed
/// @param hi the maximum value allowed
/// @return the clamped value
template<typename T>
T branchless_clamp(T x, T lo, T hi) 
{
    return lo + (x - lo) * (x > lo)
              - (x - hi) * (x > hi);
} // end-branchless_clamp


/// @brief Select between two values given a boolean condition.
/// @tparam T the variable type
/// @param c the boolean condition
/// @param a the first choice (if true)
/// @param b the second choice (if false)
/// @return the selected value
template<typename T>
T select_branchless(bool c, T a, T b)
{ return b ^ ((a ^ b) & -T(c)); }

} // namespace perfkit::math

// // EOF //////////////////////////////////////////////////////////////////////