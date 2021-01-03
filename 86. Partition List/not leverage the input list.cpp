/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    
    ListNode* l = new ListNode(0); ListNode* l_head = l; 
    ListNode* r = new ListNode(0); ListNode* r_head = r; 
    
    while (head != nullptr)
    {
        auto tmpNode = new ListNode(head->val);
        if (head->val < x)
        {
            l->next = tmpNode;
            l = l->next;
        }
        else
        {
            r->next = tmpNode;
            r = r->next;
        }
        head = head->next;
    }

    r = r_head->next; delete r_head;
    l->next = r;

    l = l_head->next; delete l_head;
    
    return l;
    }
};