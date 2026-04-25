#pragma once

/**
 * @file fast_split.h
 * @date 2026-04-23
 * @author Peter Young
 * 
 * @brief std::stringstream is slow for a lot of situations. This folder contains
 * useful methods that split strings faster than std::stringstream will.
 */

// // HEADERS //////////////////////////////////////////////////////////////////

#include <string_view>
#include <vector>

// // NAMESPACE ////////////////////////////////////////////////////////////////

namespace perfkit::string
{

    
/// @brief Split a string based on a delimiter - fast edition.
/// @param str the string to split
/// @param delim the delimiter character
/// @return a vector containing the string's components
inline std::vector<std::string_view> fast_split(
    std::string_view str, 
    char delim)
{
    std::vector<std::string_view> result;
    size_t start = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == delim) 
        {
            result.emplace_back(str.substr(start, i-start));
            start = i + 1;
        } // end-if
    } // end-for

    result.emplace_back(str.substr(start));
    return result;

} // end-fast_split


} // namespace perfkit::string

// // EOF //////////////////////////////////////////////////////////////////////