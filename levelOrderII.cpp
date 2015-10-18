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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        TreeNode* t;
        vector<vector<int>> v;
        vector<int> vec;
        queue<TreeNode*> q;
        stack<TreeNode*> s;

        if(!root)
            return v;
        q.push(root);
        q.push(NULL);
        s.push(NULL);
        while(!q.empty()) {
            t = q.front();
            q.pop();
            s.push(t);
            if(!t) {
                if(q.size() > 0)
                    q.push(NULL);
            }
            else {
                if(t->right)
                    q.push(t->right);
                if(t->left)
                    q.push(t->left);
            }
        }
        s.pop();
        while(!s.empty()) {
            t = s.top();
            s.pop();
            if(t == NULL) {
                v.push_back(vec);
                vec.resize(0);
            }
            else
                vec.push_back(t->val);
        }
        return v;sh_back(t->val);
    }
};
