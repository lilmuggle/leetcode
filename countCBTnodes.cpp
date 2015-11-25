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
    vector<int> helper(TreeNode* t) {
        vector<int> level(2, 0);
        if(t) {
            for(TreeNode* p = t; p ; p = p->left, level[0]++) {}
            for(TreeNode* p = t; p ; p = p->right, level[1]++) {}
        }
        return level;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> level = helper(root->left);
        if(level[0] == level[1])
            return pow(2, level[0]) + countNodes(root->right);
        else
            return pow(2, level[1]) + countNodes(root->left);
    }
};

class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};
