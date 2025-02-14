#include "Node.h"
#include <cassert>

void test_linked_list_functions() {
    Node* root = build_linked_list(5);
    
    std::cout << "Initial linked list: ";
    print_linked_list(root);

    // Test getting values
    assert(get_linked_list_data_item_value(root, 0) == 1);
    assert(get_linked_list_data_item_value(root, 2) == 3);
    assert(get_linked_list_data_item_value(root, 4) == 5);
    assert(get_linked_list_data_item_value(root, 5) == -1); // Out of range

    // Test deleting elements
    std::cout << "Deleting node at index 2 (Value 3)...\n";
    delete_list_element(root, 2);

    std::cout << "Linked list after deletion: ";
    print_linked_list(root);

    int value_after_deletion = get_linked_list_data_item_value(root, 2);
    std::cout << "Value at index 2 after deletion: " << value_after_deletion << std::endl;

    assert(value_after_deletion == 4); // Ensure index 2 now holds 4

    // Delete entire list
    delete_entire_linked_list(root);
    assert(root == nullptr);

    std::cout << "All tests passed!\n";
}

int main() {
    test_linked_list_functions();
    return 0;
}
