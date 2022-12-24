// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu

// Date: Dec. 23, 2022
// shifts the elements in a list x times in a specified direction


#include <iostream>
#include <list>

std::list<std::string> ShiftLeft(std::list<std::string> userList, int shift) {
    // variables
    std::string prevElement;

    // actually shifts the list
    for (int counter = 0; counter < shift; counter++) {
        prevElement = userList.back();
        userList.push_front(prevElement);
        userList.pop_back();
    }

    return userList;
}

int main() {
    // variables
    std::list<std::string> listOfInput, finalList;
    std::string userInput, shiftStr, displayList;
    bool goAgain;
    int shiftInt;

    do {
        // populating list
        do {
            // asking for user input
            std::cout << "Enter a number you want in your list (/q to quit): ";
            std::cin >> userInput;

            listOfInput.push_back(userInput);
        } while (userInput != "/q");
        listOfInput.remove("/q");

        // asks user how many times to shift the elements
        std::cout << "How many times do you want to shift the elements in the list? ";
        std::cin >> shiftStr;

        // exception handling
        try {
            shiftInt = stoi(shiftStr);

        // user input is not an int
        } catch (std::invalid_argument) {
            std::cout << "Please make sure your input is an integer." << std::endl;
            break;
        }

        // calls function to shift values in the list
        finalList = ShiftLeft(listOfInput, shiftInt);

        // final displayed message
        std::cout << "The list shifted " << shiftInt << " elements to the left is [";
        for (std::string element : finalList) {
            displayList += element + ", ";
        }
        displayList.pop_back();
        displayList.pop_back();
        std::cout << displayList << "]." << std::endl << std::endl;
    } while (false);
}
