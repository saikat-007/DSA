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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(head == NULL)
            return NULL;
        
        ListNode*p=head,*q=head;
        while(n > 0)
        {
            p=p->next;
            n--;
        }
        
        if(p == NULL)
            return head->next; //if p becomes NULL the we have to remove head;
        
        while(p->next!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        ListNode*tmp=q->next;
        q->next=q->next->next;
        delete(tmp);
        return head;
    }
};