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
    void deleteNode(ListNode* node)
    {
//         ListNode* p = node;
//         ListNode* q = node -> next;
        
//         while(q != NULL)    
//         {
//             node -> val = q -> val;
//             p = node;
//             node = node -> next;
//             q = q -> next;
//         }
        
//         p -> next = 0;
        
        ListNode * p = node;
        p -> val = p -> next -> val;
        p -> next = p -> next -> next;
    }
};