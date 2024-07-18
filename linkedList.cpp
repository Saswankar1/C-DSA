#include <iostream>

// Define a node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a node
    Node(int data) : data(data), next(nullptr) {}
};

// Define a LinkedList class
class LinkedList {
private:
    Node* head; // Pointer to the head of the linked list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the linked list
    void insert(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to delete the entire linked list to free memory
    void deleteList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        std::cout << "Linked list deleted." << std::endl;
    }

    // Destructor to automatically delete the linked list when object goes out of scope
    ~LinkedList() {
        deleteList();
    }
};

// Main function to demonstrate the linked list operations
int main() {
    LinkedList list;

    // Insert elements into the linked list
    list.insert(5);
    list.insert(10);
    list.insert(15);

    // Display the linked list
    std::cout << "Linked List: ";
    list.display();

    return 0;
}
