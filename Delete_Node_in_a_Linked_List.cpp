/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach : It is given that node is not trail node hence just update the val of node with val of next node
//            -> update next of node to next of next of node
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;   
        node->next = node->next->next;   
    }
};