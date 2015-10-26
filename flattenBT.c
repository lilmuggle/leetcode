/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void flatten(struct TreeNode* root) {
    if(root) {
        struct TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        flatten(root->right);
        flatten(tmp);
        while(root->right)
            root = root->right;
        root->right = tmp;
    }
}
