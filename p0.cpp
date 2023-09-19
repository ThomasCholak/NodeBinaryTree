
#include <iostream>

#include "tree.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::string str = "61 667 143 66 17 52 21 52 21 779 52 16";

    //calls on function to break apart str and store as 'result1'
    std::vector<std::string> result = sepArray(str);

    // Use the returned vector as needed
    for (const auto& item : result) {
        std::cout << item << std::endl;
    }

    return 0;

    return 0;
}