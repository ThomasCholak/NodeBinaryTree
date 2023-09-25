
#include "tree.h"
#include "node.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstddef>
#include <string>

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
    std::vector<std::string> inOrderPair;

   // Printing via pairs
   // https://stackoverflow.com/questions/19228994/how-to-print-a-type-vectorpairchar-int-to-screen-c
    for (auto &x : sorted_array)
    {
        std::string inOrder_pairs = std::to_string(x.first) + ":";
        inOrder.push_back(x.first);  // stores 'first' elements from the vector pair
        // std::cout << x.first << ":";
        for (int num2 : x.second) {
            // std::cout << num2 << " ";
            inOrder_pairs += std::to_string(num2) + " ";
        }
        // std::cout << std::endl;
        inOrderPair.push_back(inOrder_pairs); // Add the pair entry to inOrderPair
    }


    //Converts inOrder and preOrder into arrays from vectors
    int n = inOrder.size();
    int in[n];
    copy(inOrder.begin(), inOrder.end(), in);

    std::vector<int> preOrder;

    int n2 = root_nodes.size();
    int pre[n2];                                                       // pre = postOrder
    copy(root_nodes.begin(), root_nodes.end(), pre);

    std::vector<int> postOrder = printPostorder(in, pre, n);

    int n3 = postOrder.size();
    int post[n3];
    copy(postOrder.begin(), postOrder.end(), post);

    int size2 = sizeof(pre) / sizeof(pre[0]);

    //Builds the tree
    node* root = constructTree(pre, post, size2);
    std::vector<std::string> depth_pre = printInorder(root, 0);

    //// string comparisons
    int pre_size = sizeof(pre) / sizeof(pre[0]);  //pre string
    std::vector<std::string> preString;

    for (int i = 0; i < pre_size; i++) {
        preString.push_back(std::to_string(pre[i]));
    }


    int post_size = sizeof(post) / sizeof(post[0]);  // post string
    std::vector<std::string> postString;

    for (int i = 0; i < post_size; i++) {
        postString.push_back(std::to_string(post[i]));
    }

    // Strings

    std::vector<std::string> pre2;
    std::vector<std::string> post2;


    for (const std::string& str1 : preString) {
        for (const std::string& str2 : inOrderPair) {
            if (str1[0] == str2[0]) {
                pre2.push_back(str2);
            }
        }
    }

    for (const std::string& str1 : postString) {
        for (const std::string& str2 : inOrderPair) {
            if (str1[0] == str2[0]) {
                post2.push_back(str2);
            }
        }
    }

    std::cout << "Pre-String" << std::endl;
    for (const std::string& str1 : pre2) {
        for (const std::string& str2 : depth_pre) {
            if (str1[0] == str2.back()) {
                std::string substr = str1.substr(1);
                std::cout << str2 << substr << std::endl;
            }
        }
    }

    std::cout << std::endl;

    std::cout << "Post-String" << std::endl;
    for (const std::string& str1 : post2) {
        for (const std::string& str2 : depth_pre) {
            if (str1[0] == str2.back()) {
                std::string substr = str1.substr(1);
                std::cout << str2 << substr << std::endl;
            }
        }
    }

    std::cout << std::endl;

    std::cout << "Inorder-String" << std::endl;
    for (const std::string& str1 : inOrderPair) {
        for (const std::string& str2 : depth_pre) {
            if (str1[0] == str2.back()) {
                std::string substr = str1.substr(1);
                std::cout << str2 << substr << std::endl;
            }
        }
    }

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

std::vector<std::string> printInorder(node* node, int depth) {

    std::vector<std::string> inOrder;

    if (node == nullptr)
        return inOrder;

    // uses stars for depth mapping:
    // https://stackoverflow.com/questions/2596953/multiply-char-by-integer-c
    char star = '*';
    int num = depth * 2;

    std::string line = std::string(num, star) + std::to_string(node->data);
    inOrder.push_back(line);

    // Concatenate the left and right subtree results
    std::vector<std::string> leftBranch = printInorder(node->left, depth + 1);
    std::vector<std::string> rightBranch = printInorder(node->right, depth + 1);

    inOrder.insert(inOrder.end(), leftBranch.begin(), leftBranch.end());
    inOrder.insert(inOrder.end(), rightBranch.begin(), rightBranch.end());

    return inOrder;
}