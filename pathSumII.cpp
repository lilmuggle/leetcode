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
    vector<vector<int>> vec;
    vector<int> v;

    void backtrack(TreeNode* t, int n) {
        if(!t->left && !t->right && n - t->val == 0) {
            v.push_back(t->val);
            vec.push_back(v);
            v.pop_back();
        }
        else {
            v.push_back(t->val);
            if(t->left)
                backtrack(t->left, n - t->val);
            if(t->right)
                backtrack(t->right, n - t->val);
            v.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root)
            backtrack(root, sum);
        return vec;
    }
};
