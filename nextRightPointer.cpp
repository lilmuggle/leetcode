/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        TreeLinkNode *pre = NULL, *cur;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            if(!cur) {
                if(q.size() > 0)
                    q.push(NULL);
            }
            else {
                if(cur->left) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            if(pre)
                pre->next = cur;
            pre = cur;
        }
        return;
    }
};
