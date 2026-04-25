#pragma once

/**
 * @file ops.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This is a series of bit operations simplified to a more user-friendly
 * interface. These help make flag systems among other things. This relates
 * specifically to bit operations.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <cstdint>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::bit
{

/// @brief Check to see if the number contains the appropriate bit.
/// @param x the integer to check
/// @param i the bit to check
/// @return a flag indicating whether the bit was set
inline bool test_bit(unsigned int x, unsigned int i)
{ return x & (1u << i); }


/// @brief Set a particular bit.
/// @param x the original value
/// @param i the bit to set
/// @return the new resulting value
inline unsigned int set_bit(unsigned int x, unsigned int i)
{ return x | (1u << i); }


/// @brief Set a particular bit and return by reference.
/// @param x the original value
/// @param i the bit to set
inline void set_bit(unsigned int &x, unsigned int i)
{ x |= (1u << i); }


/// @brief Clear a particular bit.
/// @param x the original value
/// @param i the bit to clear
/// @return the new resulting value
inline unsigned int clear_bit(unsigned int x, unsigned int i)
{ return x & ~(1u << i); }


/// @brief Clear a particular bit and return by reference.
/// @param x the original value
/// @param i the bit to clear
inline void clear_bit(unsigned int &x, unsigned int i)
{ x &= ~(1u << i); }


/// @brief Toggle a particular bit (to its opposite value).
/// @param x the original value
/// @param i the bit to clear
/// @return the new resulting value
inline unsigned int toggle_bit(unsigned int x, unsigned int i)
{ return x ^ (1u << i); }


/// @brief Toggle a particular bit and return by reference.
/// @param x the original value
/// @param i the bit to clear
inline void toggle_bit(unsigned int &x, unsigned int i)
{ x ^= (1u << i); }


/// @brief Count the number of bits set in a number (Kernighan's Algorithm)
/// @param x the number to check
/// @return the number of set bits in the value
inline int count_set_bits(unsigned int x)
{
    int count = 0;
    while (x)
    {
        x &= (x - 1);
        ++count;
    }
    return count;
}


/// @brief Rotate the bits of a number by N places to the left.
/// Bits that fall off the edge are put onto the right edge.
/// @param x the value to rotate
/// @param n the number of places to rotate
/// @return the rotated value
inline uint32_t rotate_bits_left(uint32_t x, int n)
{ return (x << n) | (x >> (32 - n)); }


/// @brief Rotate the bits of a number by N places to the right.
/// Bits that fall off the edge are put onto the left edge.
/// @param x the value to rotate
/// @param n the number of places to rotate
/// @return the rotated value
inline uint32_t rotate_bits_left(uint32_t x, int n)
{ return (x >> n) | (x << (32 - n)); }

} // namespace perfkit::bit

// // EOF //////////////////////////////////////////////////////////////////////