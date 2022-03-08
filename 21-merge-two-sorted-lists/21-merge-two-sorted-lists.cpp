/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if(l1 == NULL)
//             return l2;
        
//         else if(l2 == NULL)
//             return l1;
        
//         ListNode*head=new ListNode{0};   //head pointer for merged list
//         if(l1->val < l2->val)
//         {
//             head->next=l1;
//             l1=l1->next;
//         }
        
//         else
//         {
//             head->next=l2;
//             l2=l2->next;
//         }
        
//         ListNode*it=head->next; //pointer to new list
//         while(l1!=NULL && l2!=NULL)
//         {
//             if(l1->val < l2->val)
//             {
//                 it->next=l1;
//                 l1=l1->next;
//             }
//             else
//             {
//                  it->next = l2;
//                  l2 = l2->next;
//             }
//             it=it->next;
//         }
        
//         if(l1!=NULL)
//         {
//             it->next=l1;
//         }
        
//         if(l2!=NULL)
//         {
//             it->next=l2;
//         }
        
//         return head->next;
//     }
// };
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        
        ListNode*root=NULL;
        if(l1->val <= l2->val)root=l1;
        else root=l2;
        
        ListNode*temp=NULL;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                if(temp!=NULL)
                    temp->next=l1;
                
                temp=l1;
                l1=l1->next;
            }
            
            else
            {
                if(temp!=NULL)
                    temp->next=l2;
                
                temp=l2;
                l2=l2->next;
            }
        }
        
        if(l1) temp->next=l1;
        else temp->next=l2;
        
        return root;
    }
};