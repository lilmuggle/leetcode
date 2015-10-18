/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//Original
struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL)
        return NULL;
    struct TreeNode* l = invertTree(root->left);
    struct TreeNode* r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(!p && !q)
        return true;
    if(p && q) {
        if(p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return true;
    struct TreeNode* r = invertTree(root->right);
    return isSameTree(root->left, r);
}

//After improvement
bool helper(struct TreeNode* p, strcut TreeNode* q) {
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    if(p->val != q->val)
        return false;
    return helper(p->left, q->right) && helper(p->right, q>left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return true;
    return helper(root->left, root->right);
}
