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
        if(root == NULL)
            return 0;
        
        sum=(sum<<1)+(root->val);
        
        if(root->left == NULL && root->right == NULL)
            return sum;
        
        return sumRootToLeaf(root->left,sum) + sumRootToLeaf(root->right,sum);
          
    }
};