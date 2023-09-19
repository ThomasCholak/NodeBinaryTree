
#include "tree.h"
#include "node.h"

#include <bits/stdc++.h>


using std::string;
using std::stringstream;
using std::cout;
using std::endl;

std::vector<int> sepArray(const std::string& str) {

    stringstream stream(str);

    std::vector<int> values;
    int n;
    while(stream >> n){
        values.push_back(n);
    }

    return values;

}

//void buildTree(std::vector<std::string> vector1) {
//
//}
