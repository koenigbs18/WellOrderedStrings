/*
Printing Well-Ordered Strings

File: WellOrdered.cpp
Author: Brett Koenig
School: UW-Whitewater
Email: brettkoenig@hotmail.com
Description: A well ordered string is defined as a string sorted ascendingly by its ASCII value
	     This program prints all possible permutations of well ordered strings of given length.
	     Example: ACDEF, ACDEG... ACDyz, ACEFG, ACEFH...
	     Note: This includes all characters between ASCII values 65-122 or 'A' to 'z' (58 elements)

Usage: Input any number of digits between 1-58.  The permutated strings and the total strings
       will be output to a text file "WellOrderedStrings.txt" in the working directory.

Compatibility: Tested on a Windows system using C++17.

*/

#include "WellOrdered.hpp"

namespace WellOrdered {

	/*
	Function: PrintWellOrdered

	Desc: Calculates all permutations of a well-ordered string initialized as 'ABC...'
	      based on the passed size.

	Pre: The function requires the size of the well-ordered string to be passed.

	Post: The function will return the number of permutations 
	      and write all permutations and total permutation count to
	      a file named "WellOrderedStrings.txt" in the working directory.
	*/
	int PrintWellOrdered(int size) {
		// Open file for writing strings
		std::ofstream file;
		file.open("WellOrderedStrings.txt");
		// Permutation counter
		int stringCount = 0;
		// Initialize string dynamically based on passed size
		std::string str = "";
		InitializeWellOrderedString(str, size);
		int index = size - 1;

		file << str << "\n";
		stringCount++;

		// Well ordered algorithm
		while (str != GetMaxWellOrderedString(size)) { // Loop until we have reached our final string

			// Max size case
			if (index == str.size() - 1) {
				// For our max case, we only need to check if the character is the max possible ascii 'z'
				while (str.at(index) != 'z') {
					str.at(index)++; // increment until the character is 'z'

					file << str << "\n";
					stringCount++;
				}
				index--; // decrement our index
				continue;
			}

			// 0 index case
			if (index == 0) {
				str.at(0)++; // increment our character at index 0
				for (int i = 1; i < size; i++)
					str.at(i) = str.at(i - 1) + 1; // dynamically reset our string

				file << str << "\n";
				stringCount++;

				index = size - 1; // reset our index to the max size (-1 to play nice)
				continue;
			}

			// third case, everything inbetween index 0 and max size
			if (str.at(index) != 122 - str.size() + index + 1) {  // dynamically calculates the max character at the given index and size
				str.at(index)++; // increment our character at the current index
				for (int i = index + 1; i < size; i++)
					str.at(i) = str.at(i - 1) + 1; // dynamically reset our string

				file << str << "\n";
				stringCount++;

				index = size - 1; // reset our index to the max size (-1 to play nice)
				continue;
			}

			// When we reach the max character of index's between 0 & max, we want to move down an index
			index--;
		}
		file << "Total Strings: " << stringCount;
		file.close();
		return stringCount;
	}

	/*
	Function: GetMaxWellOrderedString

	Desc: Calculates the maximum (highest ascii values, ascending) well-ordered
	      string given the passed length.

	Pre: The function must be passed the size of the well-ordered string.

	Post: The function returns the maximum well-ordered string.
	*/
	std::string GetMaxWellOrderedString(int size) {
		std::string maxstr = "";
		for (int i = 123 - size; i < 123; i++) {
			maxstr.push_back((char)i);
		}
		return maxstr;
	}

	/*
	Function: InitializeWellOrderedString

	Desc: Initializes a well-ordered string.

	Pre: The function is passed a string to be initialized, and the length 
	     of the desired well-ordered string.

	Post: void (string modified through reference).
	*/
	void InitializeWellOrderedString(std::string& str, int length)
	{
		str.clear();
		for (int i = 0; i < length; i++)
		{
			str.push_back(65 + i);
		}
	}
}
