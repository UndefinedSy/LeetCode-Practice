/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> results;
        
        if (tree != nullptr)
        {
            SearchDepthBFS(tree, results);
        }

        return results;
    }

private:
    void SearchDepthBFS(TreeNode* Node, vector<ListNode*>& results)
    {
        std::queue<TreeNode*> PendedTreeNodesQueue;
        PendedTreeNodesQueue.push(Node);

        while (!PendedTreeNodesQueue.empty())
        {
            auto PendedSize = PendedTreeNodesQueue.size();
            
            ListNode* current;
            for (int i = 0; i < PendedSize; ++i)
            {
                auto tmpTreeNode = PendedTreeNodesQueue.front();
                PendedTreeNodesQueue.pop();

                auto tmpListNode = new ListNode(tmpTreeNode->val);
                if (i == 0) { current = tmpListNode; results.push_back(current); }
                else { current->next = tmpListNode; current = current->next; }

                if (tmpTreeNode->left)
                    PendedTreeNodesQueue.push(tmpTreeNode->left);
                if (tmpTreeNode->right)
                    PendedTreeNodesQueue.push(tmpTreeNode->right);
            }
        }
    }
};