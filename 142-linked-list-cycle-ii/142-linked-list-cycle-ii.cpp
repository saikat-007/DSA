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
        unordered_set<ListNode*>st;
        
        ListNode*p = head;
        while(st.find(p) == st.end())
        {
            st.insert(p);
            if(p == NULL)
                return NULL;
            
            p = p->next;
        }
        
        return p;
    }
};