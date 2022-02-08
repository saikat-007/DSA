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
    ListNode* reverseList(ListNode* head)
    {
        ListNode*dummy=NULL;
        while(head!=NULL)
        {
            ListNode*next = head->next;
            head->next = dummy;
            dummy = head;
            head = next;
        }
        
        return dummy;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode*head1=reverseList(l1);
        ListNode*head2=reverseList(l2);
        
        ListNode*p=head1,*q=head2;
        int carry=0;
        ListNode*dummy=new ListNode{0},*curr=dummy;
        
        while(p || q)
        {
            int x = (p!=NULL)?p->val:0;
            int y = (q!=NULL)?q->val:0;
            
            int sum = x+y+carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr=curr->next;
            
            if(p!=NULL)
                p=p->next;
            
            if(q!=NULL)
                q=q->next;
        }
        
        if(carry > 0)
            curr->next = new ListNode(carry);
        
        return reverseList(dummy->next);
    }
};