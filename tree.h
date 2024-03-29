// Thomas Cholak

#ifndef TREE_H
#define TREE_H

#include "node.h"

#include <bits/stdc++.h>

// header file functions

bool dataValidation(const std::string& input);
void buildTree(const std::string& node_str);
std::vector<int> printPostorder(int arr[], int pre[], int inStrt, int inEnd);
int printPreorder(int arr[], int startIn, int endIn, int data);

node* ConstructTree(int pre[], int post[], int size);
std::vector<std::string> printInorder(node* node, int depth);
node* ConstructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size);
void writeToFile(const std::string& filename, const std::string& data);

#endif