#pragma once

/**
 * @file alignment.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This is a series of functions that help pair values into a single
 * identifier, or map values onto others.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <cstdint>
#include <cmath>
#include <utility>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::hash
{


/// @brief Map a signed 64-bit integer into an unsigned equivalent.
/// This maps values in an alternating pattern. So you'd have
/// 0 -> 0, -1 -> 1, 1 -> 2, etc.
/// @param x the 64-bit integer
/// @return the unsigned 64-bit integer
inline uint64_t zigzag_encode(int64_t x)
{
    return (static_cast<uint64_t>(x) << 1) 
     ^ static_cast<uint64_t>(x >> 63);
} // end-zigzag_encode


/// @brief Map an unsigned 64-bit integer back into a signed equivalent.
/// @param x 
/// @return 
inline int64_t zigzag_decode(uint64_t x)
{
    return static_cast<int64_t>((x >> 1) ^ (~(x & 1) + 1));
} // end-zigzag_decode


/// @brief Convert a pair of values into their unique Cantor pair.
/// @param x the first variable
/// @param y the second variable
/// @return the cantor pairing value
inline uint64_t cantor(uint64_t x, uint64_t y)
{
    uint64_t s = x + y;
    return (s * (s+1) >> 1) + y;
} // end-cantor


/// @brief Do the inverse of a cantor pairing function to get the 
/// original pair of values
/// @param z the cantor pair value
/// @return an std::pair containing the original values
inline std::pair<uint64_t, uint64_t> cantor_inverse(uint64_t z)
{
    uint64_t w = static_cast<uint64_t>((std::sqrt(8.0*z + 1)-1)/2);
    uint64_t t = (w * (w+1)) >> 1;
    uint64_t y = z - t;
    uint64_t x = w - y;
    return {x, y};
} // end-cantor_inverse


/// @brief Do the inverse of the cantor pairing function to get the
/// original pair of values by reference.
/// @param z the cantor pair value
/// @param x the original x value (set by reference)
/// @param y the original y value (set by reference)
inline void cantor_inverse(uint64_t z, uint64_t &x, uint64_t &y)
{
    uint64_t w = static_cast<uint64_t>((std::sqrt(8.0*z + 1)-1)/2);
    uint64_t t = (w * (w+1)) >> 1;
    y = z - t;
    x = w - y;
} // end-cantor_inverse


/// @brief Convert a pair of signed values into their unique Cantor pair.
/// Cantor pairing typically requires unsigned values, so this invokes
/// zigzag encoding before doing the standard method.
/// @param x the first variable
/// @param y the second variable
/// @return the cantor pairing value
inline uint64_t cantor_signed(int64_t x, int64_t y)
{ return cantor(zigzag_encode(x), zigzag_encode(y)); }


/// @brief Do the inverse of a cantor pairing function to get the 
/// original pair of values (which are zigzag decoded).
/// @param z the cantor pair value
/// @return and std::pair containing the original value
inline std::pair<int64_t, int64_t> cantor_signed_inverse(uint64_t z) 
{
    auto [ux, uy] = cantor_inverse(z);
    return {zigzag_decode(ux), zigzag_decode(uy)};
} // end-cantor_signed_inverse


/// @brief Do the inverse of a cantor pairing function to get the 
/// original pair of values (which are zigzag decoded) by reference.
/// @param z the cantor pair value
/// @param x the original x value (set by reference)
/// @param y the original y value (set by reference)
inline void cantor_signed_inverse(uint64_t z, int64_t &x, int64_t &y)
{
    auto [ux, uy] = cantor_inverse(z);
    x = zigzag_decode(ux);
    y = zigzag_decode(uy);
} // end-cantor_signed_inverse


/// @brief Convert a pair of integers into a unique value by using
/// the elegant pairing function created by Michael Szudzik. This 
/// function is designed to use its value space more efficiently,
/// have less risk of overflow, and run faster.
/// @param x the first variable
/// @param y the second variable
/// @return the szudzik pairing value
inline uint64_t szudzik(uint64_t x, uint64_t y)
{ return (x >= y) ? (x * x + x + y) : (y * y + x); }


/// @brief Do the inverse of the Szudzik pairing to get the original values.
/// @param z the szudzik pairing value
/// @return an std::pair containing the original values
inline std::pair<uint64_t, uint64_t> szudzik_inverse(uint64_t z) {
    uint64_t s = static_cast<uint64_t>(
        std::floor(std::sqrt(static_cast<long double>(z)))
    );
    uint64_t sq = s * s;

    if (z - sq < s) return {z - sq, s};
    return {s, z - sq - s};
} // end-szudzik_inverse


/// @brief Do the inverse of the Szudzik pairing to get the
/// original values by reference.
/// @param z the szudzik pair value
/// @param x the original x value (set by reference)
/// @param y the original y value (set by reference)
inline void szudzik_inverse(uint64_t z, uint64_t &x, uint64_t &y)
{
    uint64_t s = static_cast<uint64_t>(
        std::floor(std::sqrt(static_cast<long double>(z)))
    );
    uint64_t sq = s * s;
    
    if (z - sq < s) 
    {
        x = z - sq;
        y = s;
    }
    else
    {
        x = s;
        y = z - sq - s;
    }
} // end-szudzik_inverse


/// @brief Convert a pair of signed values into their unique Szudzik pair.
/// Szudzik pairing typically requires unsigned values, so this invokes
/// zigzag encoding before doing the standard method.
/// @param x the first variable
/// @param y the second variable
/// @return the szudzik pairing value
inline uint64_t szudzik_signed(int64_t x, int64_t y)
{ return szudzik(zigzag_encode(x), zigzag_encode(y)); }


/// @brief Convert a szudzik value back to the original signed values.
/// @param z the szudzik pairing value
/// @return an std::pair containing the original values
inline std::pair<int64_t, int64_t> szudzik_signed_inverse(uint64_t z)
{
    auto [ux, uy] = szudzik_inverse(z);
    return {zigzag_decode(ux), zigzag_decode(uy) };
} // end-szudzik_signed_inverse


/// @brief Convert a szudzik value back to the original signed values by reference.
/// @param z the szudzik pairing value
/// @param x the original x value (set by reference)
/// @param y the original y value (set by reference)
inline void szudzik_signed_inverse(uint64_t z, int64_t &x, int64_t &y)
{
    auto [ux, uy] = szudzik_inverse(z);
    x = zigzag_decode(ux);
    y = zigzag_decode(uy);
} // end-szudzik_signed_inverse

} // namespace perfkit::hash

// // EOF //////////////////////////////////////////////////////////////////////