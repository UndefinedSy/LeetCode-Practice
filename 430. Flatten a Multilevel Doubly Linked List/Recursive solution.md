/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        auto ResultNode = head;

        if (head)
        {
            RecursivelyIterateChild(head);
        }    

        // for (; head != nullptr; head = head->next)
        // {
        //     TestOutputNode(head);
        // }

        return ResultNode;      
    }

private:

    void TestOutputNode(Node* head)
    {
        std::cout << "This is: " << head->val
                  << " | The prev is: " << (head->prev ? head->prev->val : -1 )
                  << " | The next is: " << (head->next ? head->next->val : -1 )
                  << " | The child is: " << (head->child ? head->child->val : -1 )
                  << std::endl;
    }

    Node* RecursivelyIterateChild(Node* head)
    {
        for ( ; ; )
        {
            if (head->child != nullptr)
            {
                auto OriginalHeadNext = head->next;
                head->next = head->child;
                head->child->prev = head;

                auto TmpRecursiveListTail = RecursivelyIterateChild(head->child);

                if (OriginalHeadNext != nullptr)
                {
                    OriginalHeadNext->prev = TmpRecursiveListTail;
                }
                TmpRecursiveListTail->next = OriginalHeadNext;
                // If you don't clean the child field
                // you will get a "not a valid doubly linked list" error :(
                head->child = nullptr;
            }

            if (head->next == nullptr)
            {
                return head;
            }
            else
            {
                head = head->next;
            }
        }
    }
};