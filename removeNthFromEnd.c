/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *cur, *tmp, *pre;

    cur = head;
    tmp = cur;
    for(; n > 0; n--)
        tmp = tmp->next;
    if(tmp == NULL)
    {
        head = head->next;
        return head;
    }
    while(tmp)
    {
        tmp = tmp->next;
        pre = cur;
        cur = cur->next;
    }
    pre->next = cur->next;
    return head;
}
