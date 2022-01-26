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
    ListNode* swapPairs(ListNode* head)
    {
        if(!head)
            return head;
        
        ListNode* dummy_node = new ListNode(0);
        dummy_node->next=head;
        ListNode*prev = dummy_node , *curr=head;
        
        while(curr!=NULL && curr->next!=NULL)
        {
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return dummy_node->next;
        
    }
};