#ifndef NODE_H
#define NODE_H

struct Node {
    //int level;                           //tracks the depth level of the node
    int parent_node;
    std::vector<double> child_nodes;     //used to store number son the same node

    Node() : parent_node(), child_nodes() {}
};

#endif