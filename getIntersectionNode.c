/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int diff = 0;
    struct ListNode *a, *b;

    a = headA;
    b = headB;
    while(a && b)
    {
        a = a->next;
        b = b->next;
    }
    while(a)
    {
        a = a->next;
        diff++;
    }
    a = headA;
    while(diff)
    {
        a = a->next;
        diff--;
    }
    while(b)
    {
        b = b->next;
        diff++;
    }
    b = headB;
    while(diff)
    {
        b = b->next;
        diff--;
    }
    while(a && b)
    {
        if(a != b)
        {
            a = a->next;
            b = b->next;
        }
        else
            return a;
    }
    return NULL;
}
