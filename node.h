#ifndef NODE_H
#define NODE_H

struct Node {
    int level;               //tracks the depth level of the node
    struct node* left;
    struct node* right;
};

#endif