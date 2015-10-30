/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode* t) {
    if(!t)
        return 0;
    int l = height(t->left);
    int r = height(t->right);
    return l > r ? l + 1 : r + 1;
}

struct TreeNode* lRotate(struct TreeNode* t) {
    struct TreeNode* p;
    p = t->right;
    t->right = p->left;
    p->left = t;
    return p;
}

struct TreeNode* insert(struct TreeNode* t, int x) {
    if(!t) {
        t = malloc(sizeof(struct TreeNode));
        t->val = x;
        t->left = t->right = NULL;
    }
    else {
        t->right = insert(t->right, x);
        if(height(t->right) - height(t->left) == 2)
            t = lRotate(t);
    }
    return t;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    struct TreeNode* root = NULL;
    while(head) {
        root = insert(root, head->val);
        head = head->next;
    }
    return root;
}
