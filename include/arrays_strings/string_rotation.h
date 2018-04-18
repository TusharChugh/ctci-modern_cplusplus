/**
 * @brief String Rotation
 * Assume you have a method isSubstring which checks if one word is a substring of another. Given
 * two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one call to
 * isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
 *
 * @file string_rotation.h
 * @author Tushar Chugh
 */

#include <string>

namespace algorithm {

bool is_substring( const std::string& input, const std::string& sub ) noexcept {
    return std::string::npos != input.find( sub );
}

bool is_rotation( const std::string& s1, const std::string& s2 ) {
    if ( ( s1.length() != s2.length() ) || s1.empty() ) return false;

    std::string concatenated = s1 + s2;
    return is_substring( concatenated, s2 );
}
} // namespace algorithm