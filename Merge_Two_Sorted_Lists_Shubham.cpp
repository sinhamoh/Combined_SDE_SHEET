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
// Apprach : recurse with smaller value node
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1) return list2;
        if(!list2) return list1;
        
        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


// Iterative Solution
// Approach : same as merge func of merge sort -> will create new LL
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode *head = new ListNode(), *list3 = head;
        while(list1 && list2) {
            if(list1->val <= list2->val) {
                list3->next = new ListNode(list1->val, NULL);
                list1 = list1->next;
            }
            else {
                list3->next = new ListNode(list2->val, NULL);
                list2 = list2->next;
            }
            list3 = list3->next;
        }
        if(list1) list3->next = list1;
        if(list2) list3->next = list2;
        return head->next;
    }
};