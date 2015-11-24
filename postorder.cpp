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
    vector<int> res;
    void helper(TreeNode* t) {
        if(t->left)
            helper(t->left);
        if(t->right)
            helper(t->right);
        res.push_back(t->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root)
            helper(root);
        return res;
    }
};

//Iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> visited;
        TreeNode* t = root;
        while(!stk.empty() || t) {
            if(t) {
                if(visited.find(t) == visited.end()) {
                    visited.insert(t);
                    stk.push(t);
                    if(t->right)
                        stk.push(t->right);
                    t = t->left;
                }
                else {
                    res.push_back(t->val);
                    t = NULL;
                }
            }
            else {
                t = stk.top();
                stk.pop();
            }
        }
        return res;
    }
};

/* pre-order is root-left-right, and post is left-right-root.
modify the code for pre-order to make it root-right-left, and
then reverse the output.
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        //base case
        if(root==NULL)
        return result;
        nodeStack.push(root);
    while(!nodeStack.empty())
    {
        TreeNode* node= nodeStack.top();
        result.push_back(node->val);
        nodeStack.pop();
        if(node->left)
        nodeStack.push(node->left);
        if(node->right)
        nodeStack.push(node->right);
    }
     reverse(result.begin(),result.end());
     return result;

}
};

//Another
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> v;
    if (!root) return v;

    stack<TreeNode *> s;
    s.push(root);

    TreeNode *p = NULL;
    while(!s.empty()) {
        p = s.top();
        s.pop();
        v.insert(v.begin(), p->val);
        if (p->left) s.push(p->left);
        if (p->right) s.push(p->right);
    }

    return v;
}
