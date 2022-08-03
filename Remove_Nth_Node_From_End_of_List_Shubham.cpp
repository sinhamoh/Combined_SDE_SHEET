/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Approach : Use two ptr -> move fast ptr ny n times -> now move slow and fast ptr together 
//            -> upadate the next ptr of slow to next of next of slow -> to handle the case of removal  
//            of head add an extra node in begining 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *start = new ListNode(0, head);
        ListNode *slow = start, *fast = start;
        while(n--)
            fast = fast->next;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};