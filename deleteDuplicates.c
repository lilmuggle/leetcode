/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p, *tmp;

    p = head;
    if(p)
    {
        while(p->next)
        {
            if(p->val == p->next->val)
            {
                tmp = p->next;
                p->next = tmp->next;
                free(tmp);
            }
            else
                p = p->next;
        }
    }
    return head;
}
