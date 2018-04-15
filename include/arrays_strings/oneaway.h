/**
 * @brief One Away
 * There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit (or zero edits) away.
 * EXAMPLE pale, pIe -> true pales. pale -> true pale. bale -> true pale. bake -> false
 *
 * @file oneaway.h
 * @author Tushar Chugh
 */

#include <assert.h>
#include <string>

namespace algorithm {

/**
 * @brief checks if inserting one character to the first string can make it same as second
 *
 * @param first string of length one less than second
 * @param second string of length one more than first
 * @return true
 * @return false
 */
bool one_edit_insert( const std::string& first, const std::string& second ) {
    size_t index_first  = 0;
    size_t index_second = 0;

    while ( index_second < second.length() && index_first < first.length() ) {
        if ( first.at( index_first ) == second.at( index_second ) ) {
            ++index_first;
            ++index_second;
        } else {
            if ( index_first != index_second ) return false;
            ++index_second;
        }
    }
    return true;
}

/**
 * @brief checks if first string can be equal to second by just replacing one characted
 *
 * @param first first string
 * @param second second string
 * @return true
 * @return false
 */
bool one_edit_replace( const std::string& first, const std::string& second ) {
    assert( first.length() == second.length() );

    bool seen_replacement = false;

    for ( size_t i = 0; i < first.length(); ++i ) {
        if ( first.at( i ) != second.at( i ) ) {
            if ( seen_replacement ) return false;
            seen_replacement = true;
        }
    }
    return true;
}

/**
 * @brief Checks if two given strings are one edit away
 *
 * @param first first string
 * @param second second string
 * @return true if inputs are one edit away
 * @return false if inputs are not ine edit away
 */
bool one_edit_away( const std::string& first, const std::string& second ) {
    if ( first.length() == second.length() )
        return one_edit_replace( first, second );
    else if ( first.length() + 1 == second.length() )
        return one_edit_insert( first, second );
    else if ( first.length() - 1 == second.length() )
        return one_edit_insert( second, first );
    return false;
}
} // namespace algorithm