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
    vector<int>inorder;
    
    void in(TreeNode*root)
    {
        if(root!=NULL)
        {
            in(root->left);
            inorder.push_back(root->val);
            in(root->right);
        }
        
        else
            return;
    }
    
    TreeNode* makeTree(int low,int high)
    {
        if(low > high)
            return NULL;
        
        int mid=low+(high-low)/2;
        TreeNode*root = new TreeNode(inorder[mid]);
        root->left = makeTree(low,mid-1);
        root->right = makeTree(mid+1,high);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        
        in(root);
        int n = inorder.size();
        root=makeTree(0,n-1);
        return root;
    }
};