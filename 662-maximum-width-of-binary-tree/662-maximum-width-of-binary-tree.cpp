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
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int ans = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int size = q.size();
            int min = q.front().second;
            int first,last;
            
            for(int i=0;i<size;i++)
            {
                long long curr_idx = q.front().second - min;
                TreeNode*curr_node = q.front().first;
                q.pop();
                
                if(i == 0) first = curr_idx;
                if(i == size-1) last = curr_idx;
                
                if(curr_node -> left!=NULL)
                    q.push({curr_node->left,2*curr_idx+1});
                
                if(curr_node -> right!=NULL)
                    q.push({curr_node->right,2*curr_idx+2});
            }
            
            ans = max(ans,(last - first + 1));
        }
        
        return ans;
    }
};