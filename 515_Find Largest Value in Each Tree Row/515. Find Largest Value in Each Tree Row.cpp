/************************************************
You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]
************************************************/
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // ！nullprt error solution
        if (root == nullptr) {
            return {};
        }
        
        vector<int> res;
        queue<int> lev;
        queue<TreeNode*> q;
        int levLabel = -1;

        lev.push(0);
        q.push(root);
        while (q.size()) {
            TreeNode* curNode = q.front();
            int curLev = lev.front();
            q.pop();
            lev.pop();
            if (curNode->left) {
                lev.push(curLev+1);
                q.push(curNode->left);
            }
            if (curNode->right) {
                lev.push(curLev+1);
                q.push(curNode->right);
            }
            if (curLev > levLabel) {    // get into next row
                levLabel = curLev;
                res.push_back(curNode->val);
            }
            else {
                res[curLev] = max(res[curLev], curNode->val);
            }
        }
        return res;
    }
};