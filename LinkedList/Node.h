#include <iostream>

#ifndef NODE_H
#define NODE_H

template <typename type>
struct Node {
    type data;
    Node *next;
};

#endif