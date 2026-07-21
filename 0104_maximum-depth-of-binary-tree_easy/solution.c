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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        stack<pair<TreeNode* , int>> st;
        st.push({root, 1});
        int maxdepth = 0;

        while(!st.empty()){
            auto [curr, depth] = st.top();
            st.pop();
            maxdepth = max(maxdepth, depth);
            if(curr->right) st.push({curr->right, 1+depth});
            if(curr->left) st.push({curr->left, 1+depth});
        }

        return maxdepth;

    }
};