
#include <iostream>
#include "tree.h"
#include <string>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

using namespace std;

int main() {
    std::string str1 = "61 667 143 66 17 52 21 52 21 779 52 16";

    std::vector<int> result = sepArray(str1);

    for (const auto& item : result) {
        std::cout << item << std::endl;
    }

    return 0;

}