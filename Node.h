#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    int data;
    Node* next;

    // Constructor
    Node(int value);

    // Copy Constructor
    Node(const Node& other);

    // Destructor
    ~Node();
};

// Function Declarations
Node* build_linked_list(int n);
void print_linked_list(Node* root);
void delete_entire_linked_list(Node*& root);
int get_linked_list_data_item_value(Node* root, int node_number);
void delete_list_element(Node*& root, int node_number);

#endif // NODE_H
