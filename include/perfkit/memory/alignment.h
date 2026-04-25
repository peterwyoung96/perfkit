#pragma once

/**
 * @file alignment.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief This is a series of memory options simplified to a more user-friendly
 * interface. These help make flag systems among other things. These relate
 * in particular to aligning variables to the next option.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <cstddef>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::memory
{

/// @brief Round up to the nearest multiple of a number.
/// NOTE: 'align' must be a power of two to work properly.
/// (This is used more memory purposes like ensuring sizes
/// meet hardware requirements.)
/// @param x the variable to align
/// @param align the alignment value
/// @return the newly aligned value
inline std::size_t align_up(std::size_t x, std::size_t align) 
{ return (x + align - 1) & ~(align - 1); }

/// @brief Round down to the nearest multiple of a number.
/// NOTE: 'align' must be a power of two to work properly.
/// (This is used more memory purposes like ensuring sizes
/// meet hardware requirements.)
/// @param x the variable to align
/// @param align the alignment value
/// @return the newly aligned value
inline std::size_t align_down(std::size_t x, std::size_t align) 
{ return x & ~(align - 1); }

} // namespace perfkit::memory

// // EOF //////////////////////////////////////////////////////////////////////