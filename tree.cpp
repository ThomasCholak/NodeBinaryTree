
#include "tree.h"
#include "node.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstddef>

void buildTree(const std::string& node_str) {

    // Converts string into an integer vector:
    // https://stackoverflow.com/questions/20659066/parse-string-to-vector-of-int
    std::istringstream iss(node_str);
    std::vector<int> node_int;
    int num;

    while (iss >> num) {
        node_int.push_back(num);
    }

    std::unordered_set<int> unique_values;  //empty vector to return unique values to

    // code to remove non-unique integers:
    // https://www.reddit.com/r/cpp_questions/comments/bjims8/the_best_way_to_remove_duplicates_from_vector_of/
    node_int.erase(std::remove_if(node_int.begin(), node_int.end(),
                                  [&unique_values](int x)
                           {
                               return !unique_values.insert(x).second;
                           }),
                   node_int.end());

    // Code to organize values via mapping:
    // https://stackoverflow.com/questions/19842035/how-can-i-sort-a-stdmap-first-by-value-then-by-key
    std::map<int, std::vector<int>> sorted_array;

    std::vector<int> root_nodes3 = node_int;

    for (int & i : root_nodes3)
    {
        while (i >= 10)
        {
            i /= 10;
        }
    }

    std::unordered_set<int> root_nodes2;

    node_int.erase(std::remove_if(root_nodes3.begin(), root_nodes3.end(),
                                  [&root_nodes2](int x)
                                  {
                                      return !root_nodes2.insert(x).second;
                                  }),
                   root_nodes3.end());

    std::vector<int> root_nodes(root_nodes2.begin(), root_nodes2.end());
    std::reverse(root_nodes.begin(), root_nodes.end());

    std::cout << "Preorder traversal:\n";
    for (const int& num : root_nodes) {  //'root_nodes' is preorder
        std::cout << num << " ";
    }
    std::cout << "\n";


    // Finds first digit and pushes it to another vector:
    // https://www.scaler.com/topics/cpp-program-to-find-first-and-last-digit-of-a-number/
    for (int num2 : unique_values) {
        int first_digit = num2;

        while (first_digit >= 10) {
            first_digit /= 10;
        }
        sorted_array[first_digit].push_back(num2);
    }

    std::vector<int> inOrder;

    // Printing via pairs
    // https://stackoverflow.com/questions/19228994/how-to-print-a-type-vectorpairchar-int-to-screen-c
    std::cout << "Inorder traversal:\n";
    for (auto &x:sorted_array)
    {
        inOrder.push_back(x.first);  //stores 'first' elements from the vector pair
        std::cout << x.first << ":";
        for (int num2 : x.second) {
            std::cout << num2 << " ";
        }
        std::cout << std::endl;
    }


    //Converts inOrder and preOrder into arrays from vectors
    int n = inOrder.size();
    int in[n];
    copy(inOrder.begin(), inOrder.end(), in);


    // Print the 'in' array
    /*
    std::cout << "Inorder array: ";
    for (int i = 0; i < n; i++) {
        std::cout << in[i] << " ";
    }
    std::cout << std::endl;
     */

    std::vector<int> preOrder;

    int n2 = root_nodes.size();
    int pre[n2];                                                       // pre = postOrder
    copy(root_nodes.begin(), root_nodes.end(), pre);

    // Print the 'pre' array
    /*
    std::cout << "Preorder array: ";
    for (int i = 0; i < n2; i++) {
        std::cout << pre[i] << " ";
    }
    std::cout << std::endl;
     */

    std::vector<int> postOrder = printPostorder(in, pre, n);

    //Prints the PostOrder Traversals
    std::cout << "Postorder traversal:" << std::endl;
    for (const int& num : postOrder) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int n3 = postOrder.size();
    int post[n3];
    copy(postOrder.begin(), postOrder.end(), post);

    int size2 = sizeof(pre) / sizeof(pre[0]);


    std::cout << std::endl;

    //Builds the tree
    std::cout << "Preorder Depth Map: \n";
    node* root = constructTree(pre, post, size2);
    printInorder(root, 0);
}

// "search" and "printPostOrder" functions from here:
// https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

std::vector<int> printPostorder(int in[], int pre[], int n)
{
    std::vector<int> postOrder;

    int root = search(in, pre[0], n);

    if (root != 0)
    {
        std::vector<int> leftPostorder = printPostorder(in, pre + 1, root);
        postOrder.insert(postOrder.end(), leftPostorder.begin(), leftPostorder.end());
    }

    if (root != n - 1)
    {
        std::vector<int> rightPostorder = printPostorder(in + root + 1, pre + root + 1, n - root - 1);
        postOrder.insert(postOrder.end(), rightPostorder.begin(), rightPostorder.end());
    }

    postOrder.push_back(pre[0]);

    return postOrder;
}

// "printInorder", "newNode", "constructTreeUtil", "constructTree" functions are from the below url:
// https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
node* newNode(int data) {
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node* constructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return NULL;

    node* root = newNode(pre[*preIndex]);
    ++*preIndex;

    if (l == h)
        return root;

    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;

    if (i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

node* constructTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, &preIndex, 0, size - 1, size);
}

void printInorder(node* node, int depth) {
    if (node == nullptr)
        return;

    // uses stars for depth mapping:
    // https://stackoverflow.com/questions/2596953/multiply-char-by-integer-c
    char star = '*';
    int num = depth * 2;

    std::cout << std::string(num, star)  << node->data << "\n";

    printInorder(node->left, depth + 1);
    printInorder(node->right, depth + 1);
}