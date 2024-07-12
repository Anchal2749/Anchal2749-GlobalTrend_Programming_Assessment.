//Write a function to reverse a singly linked list.The function should take the head of the list and return the new head of the reversed list.



#include <bits/stdc++.h>

using namespace std;


class Node {
public:
   
    int data;   
    Node* next;      
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

//function to reverse linkedlist
Node* reverseLinkedList(Node *head)
{
   
   Node* temp = head;  
   Node* prev = NULL;  
   while(temp != NULL){  
       Node* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front; 
   }
   return prev;  
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    cout << "Original Linked List: ";
    printLinkedList(head);
    head = reverseLinkedList(head);
    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}