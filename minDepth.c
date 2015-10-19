/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root) {
    if(!root)
        return 0;
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    if(rh != 0 && lh != 0)
        return lh < rh ? lh + 1 : rh + 1;
    return lh > rh ? lh + 1 : rh + 1;
}
