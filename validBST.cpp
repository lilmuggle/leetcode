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
    int pre, flag = 1;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(isValidBST(root->left)) {
            if(flag == 1 || root->val > pre) {
                flag = 0;
                pre = root->val;
                return isValidBST(root->right);
            }
        }
        return false;
    }
};

