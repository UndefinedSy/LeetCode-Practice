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
        if (head->val < x)
        {
            l->next = head;
            l = head;
        }
        else
        {
            r->next = head;
            r = head;
        }

        head = head->next;
    }

    r->next = nullptr;  // cleanup the last node to avoid circle.

    r = r_head->next; delete r_head;    // remove the virtual head
    l->next = r;

    l = l_head->next; delete l_head;    // remove the virtual head
    // PrintLinkedList(l);
    return l;
    }
private:
    void PrintLinkedList(ListNode* head)
    {
        while (head != nullptr)
        {
            std::cout << head->val << (head->next == nullptr ? "\n" : " -> ");
            head = head->next;
        }
    }
};