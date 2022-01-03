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
    bool check(TreeNode*leftsub,TreeNode*rightsub)
    {
        if(leftsub == NULL && rightsub == NULL)
            return true;
        
        else if(leftsub != NULL && rightsub != NULL)
        {
            return (leftsub->val == rightsub->val) && check(leftsub->left,rightsub->right) && check(leftsub->right,rightsub->left);
        }
        return false;
    }
    
    bool isSymmetric(TreeNode* root)
    {
        return root == NULL || check(root->left,root->right);
    }
};