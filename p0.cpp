// Thomas Cholak

#include "tree.h"
#include <string>

#include <iostream>
#include <fstream>

// 'main' accepts file arguments in case user redirects a file into the program
int main(int argc, char* argv[])
{
    std::ifstream inFile;

    if (argc > 1)
    {
        //looks for if a file is present in Delmar
        inFile.open(argv[1]);

        // error validation if file couldn't be opened
        if (!inFile.is_open())
        {
            std::cerr << "Error! Could not open file: " << argv[1] << std::endl;
            return 1;
        }
    }

    // initialize empty string for file file_str
    std::string file_str;

    // Read from file if one is present
    if (inFile.is_open())
    {
        // grabs file_str from file
        std::getline(inFile, file_str);
        buildTree(file_str);
        inFile.close();
    }
    else
    {
        // Read a string from the user
        //std::cout << "Enter your numbers (place a space between each integer):" << std::endl;
        //std::string user_str;
        //std::getline(std::cin, user_str);
        //buildTree(user_str);

         //'user' string for testing purposes
         std::string user_str = "12 34 56 76 54 34";
         buildTree(user_str);
    }

    return 0;
}