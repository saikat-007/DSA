/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root)
    {
        if(root == NULL)    
            return NULL;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            Node*curr = q.front();
            q.pop();
            if(curr->left!=NULL)
            {
                curr->left->next = curr->right;
                q.push(curr -> left);
            }
            
            if(curr -> right != NULL)
            {
                if(curr->next != NULL)
                {
                    curr->right->next = curr -> next -> left;
                }
                q.push(curr -> right);
            }
        }
        
        return root;
    }
};