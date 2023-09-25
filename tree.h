#ifndef TREE_H
#define TREE_H

#include "node.h"

#include <bits/stdc++.h>

void buildTree(const std::string& node_str);
std::vector<int> printPostorder(int in[], int pre[], int n);
int search(int arr[], int x, int n);

node* constructTree(int pre[], int post[], int size);
std::vector<std::string> printInorder(node* node, int depth);
node* constructTreeUtil(int pre[], int post[], int* preIndex, int l, int h, int size);

#endif