#ifndef WELLORDERED_HPP
#define WELLORDERED_HPP

/*
WellOrdered Header

File: WellOrdered.hpp
Author: Brett Koenig
School: UW-Whitewater
Email: brettkoenig@hotmail.com
Description: Contains the WellOrdered function declarations.

Compatability: Tested on a Windows system using C++17.

*/

#include <string> // std::string
#include <fstream> // std::ofstream

namespace WellOrdered {
	// Writes all permutations of a well-ordered string.
	// Input: size of well-ordered string.
	// Output: total permutation count.
	int PrintWellOrdered(int size);

	// Gets the maximum well-ordered string in ascending ascii value.
	// Input: size of well-ordered string.
	// Output: max well-ordered string in ascending ascii value.
	std::string GetMaxWellOrderedString(int size);

	// Initializes a well-ordered string.
	// Input: empty string to be initialized, length of desired well-ordered string.
	// Output: void (string modified through reference).
	void InitializeWellOrderedString(std::string& str, int length);
}

#endif