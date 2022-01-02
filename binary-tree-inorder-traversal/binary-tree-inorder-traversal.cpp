/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>stk;
        TreeNode*curr=root;
        vector<int>inorder;
        while(true)
        {
            if(curr!=NULL)
            {
                stk.push(curr); //push curr node to stack
                curr=curr->left;
            }

            else
            {
                if(stk.empty())break;
                curr=stk.top();
                stk.pop();
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
        return inorder;
    }
};