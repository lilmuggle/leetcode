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
    vector<int> vec;

    void helper(TreeNode* t) {
        vec.push_back(t->val);
        if(t->left)
            helper(t->left);
        if(t->right)
            helper(t->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if(root)
           helper(root);
        return vec;
    }
};

//iteratively
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> stk;
    TreeNode *t = root;
    while(!stk.empty() || t) {
        if(t) {
            vec.push_back(t->val);
            if(t->right)
                stk.push(t->right);
            t= t->left;
        }
        else {
            t = stk.top();
            stk.pop();
        }
    }
    return vec;
}
