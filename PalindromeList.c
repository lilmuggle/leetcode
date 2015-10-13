/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode *slow, *fast, *tmp, *rev;
    slow = head;
    fast = head;
    rev = NULL;
    while(fast && fast->next) {
        fast = fast->next->next;
        tmp = slow->next;
        slow->next = rev;
        rev = slow;
        slow = tmp;
    }
    if(fast) slow = slow->next;
    while(slow) {
        if(slow->val != rev->val) return false;
        slow = slow->next;
        rev = rev->next;
    }
    return true;
}
