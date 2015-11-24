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
     ListNode* reverseList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur && cur -> next) {
            ListNode* temp = pre -> next;
            pre -> next = cur -> next;
            cur -> next = cur -> next -> next;
            pre -> next -> next = temp;
        }
        return new_head -> next;
    }
    ListNode* mergeLists(ListNode *l1, ListNode *l2) {
        int flag = 0;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 && l2) {
            if(flag == 0) {
                tail->next = l1;
                l1 = l1->next;
                flag = 1;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
                flag = 0;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *pre, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        head = mergeLists(head, reverseList(slow));
    }
};
