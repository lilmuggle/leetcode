/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//Original
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level, lastlevel = -1;
        queue<struct TreeNode*> q1;
        queue<int> q2;
        vector<vector<int>> v;
        vector<int> vec;
        struct TreeNode* t;

        if(root) {
            q1.push(root);
            q2.push(0);
        }
        while(!q1.empty() && !q2.empty()) {
            t = q1.front();
            level = q2.front();
            q1.pop();
            q2.pop();
            if(level != lastlevel) {
                lastlevel = level;
                v.push_back(vec);
            }
            v[level].push_back(t->val);

            if(t->left) {
                q1.push(t->left);
                q2.push(level + 1);
            }
            if(t->right) {
                q1.push(t->right);
                q2.push(level + 1);
            }
        }
        return v;
    }
};

//Others
vector<vector<int>> ret;

void buildVector(TreeNode *root, int depth)
{
    if(root == NULL) return;
    if(ret.size() == depth)
        ret.push_back(vector<int>());

    ret[depth].push_back(root->val);
    buildVector(root->left, depth + 1);
    buildVector(root->right, depth + 1);
}

vector<vector<int> > levelOrder(TreeNode *root) {
    buildVector(root, 0);
    return ret;
}
