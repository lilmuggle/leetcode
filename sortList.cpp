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
    ListNode* mergeLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *pre, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return mergeLists(sortList(head), sortList(slow));
    }
};
