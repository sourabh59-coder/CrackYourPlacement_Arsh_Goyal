#include <bits/stdc++.h> 
using namespace std; 

/* a node of the singly linked list */
class Node 
{ 
public: 
    int data; 
    Node *next; 
    Node (int d) {
        data = d;
        next = nullptr;
    }
}; 

// Function to segregate even and odd nodes.
void segregateEvenOdd(struct Node** head_ref)
{
    // Starting node of list having even values.
    Node* evenStart = nullptr;
    
    // Ending node of even values list.
    Node* evenEnd = nullptr;
    
    // Same for the odd list.
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;
    
    // Node to traverse the list.
    Node* currNode = *head_ref;

    while (currNode != nullptr) {
        int val = currNode->data;

        // If current value is even, add it to even values
        // list.
        if (val % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }

        // If current value is odd, add it to odd values
        // list.
        else {
            if (oddStart == nullptr) {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }

        // Move head pointer one step in forward direction
        currNode = currNode->next;
    }

    // If either odd list or even list is empty, no change
    // is required as all elements are either even or odd.
    if (oddStart == nullptr || evenStart == nullptr)
        return;

    // Add odd list after even list.
    evenEnd->next = oddStart;
    oddEnd->next = nullptr;

    // Modify head pointer to starting of even list.
    *head_ref = evenStart;
}

/* Function to print nodes in a given linked list */
void printList(Node *node) 
{ 
    while (node != nullptr) 
    { 
        cout << node->data <<" "; 
        node = node->next; 
    } 
} 

/* Driver code*/
int main() 
{ 
    /* Let us create a sample linked list as following 
    0->2->4->6->8->10->11 */
    Node* head = new Node(0);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = 
                                   new Node(10);
    head->next->next->next->next->next->next = 
                                   new Node(11);

    cout << "Original Linked list "; 
    printList(head); 

    segregateEvenOdd(&head); 

    cout << "\nModified Linked list "; 
    printList(head); 

    return 0; 
} 
