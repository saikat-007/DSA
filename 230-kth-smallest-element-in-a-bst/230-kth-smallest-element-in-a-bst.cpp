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
    void inorder(TreeNode*root , vector<int>&v)
    {
        if(root != NULL)
        {
            inorder(root->left , v);
            v.push_back(root->val);
            inorder(root->right , v);
        }
        
        else
            return;
    }
    int kthSmallest(TreeNode* root, int k)
    {
        vector<int>ans;
        inorder(root,ans);
        
        int n = ans.size();
        return ans[k-1];
    }
};