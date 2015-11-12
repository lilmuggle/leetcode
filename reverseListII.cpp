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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        ListNode *p = head, *h = nullptr, *pp, *pre, *tmp;
        for(int count = 1; count < m - 1; count++)
            p = p->next;
        pre = p;
        if(m != 1)
            p = p->next;
        for(int c = 0; c <= n - m; c++) {
            if(h == NULL)
                pp = p;
            tmp = p->next;
            p->next = h;
            h = p;
            p = tmp;
        }
        if(m == 1)
            head = h;
        else
            pre->next = h;
        pp->next = tmp;
        return head;
    }
};

//Others
ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(m==n)return head;
    n-=m;
    ListNode prehead(0);
    prehead.next=head;
    ListNode* pre=&prehead;
    while(--m)pre=pre->next;
    ListNode* pstart=pre->next;
    while(n--)
    {
        ListNode *p=pstart->next;
        pstart->next=p->next;
        p->next=pre->next;
        pre->next=p;
    }
    return prehead.next;
}
