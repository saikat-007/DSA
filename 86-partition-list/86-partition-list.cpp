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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode*l1=new ListNode{0};
        ListNode*l2=new ListNode{0};
        ListNode*p=head,*q=l1,*r=l2;
        
        while(p!=NULL)
        {
            if(p->val < x)
            {
                q->next=p;
                q=q->next;
                p=p->next;
            }
            else
            {
                r->next=p;
                r=r->next;
                p=p->next;
            }
        }
        r->next=NULL;
        q->next=l2->next;
        return l1->next;
    }
};