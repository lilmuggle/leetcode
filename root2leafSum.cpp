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
    int helper(TreeNode* t, int s) {
        if(t) {
            s = s * 10 + t->val;
            int l = helper(t->left, s);
            int r = helper(t->right, s);
            if(l + r == 0)
                return s;
            return l + r;
        }
        return 0;
    }
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
};
