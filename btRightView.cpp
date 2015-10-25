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
    vector<int> v;

    void helper(TreeNode* t, int dep) {
        if(t) {
            if(dep == v.size())
                v.push_back(t->val);
            helper(t->right, dep + 1);
            helper(t->left, dep + 1);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return v;
    }
};
