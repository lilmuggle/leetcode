/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    if(!root)
        return;
    struct TreeLinkNode *pre = root;
    struct TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next)
                cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
