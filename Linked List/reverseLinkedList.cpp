// Reverse a Linked List

// PROBLEM LINKS:
// LEETCODE: https://leetcode.com/problems/reverse-linked-list/description/
// CODE STUDIO: https://www.codingninjas.com/studio/problems/799897



// ITERATIVE APPROACH

// Time Complexity:
// Since we are iterating only once through the list and achieving reversed list. 
// Thus, the time complexity is O(N) where N is the number of nodes present in the list.

// Space Complexity:
// To perform given tasks, no external spaces are used except three-pointers. 
// So, space complexity is O(1).


class Solution {
public:

    ListNode* reverseList(ListNode* head) {

       //step 1
        ListNode* prev_p = NULL;
        ListNode* current_p = head;
        ListNode* next_p;
       
       //step 2
        while(current_p) {

            next_p = current_p->next;
            current_p->next = prev_p;
            
            prev_p = current_p;
            current_p = next_p;
        }

        head = prev_p; //step 3
        return head;
    }
};



// RECURSIVE APPROACH

// Time Complexity:
// We move to the end of the list and achieve our reversed list. 
// Thus, the time complexity is O(N) where N represents the number of nodes.

// Space Complexity:
// Apart from recursion using stack space, no external storage is used. 
// Thus, space complexity is O(1).


class Solution {
public:

    ListNode* reverseList(ListNode* &head) {

        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
};