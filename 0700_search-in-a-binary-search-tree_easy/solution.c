/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* func(TreeNode* r, int v){
        if(r == NULL) return r;
        if(r->val == v) return r;
        else if(r->val > v) return func(r->left, v);
        return func(r->right, v);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return root;
        TreeNode* ans = func(root, val);
        return ans;
    }
};