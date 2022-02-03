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
    void inorder(vector<int>&v,TreeNode*root)
    {
        if(root!=NULL)
        {
            inorder(v,root->left);
            v.push_back(root->val);
            inorder(v,root->right);
        }
        
        else
            return;
    }
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        vector<int>v;
        int sum=0;
        inorder(v,root);
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>=low && v[i]<=high)
                sum+=v[i];
        }
        
        return sum;
    }
};









