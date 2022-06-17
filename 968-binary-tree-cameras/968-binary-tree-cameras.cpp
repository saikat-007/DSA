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
    int dfs(TreeNode*tr , int &sum)
    {
        if(tr == NULL)
            return 1;
        
        int l = dfs(tr->left , sum);
        int r = dfs(tr->right , sum);
        
        if(r == 0 || l == 0)
        {
            sum++;
            return 2;
        }
        
        if(l == 2 || r == 2)
            return 1;
        
        else
            return 0;
    }
    
    int minCameraCover(TreeNode* root)
    {
        int sum = 0 ;
        
        if(dfs(root,sum) == 0) 
            sum++;
        
        return sum;
    }
};