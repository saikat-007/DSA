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
    
    bool isPalindrome(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
            return true;
        
        ListNode*slow = head , *fast = head;
        while(fast -> next != NULL && fast -> next -> next != NULL)
        {
            slow = slow -> next ;
            fast = fast -> next -> next;
        }
        
        slow -> next = reverseList(slow -> next);
        slow = slow -> next;
        ListNode* i = head;
        while(slow!=NULL)
        {
            if(slow -> val != i -> val)
                return false;
            
            slow = slow -> next;
            i = i -> next;
        }
        
        return true;
    }
};