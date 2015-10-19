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
    vector<string> s;

    void helper(TreeNode* t, string str) {
        str += to_string(t->val);
        if(t->left)
            helper(t->left, str + "->");
        if(t->right)
            helper(t->right, str + "->");
        if(!t->left && !t->right)
            s.push_back(str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root)
            helper(root, "");
        return s;
    }
};
