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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *evenEnd = head->next, *oddEnd = head;
        for(ListNode *p = evenEnd->next; p; p = evenEnd->next) {
            evenEnd->next = p->next;
            p->next = oddEnd->next;
            oddEnd->next = p;
            oddEnd = oddEnd->next;
            evenEnd = evenEnd->next;
            if(!evenEnd)
                return head;
        }
        return head;
    }
};
