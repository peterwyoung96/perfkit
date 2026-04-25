#pragma once

/**
 * @file masks.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This is a series of bit operations simplified to a more user-friendly
 * interface. These help make flag systems among other things. These relate
 * in particular to masks.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <cstdint>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::bit
{

/// @brief Get the lowest bit.
/// @param x the value to manipulate
/// @return the lowest bit
inline unsigned int lowest_bit(unsigned int x)
{ return x & -x; }


/// @brief Clear the lowest bit.
/// @param x the value to manipulate
/// @return the new resulting value
inline unsigned int clear_lowest_bit(unsigned int x)
{ return x & (x - 1); }


/// @brief Clear the lowest bit and return by reference.
/// @param x the value to manipulate
inline void clear_lowest_bit(unsigned int &x)
{ x &= (x - 1); }


/// @brief Check if the value has exactly one bit set.
/// @param x the value to check
/// @return if the value has exactly one bit set
inline bool has_single_bit(unsigned int x)
{ return x && !(x & (x - 1)); }

} // namespace perfkit::bit

// // EOF //////////////////////////////////////////////////////////////////////