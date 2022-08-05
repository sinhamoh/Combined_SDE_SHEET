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

// Approach same as merge function of merge sort
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int tmp = 0, cy = 0;
        ListNode *dummy = new ListNode();
        ListNode *l3 = dummy;
        while(l1 && l2) {
            tmp = l1->val + l2->val + cy;
            cy = tmp / 10;
            l3->next = new ListNode(tmp % 10, NULL);
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
        while(l1) {
            tmp = l1->val + cy;
            cy = tmp / 10;
            l3->next = new ListNode(tmp % 10, NULL);
            l1 = l1->next;
            l3 = l3->next;
        }
        while(l2) {
            tmp = l2->val +cy;
            cy = tmp / 10;
            l3->next = new ListNode(tmp %10, NULL);
            l2 = l2->next;
            l3 = l3->next;
        }
        if(cy)
            l3->next = new ListNode(cy, NULL);
        return dummy->next;
    }
};

// Approach : Space optmized solution -> creates only one or zero new nodes
//            -> memory usage beats 99.51% cpp slns on leetcode -> faster than 66.15% cpp slns 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int tmp = 0, cy = 0;
        ListNode *h1 = l1, *h2 = l2;
        while(h1 && h2) {
            tmp = h1->val + h2->val + cy;
            cy = tmp / 10;
            h1->val = tmp % 10;
            if(!h1->next && !h2->next && cy) {
                h1->next = new ListNode(cy, NULL);
                h1 = h1->next->next;
            }
            else if(!h1->next) {
                h1->next = h2->next;
                h1 = h1->next;
                break;
            }
            else h1 = h1->next, h2 = h2->next;
        }
        while(h1) {
            tmp = h1->val + cy;
            cy = tmp / 10;  
            h1->val = tmp % 10;
            if(!h1->next && cy) {
                h1->next = new ListNode(cy, NULL);
                h1 = h1->next;
            }
            h1 = h1->next;
        }
        return l1;
    }
};