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
    int pos = 0;
    vector<int> tmp;
    void helper(TreeNode* t) {
        if(!t)
            return;
        helper(t->left);
        tmp.push_back(t->val);
        helper(t->right);
    }
    void recover(TreeNode* t) {
        if(!t)
            return;
        recover(t->left);
        t->val = tmp[pos++];
        recover(t->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        sort(tmp.begin(), tmp.end());
        recover(root);
    }
};

//In-order traverse
class Solution {
public:
    TreeNode *pre = nullptr, *mistake1 = nullptr, *mistake2 = nullptr;
    void helper(TreeNode* t) {
        if(!t)
            return;
        helper(t->left);
        if(pre != NULL) {
            if(!mistake1 && t->val < pre->val)
                mistake1 = pre;
            if(mistake1 && t->val < pre->val)
                mistake2 = t;
        }
        pre = t;
        helper(t->right);
    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(mistake1->val, mistake2->val);
    }
};
