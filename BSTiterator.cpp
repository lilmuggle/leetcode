/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> vnext;
    int h, s;
public:

    void helper(TreeNode *t) {
        if(!t)
            return;
        helper(t->left);
        vnext.push_back(t->val);
        helper(t->right);
    }

    BSTIterator(TreeNode *root) {
        helper(root);
        h = 0;
        s = vnext.size();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return h != s;
    }

    /** @return the next smallest number */
    int next() {
        return vnext[h++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

//Others
class BSTIterator {
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != NULL; myStack.push(node), node = node->left);
    }
};
