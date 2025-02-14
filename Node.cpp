#include "Node.h"

// Constructor
Node::Node(int value) : data(value), next(nullptr) {}

// Copy Constructor
Node::Node(const Node& other) : data(other.data), next(nullptr) {
    if (other.next) {
        next = new Node(*other.next);
    }
}

// Destructor
Node::~Node() {
    delete next;
}

// Function to build a linked list
Node* build_linked_list(int n) {
    if (n <= 0) return nullptr;

    Node* head = new Node(1);
    Node* current = head;

    for (int i = 2; i <= n; ++i) {
        current->next = new Node(i);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void print_linked_list(Node* root) {
    Node* temp = root;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}

// Function to delete the entire linked list
void delete_entire_linked_list(Node*& root) {
    while (root) {
        Node* temp = root;
        root = root->next;
        temp->next = nullptr; // Prevent destructor from cascading deletes
        delete temp;
    }
}

// Function to get the value at a specific node position
int get_linked_list_data_item_value(Node* root, int node_number) {
    int count = 0;
    while (root) {
        if (count == node_number) return root->data;
        root = root->next;
        count++;
    }
    return -1; // Return -1 if node_number is out of range
}

// Function to delete a specific node
void delete_list_element(Node*& root, int node_number) {
    if (!root) return;

    if (node_number == 0) {
        Node* temp = root;
        root = root->next;
        temp->next = nullptr; // Prevent cascading destructor calls
        delete temp;
        return;
    }

    Node* prev = root;
    Node* current = root->next;
    int count = 1;

    while (current && count < node_number) {
        prev = current;
        current = current->next;
        count++;
    }

    if (current) {
        prev->next = current->next; // Update link
        current->next = nullptr;    // Prevent invalid memory deletion
        delete current;
    }
}
