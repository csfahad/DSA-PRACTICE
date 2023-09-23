// Add two numbers represented as Linked Lists

// PROBLEM LINKS:
// LEETCODE: https://leetcode.com/problems/add-two-numbers/
// CODE STUDIO: https://leetcode.com/problems/add-two-numbers/


// APPROACH : ELEMENTARY MATH

// Intuition: Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of the list, 
// which contains the least significant digit.


// Time Complexity: O(max(m,n)). Assume that m and n represent the length of l1 and l2 respectively, 
// the algorithm above iterates at most max(m,n) times.

// Space Complexity: O(max(m,n)). The length of the new list is at most max(m,n)+1.



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};