/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //Original
struct ListNode* reverseList(struct ListNode* head) {
    int i, len, *a;
    struct ListNode* p;

    i = len = 0;
    p = head;
    while(p)
    {
        len++;
        p = p->next;
    }
    if(len > 1)
    {
        a = (int *)malloc(sizeof(int) * len);
        p = head;
        while(p)
        {
            a[i] = p->val;
            i++;
            p = p->next;
        }
        p = head;
        while(p)
        {
            p->val = a[i - 1];
            i--;
            p = p->next;
        }
    }
    return head;
}

//Others
ListNode* reverseList_iterative(ListNode *head)
{
    ListNode *pre = nullptr, *next = nullptr;
    while (head)
    {
        next = head->next;      //save the current's next node
        head->next = pre;       //let the current point to its previous one
        pre = head;             //save the current node as pre
        head = next;            //move to next node
    }
    return pre;                   //just point to the last node we wanted
}
