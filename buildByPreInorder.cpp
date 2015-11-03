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
    int n = 0;
    vector<int> pre, in;
    TreeNode* build(int l, int r) {
        if(n == pre.size() || l > r)
            return NULL;
        TreeNode* t = new TreeNode(pre[n]);
        int i;
        for(i = 0; pre[n] != in[i]; i++) {}
        n++;
        t->left = build(l, i - 1);
        t->right = build(i + 1, r);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        return build(0, in.size() - 1);
    }
};
