/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return l>r?l+1:r+1;
}

bool isBalanced(struct TreeNode* root) {
    if(root == NULL)
        return true;
    int ldep = maxDepth(root->left);
    int rdep = maxDepth(root->right);
    if(ldep - rdep > 1 || ldep - rdep < -1)
        return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
