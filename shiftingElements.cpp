// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu

// Date: Dec. 23, 2022
// shifts the elements in a list x times in a specified direction


#include <iostream>
#include <list>

// function to shift the elements of the lit to the right
std::list<std::string> ShiftRight(std::list<std::string> userList, int shift) {
    // variables
    std::string firstElement;

    // shifts the list to the right
    for (int counter = 0; counter < shift; counter++) {
        firstElement = userList.front();
        userList.push_back(firstElement);
        userList.pop_front();
    }

    return userList;
}


// function to shift the elements of the lit to the left
std::list<std::string> ShiftLeft(std::list<std::string> userList, int shift) {
    // variables
    std::string prevElement;

    // shifts the list to the left
    for (int counter = 0; counter < shift; counter++) {
        prevElement = userList.back();
        userList.push_front(prevElement);
        userList.pop_back();
    }

    return userList;
}


// function to display the start message
void StartMessage() {
    std::cout << "Hello and thank you for using this program!" << std::endl
              << "In this program, you will be entering values"
              << " to add into a list, then the" << std::endl
              << "elements (the values) will shift"
              << "to the left x amount of times." << std::endl
              << "Example:" << std::endl
              << "Enter a number(/ q to quit) : 3" << std::endl
              << "Enter a number (/q to quit): abc" << std::endl
              << "Enter a number (/q to quit): 1.1" << std::endl
              << "Enter a number (/q to quit): /q" << std::endl
              << "Here is your list: [3, abc, 1.1]" << std::endl
              << "How many elements to the left do you want to shift this list? 2"
              << std::endl
              << "Your list shifted 2 elements to the left is [abc, 1.1, 3]"
              << std::endl << std::endl;
}


int main() {
    // variables
    std::list<std::string> listOfInput, finalList;
    std::string userInput, shiftStr, displayList, direction;
    bool goAgain;
    int shiftInt;

    // displays the start message
    StartMessage();

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

        // asks the user which way to shift the elements
        std::cout << "Which way do you want to shift the list (l for left or r for right)? ";
        std::cin >> direction;

        // user wants to shift to the left
        if (direction == "l") {
            finalList = ShiftLeft(listOfInput, shiftInt);

        // user wants to shift to the right
        } else if (direction == "r") {
            finalList = ShiftRight(listOfInput, shiftInt);

        // user input is invalid
        } else {
            std::cout << "Please enter either l or r.";
            break;
        }

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
