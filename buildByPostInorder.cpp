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
    int n;
    vector<int> post, in;
    TreeNode* build(int l, int r) {
        if(n == -1 || l > r)
            return NULL;
        TreeNode* t = new TreeNode(pre[n]);
        int i;
        for(i = 0; pre[n] != in[i]; i++) {}
        n--;
        t->left = build(l, i - 1);
        t->right = build(i + 1, r);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = postorder.size() - 1;
        post = postorder;
        in = inorder;
        return build(0, in.size() - 1);
    }
};
