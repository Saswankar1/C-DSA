#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* current = dummyHead;
    int carry = 0;

    while (p != nullptr || q != nullptr) {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        int sum = carry + x + y;
        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;

        if (p != nullptr) p = p->next;
        if (q != nullptr) q = q->next;
    }

    if (carry > 0) {
        current->next = new ListNode(carry);
    }

    return dummyHead->next;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to append a node to the end of the list
void appendNode(ListNode*& head, int value) {
    if (head == nullptr) {
        head = new ListNode(value);
    } else {
        ListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new ListNode(value);
    }
}

int main() {
    // Creating the first linked list: 2 -> 4 -> 3 (represents 342)
    ListNode* l1 = nullptr;
    appendNode(l1, 2);
    appendNode(l1, 4);
    appendNode(l1, 3);

    // Creating the second linked list: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = nullptr;
    appendNode(l2, 5);
    appendNode(l2, 6);
    appendNode(l2, 4);

    // Adding the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Printing the result
    cout << "Result: ";
    printList(result);

    return 0;
}
