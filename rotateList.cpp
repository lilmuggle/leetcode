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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *p, *tail, *pre;
        for(p = head; p ; p = p->next) {
            tail = p;
            len++;
        }
        k = len == 0 ? 0 : k % len;
        k = len - k;
        if(len < 2 || k == len)
            return head;
        for(p = head; k != 0; p = p->next, k--)
            pre = p;
        tail->next = head;
        pre->next = NULL;
        return p;
    }
};
