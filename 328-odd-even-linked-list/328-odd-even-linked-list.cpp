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
    ListNode* oddEvenList(ListNode* head)
    {
        if(head == NULL) return NULL;
        ListNode*odd_indices=head,*even_indices=head->next,*even_head=even_indices;
        
        while(even_indices!=NULL && even_indices->next!=NULL)
        {
            //Putting the odd indices together
            odd_indices->next=even_indices->next;
            odd_indices=odd_indices->next;
            
            //Putting the even indices together
            even_indices->next=odd_indices->next;
            even_indices=even_indices->next;
        }
        
        //connecting even_indices list to the tail of odd_indices
        odd_indices->next = even_head;
        return head;
        
    }
};