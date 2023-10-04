// Thomas Cholak

#include "tree.h"
#include "node.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <algorithm>

void buildTree(const std::string& node_str)
{
    // Converts string into an integer vector:
    // https://stackoverflow.com/questions/20659066/parse-string-to-vector-of-int
    std::istringstream iss(node_str);
    std::vector<int> node_int;
    int num;

    while (iss >> num)
    {
        node_int.push_back(num);
    }

    std::map<int, std::vector<int>> firstDigits;

    for (int num : node_int) {
        int first_digit = num;

        while (first_digit >= 10) {
            first_digit /= 10;
        }

        firstDigits[first_digit].push_back(num);
    }

    std::vector<int> inOrder;
    std::vector<std::string> inOrderPair;

    // Print the organized arrays
    for (const auto& entry : firstDigits) {
        inOrder.push_back(entry.first);
        std::string inOrder_pairs = std::to_string(entry.first) + ":";
        for (int num : entry.second) {
            inOrder_pairs += std::to_string(num) + " ";
        }
        inOrderPair.push_back(inOrder_pairs);
    }

    std::vector<int> preOrder = node_int;

    for (int & i : preOrder)
    {
        while (i >= 10)
        {
            i /= 10;
        }
    }

    std::unordered_set<int> seen;

    preOrder.erase(std::remove_if(preOrder.begin(), preOrder.end(),
                                  [&seen](int x)
                                  {
                                      return !seen.insert(x).second;
                                  }),
                   preOrder.end());


    //Converts inOrder and preOrder into arrays from vectors
    const int N = inOrder.size();
    int in[N];
    copy(inOrder.begin(), inOrder.end(), in);

    // creates a preOrder integer array
    const int N2 = preOrder.size();
    int pre[N2];
    copy(preOrder.begin(), preOrder.end(), pre);


    // uses the other traversals to create a vector for postOrder
    std::vector<int> postOrder = printPostorder(in, pre, 0, N - 1);


    // creates a postOrder integer array through a 'copy'
    const int N3 = postOrder.size();
    int post[N3];
    copy(postOrder.begin(), postOrder.end(), post);

    const int SIZE2 = sizeof(pre) / sizeof(pre[0]);

    // builds the tree (Inorder traversal)
    node* root = ConstructTree(pre, post, SIZE2);
    std::vector<std::string> depth_pre = printInorder(root, 0);

    // converts an integer vector (preOrder) into a string vector
    const int PRE_SIZE = sizeof(pre) / sizeof(pre[0]);
    std::vector<std::string> preString;

    for (int i = 0; i < PRE_SIZE; i++)
    {
        preString.push_back(std::to_string(pre[i]));
    }

    // converts postOrder into a string vector
    const int POST_SIZE = sizeof(post) / sizeof(post[0]);
    std::vector<std::string> postString;

    for (int i = 0; i < POST_SIZE; i++)
    {
        postString.push_back(std::to_string(post[i]));
    }

    // empty vectors to store new strings in
    std::vector<std::string> pre2;
    std::vector<std::string> post2;

    // pushes leaf nodes to root notes for preOrder
    for (const std::string& STR1 : preString)
    {
        for (const std::string& STR2 : inOrderPair)
        {
            if (STR1[0] == STR2[0])
            {
                pre2.push_back(STR2);
            }
        }
    }

    // pushes leaf nodes to root notes for postOrder
    for (const std::string& STR1 : postString)
    {
        for (const std::string& STR2 : inOrderPair)
        {
            if (STR1[0] == STR2[0])
            {
                post2.push_back(STR2);
            }
        }
    }

    // adds depth levels to all levels for preString
    std::cout << "Pre-String" << std::endl;
    for (const std::string& STR1 : pre2)
    {
        for (const std::string& STR2 : depth_pre)
        {
            if (STR1[0] == STR2.back())
            {
                std::string substr = STR1.substr(1);
                std::cout << STR2 << substr << std::endl;
            }
        }
    }

    std::cout << std::endl;  // spacing

    // adds depth level string to the beginning of postOrder
    std::cout << "Post-String" << std::endl;
    for (const std::string& str1 : post2)
    {
        for (const std::string& str2 : depth_pre)
        {
            if (str1[0] == str2.back())
            {
                std::string substr = str1.substr(1);
                std::cout << str2 << substr << std::endl;
            }
        }
    }

    std::cout << std::endl;  // spacing

    // adds depth level string to the beginning of inOrder
    std::cout << "Inorder-String" << std::endl;
    for (const std::string& str1 : inOrderPair)
    {
        for (const std::string& str2 : depth_pre)
        {
            if (str1[0] == str2.back())
            {
                std::string substr = str1.substr(1);
                std::cout << str2 << substr << std::endl;
            }
        }
    }

}

// "search" and "printPostOrder" functions modified from here:
// https://www.geeksforgeeks.org/print-postorder-from-given-inorder-and-preorder-traversals/
int Search(int arr[], int startIn,int endIn, int data)
{
    int i;
    for (i = startIn; i < endIn; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return i;
}

// uses 'preOrder' and 'inOrder' traversals to return 'postOrder'
std::vector<int> printPostorder(int arr[], int pre[], int inStrt, int inEnd)
{
    int preIndex = 0;

    std::vector<int> postOrder;

    if (inStrt > inEnd)
    {
        return postOrder;
    }

    // Looks for the index of the next number in the traversal
    int inIndex = Search(arr, inStrt, inEnd, pre[preIndex++]);

    // Traversal for the left tree
    std::vector<int> leftPostorder = printPostorder(arr, pre, inStrt, inIndex - 1);
    postOrder.insert(postOrder.end(), leftPostorder.begin(), leftPostorder.end());

    // Traversal for the right tree
    std::vector<int> rightPostorder = printPostorder(arr, pre, inIndex + 1, inEnd);
    postOrder.insert(postOrder.end(), rightPostorder.begin(), rightPostorder.end());

    // Adds the root node to the beginning of the traversal
    postOrder.push_back(arr[inIndex]);

    return postOrder;
}

// "printInorder", "newNode", "constructTreeUtil", "constructTree" functions are modified from the below url:
// https://www.geeksforgeeks.org/full-and-complete-binary-tree-from-given-preorder-and-postorder-traversals/
node* newNode(int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

node* ConstructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)
        return nullptr;

    // assumes that the first number is the root
    node* root = newNode(pre[*preIndex]);
    ++*preIndex;

    // prevents recursion if the current subarray has one element
    if (l == h)
        return root;

    //searches 'preOrder' and 'postOrder' lists for the next element
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;

    // divides tree into left and right branches
    if (i <= h)
    {
        root->left = ConstructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = ConstructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
    }

    return root;
}

node* ConstructTree(int pre[], int post[], int size) {
    int preIndex = 0;
    return ConstructTreeUtil(pre, post, &preIndex, 0, size - 1, size);
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

    // Splits nodes into left and right branches using 'node'
    std::vector<std::string> leftBranch = printInorder(node->left, depth + 1);
    std::vector<std::string> rightBranch = printInorder(node->right, depth + 1);

    inOrder.insert(inOrder.end(), leftBranch.begin(), leftBranch.end());
    inOrder.insert(inOrder.end(), rightBranch.begin(), rightBranch.end());

    return inOrder;  //builds tree and returns depth level
}