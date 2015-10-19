/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //Recursive
class Solution {
public:
    vector<int> vec;

    void helper(TreeNode* t) {
        if(t->left)
            helper(t->left);
        vec.push_back(t->val);
        if(t->right)
            helper(t->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if(root)
           helper(root);
        return vec;
    }
};

//iteratively
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> vector;
        stack<TreeNode *> stack;
        TreeNode *pCurrent = root;

        while(!stack.empty() || pCurrent)
        {
            if(pCurrent)
            {
                stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }
            else
            {
                TreeNode *pNode = stack.top();
                vector.push_back(pNode->val);
                stack.pop();
                pCurrent = pNode->right;
            }
        }
        return vector;
    }
};
