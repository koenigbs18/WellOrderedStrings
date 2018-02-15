/*
Sample Main Function

File: main.cpp
Author: Brett Koenig
School: UW-Whitewater
Email: brettkoenig@hotmail.com
Description: Shows example usage of WellOrdered functions in "WellOrdered.hpp"

Compatability: Tested on a Windows system using C++17.

*/

#include <string> // std::string
#include <iostream> // std::cin, std::cout

#include "WellOrdered.hpp"

// Sample main function
int main() {
	// Get user input to initialize string dynamically based on the size
	std::cout << "Enter size of string: ";
	int sz = 0;
	std::cin >> sz;
	// Ensure user input is valid.
	while (std::cin.fail() || sz < 1 || sz > 58) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << "\nPlease enter a proper value!";

		std::cout << "\nEnter size of string: ";
		std::cin >> sz;
	}

	// Initialize well-ordered string based on user input size
	std::string init = "";
	WellOrdered::InitializeWellOrderedString(init, sz);

	// Print strings for debugging purposes
	std::cout << "\nInitialized String: " << init;
	std::cout << "\nMax string: " << WellOrdered::GetMaxWellOrderedString(sz);

	// Call algorithm
	int count = WellOrdered::PrintWellOrdered(sz);

	// Print results
	std::cout <<"\nTotal Strings: " << count;
	std::cout << "\n\nWrote strings to file \"WellOrderedStrings.txt\".";
	std::cout << "\nEnter anything to exit...";
	std::cin >> sz;
	std::cin.ignore();

	return 0;
}