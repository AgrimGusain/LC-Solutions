class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        qu.push(root);

        while (!qu.empty()) {
            int size = qu.size();       
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* temp = qu.front();
                qu.pop();
                level.push_back(temp->val);

                if (temp->left != NULL) qu.push(temp->left);
                if (temp->right != NULL) qu.push(temp->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
