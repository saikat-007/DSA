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
//     int height(TreeNode*root)
//     {
//         if(root!=NULL)
//             return max(height(root->left),height(root->right))+1;
        
//         return 0;
//     }
//     int diameterOfBinaryTree(TreeNode* root)
//     {
//         if(root == NULL)
//             return 0;
//         else
//         {
//             int d1 = height(root->left)+height(root->right);
//             int d2=diameterOfBinaryTree(root->left);
//             int d3=diameterOfBinaryTree(root->right);
//             return max(d1,max(d2,d3));
//         }
//     }
    
    int height(TreeNode*root,int&d)
    {
        if(root == NULL)
            return 0;
        
        else
        {
            int lh = height(root->left,d);
            int rh = height(root->right,d);
            d=max(d,lh+rh);
            return 1+max(lh,rh);
        }
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};