/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*hare=head;
        ListNode*tort=head;
        while(tort!=NULL && tort->next!=NULL)
        {
             hare = hare->next;
             tort = (tort->next)->next;
             if(hare == tort)
             {
                 return true;
                 break;
             }  
        }
        return false;
        
    }
};