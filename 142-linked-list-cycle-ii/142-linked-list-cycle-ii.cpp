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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode*hare=head,*turt=head;
        while(turt!=NULL && turt->next!=NULL)
        {
            hare=hare->next;
            turt=turt->next->next;
            
            if(turt == hare)
            {
                hare=head;
                while(hare!=turt)
                {
                    hare=hare->next;
                    turt=turt->next;
                }
                return hare;
            }
        }
        return NULL;
    }
};