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
    
    
    void reorderList(ListNode* head) 
    {
        // step-1 : finding middle of the list using fast and slow pointer
        
        ListNode*slow = head;
        ListNode*fast = head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast=fast->next->next;
        }
        
        //step-2 : Reverse the second half and split the list into two independent list
        
        ListNode*second = reverseList(slow -> next); //second list
        ListNode*first = head;                       //first list
        slow->next = NULL;                           //to break the link with first list
        
        //step-3 : merging the list 
        
        while(second!=NULL)
        {
            ListNode*temp1=first->next;
            first->next=second;
            ListNode*temp2=second->next;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
        
    }
};