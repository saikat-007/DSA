/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
//         unordered_map<Node*,Node*>mp;
//         Node*p=head;
        
//         //creating the deep copies of nodes...without links
        
//         while(p!=NULL)
//         {
//             mp[p]=new Node(p->val);
//             p=p->next;
//         }
        
//         //connecting links
        
//         Node*ptr=head;
//         while(ptr!=NULL)
//         {
//             mp[ptr]->next=mp[ptr->next];
//             mp[ptr]->random=mp[ptr->random];
//             ptr=ptr->next;
//         }
        
//         return mp[head];
        
        
        //O(1) space
        
        
        //step-1 :  make copy of each node,and link them together side-by-side in a single list.
        Node*it=head;
        Node*front=head;
        
        while(it!=NULL)
        {
            front=it->next;
            Node*dc=new Node(it->val);
            it->next=dc;
            dc->next=front;
            it=front;
        }
        
        //step-2: assign random pointers for the copy nodes.
        
        it=head;
        while(it!=NULL)
        {
            if(it->random!=NULL)
            {
                it->next->random=it->random->next;
            }
            it=it->next->next;
        }
        
        // step-3: restore the original list, and extract the copy list.
        it=head;
        Node*dummy=new Node{0};
        Node*cpy=dummy;
        
        while(it!=NULL)
        {
            front=it->next->next;
            cpy->next=it->next;
            cpy=cpy->next;
            it->next=front;
            it=it->next;
        }
        return dummy->next;
    }
};