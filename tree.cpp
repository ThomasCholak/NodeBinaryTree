
#include "tree.h"
#include "node.h"

#include <bits/stdc++.h>

// https://www.geeksforgeeks.org/split-string-by-space-into-vector-in-cpp-stl/
std::vector<std::string> sepArray(const std::string& str) {

    std::stringstream ss(str);
    std::string s;
    std::vector<std::string> DataNumbers1;

    while (getline(ss, s, ' ')) {
        DataNumbers1.push_back(s);
    }

    return DataNumbers1;

}

//void buildTree(std::vector<std::string> vector1) {
//
//}
