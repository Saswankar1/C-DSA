#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    void inorder() {
        inorderRec(root);
        std::cout << std::endl;
    }

    Node* search(int value) {
        return searchRec(root, value);
    }

    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void inorderRec(Node* node) {
        if (node != nullptr) {
            inorderRec(node->left);
            std::cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    Node* searchRec(Node* node, int value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchRec(node->left, value);
        }

        return searchRec(node->right, value);
    }

    Node* deleteRec(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteRec(node->left, value);
        } else if (value > node->data) {
            node->right = deleteRec(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current && current->left != nullptr) {
            current = current->left;
        }

        return current;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal of the BST: ";
    bst.inorder();

    int key = 40;
    if (bst.search(key) != nullptr) {
        std::cout << key << " found in the BST." << std::endl;
    } else {
        std::cout << key << " not found in the BST." << std::endl;
    }

    bst.deleteNode(20);
    std::cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    bst.deleteNode(30);
    std::cout << "Inorder traversal after deleting 30: ";
    bst.inorder();

    bst.deleteNode(50);
    std::cout << "Inorder traversal after deleting 50: ";
    bst.inorder();

    return 0;
}
