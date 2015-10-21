/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    int flag = 1;
    struct ListNode *pre, *cur, *tmp;
    pre = head;
    tmp = NULL;
    while(pre) {
        cur = pre->next;
        if(cur) {
            if(flag == 1) {
                flag = 0;
                head = cur;
            }
            if(tmp)
                tmp->next = cur;
            pre->next = cur->next;
            cur->next = pre;
        }
        tmp = pre;
        pre = pre->next;
    }
    return head;
}
