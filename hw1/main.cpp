// Name: Hope Kim
// Email: hopekim@usc.edu
// ITP 365, Fall 2017
// HW1 – Sieve of Eratosthenes
// Platform: Mac


#include <string>
#include <iostream>
#include <fstream>
#include "map.h"
class PhoneSystem
{
public:
    // Function: Constructor
    // Purpose: Constructs two maps --
    // (1) area codes -> locations
    // (loaded from areacodes.txt)
    // (2) phone numbers -> contacts
    // (loaded from contacts.txt)
    // Input: None
    // Output: None
    PhoneSystem();
private:
    // TODO: Add member variables here
    Map<std::string, std::string> areaCodes;
    Map<std::string, std::string> phoneNumbers;
    std::string phoneNumber;
};
PhoneSystem::PhoneSystem()
{
    // inputs file
    std::ifstream file(areacodes.txt);

    // validates files
    if (file.is_open()) {
        while (!file.eof()) {
            // Grab each line
            std::string line;
            std::getline(file, line);
            // Make sure the line's format is valid
            if (line.length() <= 4 && line[3] != '=') {
                error("Invalid data in file " + fileName);
            } else {
                // Use substr to get first 3 characters
                std::string key = line.substr(0, 3); // Get characters from 4 onwards
                std::string value = line.substr(4); // Add to map
                airports[key] = value; }
        }
    } else {
        error("Failure to load file");
    }
}
