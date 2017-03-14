/*******************************************************************************
 * Split
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * This class is used to help process command strings, by splitting into 
 * usable parts, and placing the parts into a vector.  
 ******************************************************************************/
#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <vector>

/*
 * Split a string into a vector of strings based on a delimiter.
 *
 * The delimiter is not included in any of the strings in the vector.
 */
std::vector<std::string> split(const std::string& line, const std::string& delim);

#endif //SPLIT_H