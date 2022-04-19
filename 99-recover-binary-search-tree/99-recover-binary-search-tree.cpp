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
    /*
    !------------Brute force----------!
    
    vector<int>v;
    int i=0;
    void inorder(TreeNode*root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
        
        else
            return;
    }
    
    void recovering(TreeNode*root)
    {
        if(root != NULL)
        {
            recovering(root -> left);
            
            if(root -> val != v[i])
                 root->val = v[i];
            
            i++;
            
            recovering(root -> right);
        }
    }
    
    void recoverTree(TreeNode* root)
    {
        inorder(root);
        sort(v.begin(),v.end());
        recovering(root);
    }
    
    */
    
    
    //optimised
    TreeNode*first,*prev,*middle,*last;
    
    void inorder(TreeNode*root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            
            if(prev != NULL && (root -> val) < (prev -> val))
            {
                if(first == NULL)
                {
                    first = prev;
                    middle = root;
                }
                
                else
                    last = root;
            }
            
            prev = root;
            
            inorder(root -> right);
        }
        
        else
            return;
    }
    
    void recoverTree(TreeNode* root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        
        inorder(root);
        if(first && last)
            swap(first->val , last->val);
        
        else if(first && middle)
            swap(first->val , middle->val);
            
    }
};