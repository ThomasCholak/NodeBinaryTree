
#include "tree.h"
#include "node.h"

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

    //std::vector<Node> nodes;

    std::vector<int> root_nodes = vector;
    std::vector<int> leaf_nodes = vector;

    std::vector<int>::size_type num = root_nodes.size(); //stores new size of array after removing duplicates
    std::vector<int>::size_type num2 = root_nodes.size(); //stores new size of array after removing duplicates

    for (int & i : root_nodes) //locates the first number of every entry
    {
        while (i >= 10)  //continues dividing by 10 until first digit is found
        {
            i /= 10;
        }
    }

    for (int i = 0; i < num; i++)  //loop to remove duplicates from root nodes
    {
        for (int j = i + 1; j < num; j++)
        {
            if (root_nodes[i] == root_nodes[j])
            {
                for (int k = j; k < num; k++)
                {
                    root_nodes[k] = root_nodes[k + 1];
                }
                num--;
                j--;
            }
        }
    }

    int n = num;

    insertionSort(root_nodes, n);  //sorts root_nodes via Insertion sort

    Node nodes[num];

    for (int i = 0; i < num; ++i) {
        nodes[i].parent_node = root_nodes[i];
    }

    for (int i = 0; i < num; ++i) {
        std::cout << "\n" << nodes[i].parent_node;
    }

    for (int i = 0; i < num2; i++)  //loop to remove duplicates from leaf nodes
    {
        for (int j = i + 1; j < num2; j++)
        {
            if (leaf_nodes[i] == leaf_nodes[j])
            {
                for (int k = j; k < num2; k++)
                {
                    leaf_nodes[k] = leaf_nodes[k + 1];
                }
                num2--;
                j--;
            }
        }
    }

    std::vector<int> leaf_nodes2 = leaf_nodes;

    for (int & i : leaf_nodes)
    {
        while (i >= 10)
        {
            i /= 10;
        }
    }

    /*
    for (size_t i = 0; i < leaf_nodes.size(); i++)
    {
        if (leaf_nodes[i] != root_nodes[i])
        {
            Node newNode;
            newNode.parent_node = {static_cast<double>(root_nodes[i])};
            newNode.child_nodes = {static_cast<double>(leaf_nodes2[i])};
            nodes.push_back(newNode);
        }
    }

    for (const Node& node : nodes) {
        for (const double& parent : node.parent_node) {
            std::cout << parent << ":";
        }
        for (const double& child : node.child_nodes) {
            std::cout << child << " ";
        }
        std::cout << std::endl;
    }
    */

    /*
    std::cout << "\n";

    for (int i = 0; i < num; i++) {
        std::cout << root_nodes[i] << endl;
    }

    std::cout << "\n";

    for (int i = 0; i < num2; i++) {
        std::cout << leaf_nodes[i] << endl;
    }
     */
}