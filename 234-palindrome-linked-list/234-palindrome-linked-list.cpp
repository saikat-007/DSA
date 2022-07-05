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
    ListNode* reverse(ListNode*head)
    {
        ListNode*dummy = NULL;
        while(head!=NULL)
        {
            ListNode*nxt = head->next;
            head->next = dummy;
            dummy = head;
            head = nxt;
        }
        
        return dummy;
    }
    
    bool isPalindrome(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
            return true;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow = slow -> next;
            fast = fast -> next ->next;
        }
        
        slow -> next = reverse(slow -> next);
        slow = slow -> next;
        
        ListNode* i = head;
        
        while(slow!=NULL)
        {
            if(i -> val != slow -> val)    
                return false;
            
            slow = slow -> next;
            i = i -> next;
        }
        
        return true;
    }
};