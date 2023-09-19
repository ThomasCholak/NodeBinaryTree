
#include "tree.h"

#include <iostream>
#include <string>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

using namespace std;

int main() {
    std::string str1 = "61 667 143 66 17 52 21 52 21 779 52 16";

    //https://stackoverflow.com/questions/4475634/pass-a-string-in-c
    std::vector<int> result = sepArray(str1);

    for (const auto& item : result) {
        std::cout << item << std::endl;
    }

    return 0;

}