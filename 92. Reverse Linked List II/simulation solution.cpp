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
class Solution {
private:
    ListNode* ReverseToN(ListNode* Start, int curr, int n, ListNode** Last)
    {
        ListNode* Prev = nullptr;
        ListNode* Curr = Start;
        ListNode* Next = Next;

        while (Curr && curr <= n)
        {
            curr++;
            Next = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = Next;
        }
        auto head = Prev;
        while (head)
        {
            // std::cout << head->val << " || ";
            head = head->next;
        }
        *Last = Next;
        // std::cout << (*Last ? std::to_string((*Last)->val) : "nullptr")  << std::endl;
        return Prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int CurrPos = 0;
        auto tmpHead = ListNode(-1, head);
        ListNode* Prev = &tmpHead;
        ListNode* Curr = head;
        ListNode* ReverseEntry;

        while (Curr)
        {
            CurrPos++;
            auto Next = Curr->next;
            if (CurrPos == m)
            {
                ListNode* Last;
                ReverseEntry = ReverseToN(Curr, m, n, &Last);
                Prev->next = ReverseEntry;
                Curr->next = Last;
                // std::cout << "Prev->next is: " << (ReverseEntry ? std::to_string(ReverseEntry->val) : "nullptr")
                //           << " / Curr->next is: " << (Last ? std::to_string(Last->val) : "nullptr") << endl;
                break;
            }
            // std::cout << "Curr is: " << Curr->val
            //           << " | Prev is: " << (Prev ? std::to_string(Prev->val) : "nullptr") 
            //           << " | Next is: " << (Curr->next ? std::to_string(Curr->next->val) : "nullptr") << std::endl;
            Prev = Curr;
            Curr = Next;
        }

        return tmpHead.next;
    }
};