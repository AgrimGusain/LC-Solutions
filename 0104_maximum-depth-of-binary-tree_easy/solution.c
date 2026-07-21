class Solution {
public:
    int func(TreeNode* r) {
        if(r == nullptr) return 0; 
        int l = func(r->left);
        int ri = func(r->right);
        return 1 + max(l, ri); 
    }

    int maxDepth(TreeNode* root) {
        return func(root);
    }
};
