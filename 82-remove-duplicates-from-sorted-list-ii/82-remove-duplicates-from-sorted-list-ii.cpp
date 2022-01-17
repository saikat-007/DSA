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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode*dummy= new ListNode(0);
        dummy->next=head;
    
        ListNode*pre=dummy;
        
        // pre = the last node before the sublist of duplicates
        
        while(head!=NULL && head->next!=NULL)
        {
            // if it's a beginning of duplicates sublist,skip all duplicates
            
            if(head->val == head->next->val)
            {
                while(head->next != NULL && head->val == head->next->val)
                {
                    // moving till the end of duplicates sublist
                    
                    head=head->next;
                }
                // skip all duplicates
                
                pre->next = head->next;
            }
            
            // otherwise, move predecessor
            else
                pre=pre->next;
            
            head = head->next;
        }
        
        return dummy->next;
    }
};