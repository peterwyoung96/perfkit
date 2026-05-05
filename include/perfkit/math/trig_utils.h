#pragma once

/**
 * @file trig_utils.h
 * @date 2026-05-04
 * @author Peter Young
 * 
 * @brief This contains a series of algorithms related to trigonometry.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <string_view>
#include <vector>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::math
{

/// @brief A template-safe version of PI
/// @tparam T 
template <typename T>
constexpr T PI = T(3.14159265358979323846);

/// @brief A template-safe version of 2*pi
/// @tparam T 
template <typename T>
constexpr T TWO_PI = T(6.28318530717958647692);

/// @brief A template-safe version of 1/(2*pi)
/// @tparam T 
template <typename T>
constexpr T INV_TWO_PI = T(0.15915494309189533577); 


/// @brief Normalize an angle to [0, 2*pi)
/// @tparam T the variable type
/// @param angle_radians the angle in radians 
/// @return the normalized angle
template <typename T>
inline T normalize_2pi(T angle_radians)
{
    angle_radians = std::fmod(angle_radians, TWO_PI<T>);
    if (angle_radians < T(0)) angle_radians += TWO_PI<T>;
    return angle_radians;
} // end-normalize_2pi


/// @brief Normalize an angle to [-pi, pi]
/// @tparam T the variable type
/// @param angle_radians the angle in radians 
/// @return the normalized angle
template <typename T>
inline T normalize_pi(T angle_radians)
{
    // First, make sure to wrap to [0, 2*pi)
    angle_radians = normalize_2pi<T>(angle_radians);

    // Second, shift to [-pi, pi]
    if (angle_radians > PI<T>) angle_radians -= TWO_PI<T>;

    return angle_radians;
} // end-normalize_2pi


/// @brief Convert an angle in degrees into radians
/// @tparam T the variable type
/// @param deg the angle in degrees
/// @return the angle in radians
template <typename T>
inline constexpr T deg_to_rad(T deg)
{ return deg * (PI<T> / T(180)); }


/// @brief Convert an angle in radians to degrees
/// @tparam T the variable type
/// @param rad the angle in radians
/// @return the angle in degrees
template <typename T>
inline constexpr T rad_to_deg(T rad)
{ return rad * (T(180) / PI<T>); }

} // namespace perfkit::math

// // EOF //////////////////////////////////////////////////////////////////////