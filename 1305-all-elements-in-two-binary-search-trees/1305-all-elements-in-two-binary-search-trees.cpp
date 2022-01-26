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
    
    void inorder(vector<int>&v,TreeNode* root)
    {
        if(root != NULL)
        {
            inorder(v,root->left);
            v.push_back(root->val);
            inorder(v,root->right);
        }
        else
            return;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int>res;
        vector<int>v1;
        vector<int>v2;
        
        inorder(v1,root1);
        inorder(v2,root2);
        
        for(int i=0;i<v1.size();i++)
            res.push_back(v1[i]);
        
        for(int i=0;i<v2.size();i++)
            res.push_back(v2[i]);
        
        sort(res.begin(),res.end());
        
        return res;
    }
};