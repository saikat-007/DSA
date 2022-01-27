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
    TreeNode*buildTree(int low,int high,vector<int>&v)
    {
        if(low > high)
            return NULL;
        
        int mid=low+(high-low)/2;
        TreeNode*root = new TreeNode(v[mid]);
        root->left = buildTree(low,mid-1,v);
        root->right = buildTree(mid+1,high,v);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int n = nums.size()-1;
        TreeNode*root = new TreeNode(0); 
        root = buildTree(0,n,nums);
        return root;
    }
};