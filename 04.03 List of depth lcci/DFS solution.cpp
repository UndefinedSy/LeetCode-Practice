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
            SearchDepthDFS(tree, 0, results);
        }

        return results;
    }

private:
    void AppendResults(vector<ListNode*>& results, int depth, TreeNode* Node)
    {
        auto tmpNode = new ListNode(Node->val);
        if (results.size() <= depth) // means this is the first node in vector.
        {

            results.emplace_back(tmpNode);
        }
        else
        {            
            auto ResultBucket = results[depth];
            while (ResultBucket->next != nullptr)
                ResultBucket = ResultBucket->next;
            
            ResultBucket->next = tmpNode;
        }
    }

    void SearchDepthDFS(TreeNode* Node, int depth, vector<ListNode*>& results)
    {
        AppendResults(results, depth, Node);
        if (Node->left)
            SearchDepthDFS(Node->left, depth + 1, results);
        if (Node->right)
            SearchDepthDFS(Node->right, depth + 1, results);
    }
};