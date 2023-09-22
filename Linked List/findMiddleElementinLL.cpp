// Find middle element in a Linked List

// PROBLEM LINKS:
// LEETCODE: https://leetcode.com/problems/middle-of-the-linked-list/
// CODE STUDIO: https://www.codingninjas.com/studio/problems/973250


// BRUTEFORCE APPROACH:

// We can traverse through the Linked List while maintaining a count of nodes let’s say in variable n, 
// and then traversing for 2nd time for n/2 nodes to get to the middle of the list.

// T.C => O(N) + O(N/2)
// S.C => O(1)

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}
};




// OPTIMAL APPROACH : USING TORTOISE-HARE APPROACH

// In the Tortoise-Hare approach, we increment slow ptr by 1 and fast ptr by 2, 
// so if take a close look fast ptr will travel double that of the slow pointer. 
// So when the fast ptr will be at the end of the Linked List, slow ptr would have covered half of the Linked List till then. 
// So slow ptr will be pointing towards the middle of Linked List.

// Time Complexity: O(N)
// Space Complexity: O(1)


class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }
};
