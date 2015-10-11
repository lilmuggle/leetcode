/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //Original
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *pre, *cur;

    pre = NULL;
    cur = head;
    while(cur)
    {
        if(cur->val == val)
        {
            if(pre == NULL)
            {
                head = head->next;
                pre = NULL;
            }
            else
            {
                pre->next = cur->next;
            }
        }
        else
            pre = cur;
        cur = cur->next;
    }
    return head;
}

//Recursive solution
public ListNode removeElements(ListNode head, int val) {
        if (head == null) return null;
        head.next = removeElements(head.next, val);
        return head.val == val ? head.next : head;
}

//Another
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode **pp, *p;

    pp = &head;
    while (*pp) {
        p = *pp;
        if ((*pp)->val == val) { /* found one */
            *pp = p->next;
            free(p);
        } else
            pp = &p->next;
    }

    return head;
}
