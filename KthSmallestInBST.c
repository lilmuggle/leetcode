/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int helper(struct TreeNode* t) {
    return 1 + helper(t->left) + helper(t->right);
}

int kthSmallest(struct TreeNode* root, int k) {
    int th = 1;
    if(root->left)
        th += helper(root->left);
    if(th == k)
        return root->val;
    if(th > k)
        return kthSmallest(root->left, k);
    else
        return kthSmallest(root->right, k - th);
}
