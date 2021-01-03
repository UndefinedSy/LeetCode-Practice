/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        
        std::queue<Node*> PendedNodes;
        PendedNodes.push(root);

        while (!PendedNodes.empty())
        {
            auto CurrentWidth = PendedNodes.size();

            for (int i = 0; i < CurrentWidth; ++i)
            {
                auto TmpNode = PendedNodes.front();
                PendedNodes.pop();

                if (TmpNode->left != nullptr)
                {
                    PendedNodes.push(TmpNode->left);
                    PendedNodes.push(TmpNode->right);
                }

                if (i != CurrentWidth - 1)
                {
                    TmpNode->next = PendedNodes.front();
                }
            }
        }
        return root;
    }
};