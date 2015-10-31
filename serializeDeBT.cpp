/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Your Codec object will be instantiated and called as such:
 * Codec codec;
 * codec.deserialize(codec.serialize(root));
 */
//level order
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        while(!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if(t == NULL)
                s += "#";
            else {
                stringstream ss;
                ss << t->val;
                s = s + ss.str() + ",";
                q.push(t->left);
                q.push(t->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0, flag = 0;
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);

        while(!q.empty() && i < data.size()) {
            TreeNode** t = q.front();
            q.pop();
            if(data[i] != '#') {
                if(data[i] == '-') {
                    flag = 1;
                    i++;
                }
                int num = data[i++] - '0';
                while(data[i] != ',')
                    num = num * 10 + data[i++] - '0';
                if(flag == 1) {
                    num = -num;
                    flag = 0;
                }
                *t = new TreeNode(num);
                q.push(&((*p)->left));
                q.push(&((*p)->right));
            }
            i++;
        }
        return root;
    }
};

//preorder
class Codec {
private:
    string s;
    int i = 0, flag = 0;
public:
    void seHelper(TreeNode* t) {
        if(t) {
            stringstream ss;
            ss << t->val;
            s = s + ss.str() + ",";
            seHelper(t->left);
            seHelper(t->right);
        }
        else
            s += "#";
    }
    string serialize(TreeNode* root) {
        seHelper(root);
        return s;
    }

    TreeNode* deHelper(string str) {
        if(str[i] == '#') {
            i++;
            return NULL;
        }
        if(str[i] == '-') {
            flag = 1;
            i++;
        }
        int num = str[i++] - '0';
        while(str[i] != ',')
            num = num * 10 + str[i++] - '0';
        if(flag == 1) {
            num = -num;
            flag = 0;
        }
        i++;
        TreeNode *t = new TreeNode(num);
        t->left = deHelper(str);
        t->right = deHelper(str);
        return t;
    }
    TreeNode* deserialize(string data) {
        for(char c : data)
            cout << c;
        return deHelper(data);
    }
};
