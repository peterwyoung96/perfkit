#pragma once

/**
 * @file fastmath.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This is a series of math operations that have been optimized by a 
 * series of bit operations. Some of these might not be useful with modern
 * compilers already being optimized, but I still think they're neat tricks.
 */

// // HEADERS //////////////////////////////////////////////////////////////////


// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::math
{

/// @brief Check if a number is even.
/// @param x the integer to check
/// @return if the integer is even
inline bool is_even(int x) { return (x & 1) == 0; }

/// @brief Check if a number if odd.
/// @param x the integer to check
/// @return if the integer is odd
inline bool is_odd(int x) { return (x & 1) != 0; }


/// @brief Check if a number is a power of two.
/// @tparam T the variable type
/// @param x the value to check
/// @return if the number is a power of two
template <typename T>
inline bool is_power_of_two(T x)
{
    return x > 0 && (x & (x-1)) == 0;
} // end-is_power_of_two


/// @brief Get the next power of two above the given value
/// @tparam T the variable type
/// @param x the value to check 
/// @return the next largest power of two
template <typename T>
inline T next_power_of_two(T x)
{
    if (x <= 1) return 1;
    --x;
    for (size_t i = 1; i < sizeof(T) * 8; i <<= 1)
        x |= x >> i;
    return x + 1;
} // end-next_power_of_two


/// @brief Branchless fast version of abs for integers
/// @param x the integer
/// @return the absolute value of the variable
inline int fast_abs(int x)
{
    int mask = x >> (sizeof(int) * 8 - 1);
    return (x + mask) ^ mask;
} // end-fast_abs


/// @brief Get the sign of an integer
/// @param x the signed integer
/// @return the sign of the integer
inline int sign(int x) { return (x > 0) - (x < 0); } 

} // namespace perfkit::math

// // EOF //////////////////////////////////////////////////////////////////////