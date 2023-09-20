
#include "tree.h"

#include <iostream>
#include <string>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

using namespace std;

/*
 * Resources used:
 *
 * Function for locating first number of an array:
 * https://www.scaler.com/topics/cpp-program-to-find-first-and-last-digit-of-a-number/
 *
 * Function for removing duplicates from an array:
 * https://www.youtube.com/watch?v=zvXSbyqNvsw
 *
 * Function for passing a string into an vector of integers:
 * //https://stackoverflow.com/questions/4475634/pass-a-string-in-c
 *
 * Insertion sorting algorithm:
 * https://prepinsta.com/data-structures-algorithms/sorting-of-array/
*/

int main() {
    std::string str1 = "61 667 143 66 17 52 21 52 21 779 52 16";
    std::vector<int> result = sepArray(str1); // Calls 'sepArray' function to separate integers

    buildTree(result);

    return 0;
}

void buildTree(const std::vector<int>& vector) {

    std::vector<int> result = vector;
    std::vector<int>::size_type num = result.size(); //stores new size of array after removing duplicates

    for (int & i : result) //locates the first number of every entry
    {
        while (i >= 10)  //continues dividing by 10 until first digit is found
        {
            i /= 10;
        }
    }

    for (int i = 0; i < num; i++)  //loop to remove duplicates from array
    {
        for (int j = i + 1; j < num; j++)
        {
            if (result[i] == result[j])
            {
                for (int k = j; k < num; k++)
                {
                    result[k] = result[k + 1];
                }
                num--;
                j--;
            }
        }
    }

    int n = sizeof(result);

    insertionSort(result, n);  //sorts via Insertion sort

    for (int i = 0; i < num; i++) {
        std::cout << result[i] << endl;
    }
}
