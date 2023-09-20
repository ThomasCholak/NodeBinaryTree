
#include "tree.h"
#include "node.h"

#include <bits/stdc++.h>
#include <algorithm>

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

//sorts array values from lowest to greatest
void insertionSort(std::vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) { int key = arr[i]; int j = i - 1; while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}