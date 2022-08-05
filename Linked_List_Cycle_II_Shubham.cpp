/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach : Extention of cycle detection -> detect cycle (slow == fast) -> initialize fast with head
//            -> move fast and slow one by one -> ensures fast and slow will meet at start of loop
class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                fast = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};