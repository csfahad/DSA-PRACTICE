// Remove N-th node from the end of a Linked List


// // PROBLEM LINKS:
// LEETCODE: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// CODE STUDIO: https://www.codingninjas.com/studio/problems/799912


// BRUTEFORCE APPROACH

// Intuition: We can traverse through the Linked List while maintaining a count of nodes, 
// let’s say in the variable count, and then traversing for the 2nd time for (n – count) nodes 
// to get to the nth node of the list.

// Time Complexity: O(2N)
// Space Complexity: O(1)





// OPTIMAL APPROACH : USING TWO POINTER

// Time Complexity: O(N)
// Space Complexity: O(1)


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};