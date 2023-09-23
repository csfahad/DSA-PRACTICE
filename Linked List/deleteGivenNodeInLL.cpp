// Delete given node in a Linked List : O(1) approach

// PROBLEM LINKS:
// LEETCODE: https://leetcode.com/problems/delete-node-in-a-linked-list/description/
// CODE STUDIO: https://www.codingninjas.com/studio/problems/1105578


// INTUTION: We are given access to nodes that we have to delete from the linked list. 
// So, whatever operation we want to do in the linked list, we can operate in the right part of the linked list from the node to be deleted. 
// The approach is to copy the next node’s value in the deleted node. Then, link node to next of next node. 
// This does not delete that node but indirectly it removes that node from the linked list.


// Time Complexity: O(1)
// Reason: It is a two-step process that can be obtained in constant time.

// Space Complexity: O(1)
// Reason: No extra data structure is used.



#include<iostream>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};
//function to insert node at the end of the list
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
//function to get reference of the node to delete
node* getNode(node* head,int val) {
    while(head->num != val) head = head->next;
    
    return head;
}
//delete function as per the question
void deleteNode(node* t) {
    t->num = t->next->num;
    t->next = t->next->next;
    return;
}
//printing the list function
void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    }
    cout<<head->num<<"\n";
}

int main() {
    node* head = NULL;
    //inserting node
    insertNode(head,1);
    insertNode(head,4);
    insertNode(head,2);
    insertNode(head,3);
    //printing given list
    cout<<"Given Linked List:\n";
    printList(head);
    node* t = getNode(head,2);
    //delete node
    deleteNode(t);
    //list after deletion operation
    cout<<"Linked List after deletion:\n";
    printList(head);
    return 0;
}