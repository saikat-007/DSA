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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode*i=headA,*j=headB,*res;
        int l1=0,l2=0;
        
        while(i!=NULL)
        {
            l1++;
            i=i->next;
        }
        
        while(j!=NULL)
        {
            l2++;
            j=j->next;
        }
        
        i=headA,j=headB;
        
        int diff=abs(l1-l2);
        
        if(l1>l2)
        {
            while(diff!=0 && i!=NULL)
            {
                i=i->next;
                diff--;
            }
        }
        else if(l2>l1)
        {
            while(diff!=0 && j!=NULL)
            {
                j=j->next;
                diff--;
            }
        }
        
        while(i!=NULL && j!=NULL)
        {

            if(i == j)
            {
                return i;
            }
            i=i->next;
            j=j->next;
            
        }
        return NULL;
    }
};