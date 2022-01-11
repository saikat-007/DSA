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
    int sumRootToLeaf(TreeNode* root, int sum = 0)
    {
        if(!root)
            return 0;
        
         // sum = sum^2 + root->val;     // Normal Math
        sum = sum << 1 | root->val;     // same thing using bits
        
        if(!root->left && !root->right)
            return sum;
        
        return sumRootToLeaf(root->left,sum) + sumRootToLeaf(root->right,sum);
    }
};