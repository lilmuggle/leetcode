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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = head, *pre = &dummy;
        while(p) {
            int value = p->val;
            if(p->next && value == p->next->val) {
                while(p->next && value == p->next->val)
                    p = p->next;
                pre->next = p->next;
            }
            else
                pre = p;
            p = p->next;
        }
        return dummy.next;
    }
};
