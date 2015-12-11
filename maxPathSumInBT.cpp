/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int res = INT_MIN;
    int pathsum(TreeNode* t) {
        if(!t)
            return 0;
        int l = pathsum(t->left);
        int r = pathsum(t->right);
        int sum = t->val + max(0, max(l + r,max(l, r)));
        res = max(res, sum);
        return t->val + max(l, max(r, 0));
    }
    int maxPathSum(TreeNode* root) {
       pathsum(root);
       return res;
    }
};

