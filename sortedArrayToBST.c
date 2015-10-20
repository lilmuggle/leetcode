/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* helper(int* a, int low, int high) {
    if(low > high)
        return NULL;
    struct TreeNode* t;
    int mid = low + (high - low) / 2;
    t = malloc(sizeof(struct TreeNode));
    t->val = nums[mid];
    t->left = helper(nums, low, mid - 1);
    t->right = helper(nums, mid + 1, high);
    return t;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    struct TreeNode* bst;
    bst = helper(nums, 0, numsSize - 1);
    return bst;
}
