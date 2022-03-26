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
    int getsum(TreeNode*root , bool isleft)
    {
        if(root == NULL)
            return 0;
        
        if(root -> left == NULL && root -> right == NULL)
            return isleft ? root -> val : 0;
        
        return getsum(root -> left , true) + getsum(root -> right , false);
          
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        return getsum(root , false);
    }
};