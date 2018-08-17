// ITP 365 Fall 2017
// HW2 – itpPhone
// Name: Hope Kim
// Email: hopekim@usc.edu
// Platform: Mac
//
// PhoneSystem.cpp
// Implements PhoneSystem class
//

#include "PhoneSystem.h"
#include <fstream>

// Function: Constructor
// Purpose: Constructs two maps --
//          (1) area codes -> locations
//              (loaded from areacodes.txt)
//          (2) phone numbers -> contacts
//              (loaded from contacts.txt)
// Input: None
// Output: None
PhoneSystem::PhoneSystem()
{
    // TODO: Implement
    std::ifstream fileInputCodes("areacodes.txt");
    if (fileInputCodes.is_open())
    {
        // TODO: Do stuff with the file
        while (!fileInputCodes.eof())
        {
            // Grab each line
            std::string line;
            std::getline(fileInputCodes, line);
            // Make sure the line's format is valid
                // Use substr to get first 3 characters
                std::string key = line.substr(0, 3);
                // Get characters from 4 onwards
                std::string value = line.substr(4);
                // Add to map
                areaCodes.put(key, value);
        }
    }
    else
    {
        error("File not found :(");
    }
    
    std::ifstream fileInputContacts("contacts.txt");
    if (fileInputContacts.is_open())
    {
        // TODO: Do stuff with the file
        while (!fileInputContacts.eof())
        {
            // Grab each line
            std::string line;
            std::getline(fileInputContacts, line);
            // Make sure the line's format is valid
                // Use substr to get first 12 characters
                std::string key = line.substr(0, 12);
                // Get characters from 13 onwards
                std::string value = line.substr(13);
                // Add to map
                phoneNumbers.put(key, value);
        }
    }
    else
    {
        error("File not found :(");
    }
}
    // Function: addDigit
    // Purpose: Called when the user adds a digit
    //          to the current phone number
    // Input: Digit to add (to the end of the number)
    // Output: None
    void PhoneSystem::addDigit(char digit)
    {
        // TODO: Implement
        if (phoneNumber.length() < 3)
        {
            phoneNumber += digit;
        }
        else if (phoneNumber.length() == 3)
        {
            phoneNumber = phoneNumber + '-' + digit;
        }
        else if (phoneNumber.length() >= 4 && phoneNumber.length() < 7)
        {
            phoneNumber += digit;
        }
        else if (phoneNumber.length() == 7)
        {
            phoneNumber = phoneNumber + '-' + digit;
        }
        else if (phoneNumber.length() >= 8 && phoneNumber.length() < 12)
        {
            phoneNumber += digit;
        }
    }
    
    // Function: backspace
    // Purpose: Removes the rightmost digit from the number
    // Input: None
    // Output: None
    void PhoneSystem::backspace()
    {
        // TODO: Implement
        if (phoneNumber.length() <= 12 && phoneNumber.length() >= 10)
        {
            phoneNumber.pop_back();
        }
        else if (phoneNumber.length() == 9)
        {
            for (int i = 0; i < 2; i ++)
            {
                phoneNumber.pop_back();
            }
        }
        else if (phoneNumber.length() > 5 && phoneNumber.length() < 9)
        {
            phoneNumber.pop_back();
        }
        else if (phoneNumber.length() == 5)
        {
            for (int i = 0; i < 2; i ++)
            {
                phoneNumber.pop_back();
            }
        }
        else if (phoneNumber.length() < 4 && phoneNumber.length() > 0)
        {
           phoneNumber.pop_back();
        }
    }
    
    // Function: getNumber
    // Purpose: Returns the current number the user has dialed
    // Input: None
    // Output: Current number user has dialed
    std::string PhoneSystem::getNumber()
    {
        // TODO: Implement
        return phoneNumber; // FIX TO RETURN CORRECT VALUE
    }
    
    // Function: lookupNumber
    // Purpose: Looks up the current number in the two maps:
    //          (1) First checks if this number is a contact

    //          (2) Otherwise, checks if the first three digits
    //              are a known area code
    // Input: None
    // Output: Returns a string that contains either:
    //         (a) The name of the contact
    //         (b) The location of the area code
    //         (c) "UNKNOWN" if it's neither a contact nor
    //             contains a valid area code
    std::string PhoneSystem::lookupNumber()
    {
        // TODO: Implement
        std::string areaCode = phoneNumber.substr(0,3);
        if (phoneNumbers.containsKey(phoneNumber) == true)
        {
            return phoneNumbers.get(phoneNumber);
        }
        else if (areaCodes.containsKey(areaCode))
        {
            return areaCodes.get(areaCode);
        }
        else
        {
        return "UNKNOWN";
        }
    }
