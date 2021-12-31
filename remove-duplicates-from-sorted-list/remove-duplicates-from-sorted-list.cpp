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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*i=head;
        while(i!=NULL && i->next!=NULL)
        {
            if(i->val == i->next->val)
            {
                ListNode*temp=i->next;
                i->next=temp->next;
                delete(temp);
            }
            else
                i=i->next;
        }
        return head;
    }
};