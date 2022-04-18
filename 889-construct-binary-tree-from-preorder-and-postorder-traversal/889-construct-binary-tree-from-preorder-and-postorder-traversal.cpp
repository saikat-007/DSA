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
    unordered_map<int,int>mp;
    
    TreeNode*construct(vector<int>& preorder , vector<int>& postorder , int pre_strt , int pre_end , int post_strt ,int post_end)
    {
        TreeNode* root = new TreeNode(preorder[pre_strt]);
        
        if(pre_strt == pre_end)
            return root;
        
        int tmp = preorder[pre_strt + 1];
        int idx = mp[tmp];
        int len = idx - post_strt + 1;
        
        root -> left = construct(preorder , postorder , pre_strt + 1 , pre_strt + len , post_strt , idx);
        
        if(idx + 1 == post_end)
            return root;
        
        root -> right = construct(preorder , postorder , pre_strt + len + 1 , pre_end , idx + 1 , post_end - 1);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        int len = postorder.size();
        
        for(int i = 0 ; i < postorder.size() ; i++)
        {
            mp[postorder[i]] = i;
        }
        
        return construct(preorder , postorder , 0 , len-1 , 0 , len-1);
    }
    
    
};