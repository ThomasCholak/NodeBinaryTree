
#include "tree.h"
#include "node.h"

#include <bits/stdc++.h>

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

std::vector<int> sepArray(const std::string& str) {

    stringstream stream(str);

    //https://stackoverflow.com/questions/4475634/pass-a-string-in-c
    std::vector<int> values;
    int n;
    while(stream >> n){
        values.push_back(n);
    }

    return values;

}