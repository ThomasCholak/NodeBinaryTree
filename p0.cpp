// Thomas Cholak

#include "tree.h"
#include <string>

#include <iostream>
#include <fstream>

// 'main' accepts file arguments in case user redirects a file into the program
int main(int argc, char* argv[])
{
    std::ifstream inFile;

    // error if more than one file is provided
    if (argc > 2)
    {
        // more than one argument provided
        std::cerr << "Error: Please only input one File.\n";
        return 1; //exits program due to error
    }
    // processes file if only one argument is provided
    else if (argc == 2)
    {
        // looks for if a file is present in Linux
        inFile.open(argv[1]);

        // error validation if file couldn't be opened
        if (!inFile.is_open())
        {
            std::cerr << "Error! Could not open File: " << argv[1] << std::endl;
            return 1;
        }
    }

    // initialize empty string for file file_str
    std::string file_str;

    // read from file if one is present
    if (inFile.is_open())
    {
        // grabs file_str from file
        std::getline(inFile, file_str);
        buildTree(file_str);
        inFile.close();

        while (true)
        {
            // Read a string from the user
            std::cout << "Enter your numbers (place a space between each integer):" << std::endl;
            std::getline(std::cin, file_str);

            if (dataValidation(file_str))
            {
                // breaks loop if data conditions are met
                break;
            }
            else
            {
                std::cout << "Invalid Data. Please enter a line of numbers with a space in between.\n";
            }
        }
        // builds a binary tree with file data
        buildTree(file_str);
    }
    else
    {
        std::string user_str;
        while (true)
        {
            // Read a string from the user
            std::cout << "Enter your numbers (place a space between each integer):" << std::endl;
            std::getline(std::cin, user_str);

            if (dataValidation(user_str))
            {
                break;
            }
            else
            {
                std::cout << "Invalid Data. Please enter a line of numbers with a space in between.\n";
            }
        }
        // builds a binary tree with user data
        buildTree(user_str);
    }

    return 0;
}

bool dataValidation(const std::string& input)
{
    std::istringstream iss(input);
    int number;

    // Checks that the user inputs at least one number
    if (!(iss >> number))
    {
        return false;
    }

    // checks that all numbers have spaces in between
    while (iss >> number)
    {

    }

    return iss.eof();
}
