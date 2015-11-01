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
    vector<TreeNode*> build(int left, int right) {
        vector<TreeNode*> res;
        if(left > right)
            res.push_back(nullptr);
        else {
            for(int i = left; i <= right; i++) {
                vector<TreeNode*> l = build(left, i - 1);
                vector<TreeNode*> r = build(i + 1, right);
                for(TreeNode* ll : l) {
                    for(TreeNode* rr : r) {
                        TreeNode* t = new TreeNode(i);
                        t->left = ll;
                        t->right = rr;
                        res.push_back(t);
                    }
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return build(1 , n);
    }
};

//DP
class Solution {
    public:
        TreeNode* clone(TreeNode* root){
            if(root == nullptr)
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
        }
        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode *> res(1,nullptr);
            for(int i = 1; i <= n; i++){
                vector<TreeNode *> tmp;
                for(int j = 0; j<res.size();j++){
                    TreeNode* oldroot = res[j];
                    TreeNode* root = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    root->left = target;
                    tmp.push_back(root);

                    if(oldroot!=nullptr){
                        TreeNode* tmpold = oldroot;
                        while(tmpold->right!=nullptr){
                            TreeNode* nonroot = new TreeNode(i);
                            TreeNode *tright = tmpold->right;
                            tmpold->right = nonroot;
                            nonroot->left = tright;
                            TreeNode *target = clone(oldroot);
                            tmp.push_back(target);
                            tmpold->right = tright;
                            tmpold = tmpold->right;
                        }
                        tmpold->right = new TreeNode(i);
                        TreeNode *target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = nullptr;
                    }
                }
                res=tmp;
            }
            return res;
        }
    };
