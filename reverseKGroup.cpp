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
    ListNode* reverseList(ListNode* head, int count) {
        ListNode* pre = NULL;
        for(;count > 0; count--) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0, times;
        ListNode *p, *pre, *tmp = nullptr;
        for(p = head; p; p = p->next)
            len++;
        if(k <= 1 || k > len)
            return head;
        for(p = head, times = len / k; p && times >= 0; times--) {
            pre = tmp;
            tmp = p;
            for(int count = k; times > 0 && count > 0; count--)
                p = p->next;
            if(tmp == head)
                head = reverseList(tmp, k);
            else {
                pre->next = times == 0 ? p : reverseList(tmp, k);
                pre = tmp;
            }
        }
        return head;
    }
};

//Another
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next)
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
    }
};
