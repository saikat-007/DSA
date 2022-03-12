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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>>res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty())
        {
            int count = q.size();
            
            vector<int>temp;
            for(int i=0;i<count;i++)
            {
                TreeNode*curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
            
            if(level % 2 == 0)
                res.push_back(temp);
            
            else
            {
                reverse(temp.begin(),temp.end());
                res.push_back(temp);
            }
            
            level++;
        }
        
        return res;
    }
};