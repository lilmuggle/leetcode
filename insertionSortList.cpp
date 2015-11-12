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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *h, *pre, *pp = nullptr, *p = head;
        while(p) {
            pre = nullptr;
            for(h=head; h->val<=p->val&&h!=p; h=h->next) {
                pre = h;
            }
            if(h == p)
                pp = p;
            else {
                if(pre == NULL) {
                    ListNode *tmp = pp;
                    pp->next = p->next;
                    p->next = head;
                    head = p;
                    pp = tmp;
                }
                else {
                    pre->next = p;
                    pp->next = p->next;
                    p->next = h;
                }
            }
            p = p->next;
        }
        return head;
    }
};
