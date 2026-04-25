#pragma once

/**
 * @file swap.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This is a series of bit operations simplified to a more user-friendly
 * interface. These help make flag systems among other things. These relate
 * in particular to swapping variables.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::bit
{

/// @brief Swap two integers using XOR.
/// NOTE: Do NOT use this method in place of std::swap.
/// This is just one that i find interesting.
/// @param a variable #1
/// @param b variable #2
inline void xor_swap(int &a, int &b)
{
    if (&a == &b) return;
    a ^= b;
    b ^= a;
    a ^= b;
} // end-xor_swap

} // namespace perfkit::bit

// // EOF //////////////////////////////////////////////////////////////////////