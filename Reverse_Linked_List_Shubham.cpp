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


// Recursive Solution 
// Approach : Reach to last second node -> update its next node's next ptr to itself  
//            -> update its next ptr to NULL -> return the last node
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next) return head;
        ListNode* rev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
    }
};

// Iterative solution
// Approach : Using three ptr -> store next node in nxt ptr -> update next of cur to prev node
//            -> update prev to cur -> update cur to nxt
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *prev = NULL, *nxt = NULL, *cur = head;
        while(cur)
        {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
