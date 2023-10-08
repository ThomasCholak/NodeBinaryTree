// Thomas Cholak

#ifndef NODE_H
#define NODE_H

#include <cstddef>

// each node stores a value and what value is to the right and left of it
class node
{
public:
    int data;
    node* left;
    node* right;
};

#endif