/**
 * @brief URLify
 * A method to replace all spaces in a string with '%20:
 * You may assume that the string has sufficient space at the end to hold the additional characters,
 * and that you are given the "true" length of the string.
 *
 * EXAMPLE Input: "Mr John Smith "J 13 Output: "Mr%20J ohn%20Smith"
 *
 * @file urlify.h
 * @author Tushar Chugh
 */

#include <iostream>
#include <string>

/**
 * @brief replace all spaces in a string with '%20
 * Notes:
 * 1. assumes that the string has sufficient space at the end to hold the additional characters
 * 2. Using iterator
 * 3. Run time complexity:
 * @param url given url with spaces in the end to accomodate the required string
 * @param url_length "true" length of the string.
 */
void urlify( std::string& url, size_t url_length ) noexcept {
    size_t from_index = url_length - 1;
    size_t to_index   = url.length() - 1;

    while ( from_index != to_index ) {
        if ( url[from_index] != ' ' ) {
            url[to_index--] = url[from_index--];
        } else {
            url[to_index--] = '0';
            url[to_index--] = '2';
            url[to_index--] = '%';

            --from_index;
        }
    }
}

/**
 * @brief replace all spaces in a string with '%20
 * Notes:
 * 1. assumes that the string has sufficient space at the end to hold the additional characters
 * 2. Using iterator
 * 3. Run time complexity:
 * @param url given url with spaces in the end to accomodate the required string
 * @param url_length "true" length of the string.
 */
void urlify_iterators( std::string& url, size_t url_length ) noexcept {
    auto from_iter = url.begin() + url_length - 1;
    auto to_iter   = url.end() - 1;

    while ( from_iter != to_iter ) {
        if ( *from_iter != ' ' ) {
            *to_iter-- = *from_iter--;
        } else {
            *to_iter-- = '0';
            *to_iter-- = '2';
            *to_iter-- = '%';

            --from_iter;
        }
    }
}
