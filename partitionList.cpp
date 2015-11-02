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
    ListNode* partition(ListNode* head, int x) {
        ListNode *cur = head, *start = nullptr, *pre = nullptr;
        while(cur) {
            if(cur->val < x) {
                if(cur == head)
                    start = cur;
                else {
                    ListNode *tmp = cur;
                    pre->next = tmp->next;
                    if(start) {
                        tmp->next = start->next;
                        start->next = tmp;
                        start = start->next;
                    }
                    else {
                        tmp->next = head;
                        head = start = tmp;
                    }
                }
            }
            pre = cur;
            cur = cur->next;
        }
        return head;
    }
};

// separate the list into 2 distinct lists and link them afterwards
ListNode *partition(ListNode *head, int x) {
    ListNode node1(0), node2(0);
    ListNode *p1 = &node1, *p2 = &node2;
    while (head) {
        if (head->val < x)
            p1 = p1->next = head;
        else
            p2 = p2->next = head;
        head = head->next;
    }
    p2->next = NULL;
    p1->next = node2.next;
    return node1.next;
}
