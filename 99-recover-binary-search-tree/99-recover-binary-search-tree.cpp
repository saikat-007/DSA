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
    vector<int>v;
    int i=0;
    void inorder(TreeNode*root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
        
        else
            return;
    }
    
    void recovering(TreeNode*root)
    {
        if(root != NULL)
        {
            recovering(root -> left);
            
            if(root -> val != v[i])
                 root->val = v[i];
            
            i++;
            
            recovering(root -> right);
        }
    }
    
    void recoverTree(TreeNode* root)
    {
        inorder(root);
        sort(v.begin(),v.end());
        recovering(root);
    }
};