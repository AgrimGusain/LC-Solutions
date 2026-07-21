# Binary Tree Level Order Traversal

## Problem Description
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]


Example 2:

Input: root = [1]
Output: [[1]]


Example 3:

Input: root = []
Output: []


 
Constraints:


	The number of nodes in the tree is in the range [0, 2000].
	-1000 <= Node.val <= 1000



## My Code
```cpp
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

```

## Code Explanation
The provided code is a solution to the "Binary Tree Level Order Traversal" problem. Here's a step-by-step breakdown of how it works:
1. It first checks if the root of the binary tree is `NULL`. If it is, the function returns an empty vector, as there are no nodes to traverse.
2. It then initializes an empty vector `ans` to store the level order traversal of the tree and a queue `qu` to store the nodes to be processed.
3. The root node is pushed into the queue `qu`.
4. The code then enters a while loop that continues until the queue `qu` is empty.
5. Inside the loop, it calculates the size of the current level by getting the size of the queue `qu`.
6. It then iterates over each node in the current level. For each node, it removes the node from the front of the queue, adds its value to the `level` vector, and pushes its left and right children (if they exist) into the queue.
7. After processing all nodes in the current level, it adds the `level` vector to the `ans` vector.
8. This process continues until the queue is empty, at which point the `ans` vector contains the level order traversal of the binary tree.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the number of nodes in the binary tree. This is because each node is visited exactly once and added to the queue. The while loop runs for each level of the tree, and inside the loop, we process each node in the current level. This results in a linear time complexity.
- **Space Complexity:** The space complexity is O(n), where n is the number of nodes in the binary tree. This is because in the worst case (when the tree is a complete binary tree), the queue will store n/2 nodes at the last level. The `ans` vector will also store n nodes in total, resulting in a space complexity of O(n).

## Optimizations
The provided code is already quite efficient and has a time complexity of O(n) and a space complexity of O(n). However, it's worth noting that this is the optimal time and space complexity for this problem, as we must visit each node at least once to perform the level order traversal. 
One minor optimization could be to check if the left or right child of a node exists before pushing it into the queue. However, this check is already performed in the code.

## Interview Explanation
So, to explain this solution to an interviewer, I would start by saying something like: 
"Okay, so the problem asks us to perform a level order traversal of a binary tree, which means we need to visit all the nodes at each level of the tree from left to right before moving on to the next level. 
The approach I took to solve this problem is to use a queue data structure. I initialize a queue and push the root node into it. Then, I enter a while loop that continues until the queue is empty. 
Inside the loop, I calculate the size of the current level by getting the size of the queue. This is because all the nodes in the queue at this point are at the same level. 
I then iterate over each node in the current level. For each node, I remove it from the front of the queue, add its value to a vector representing the current level, and push its left and right children (if they exist) into the queue. 
This way, when I've processed all the nodes in the current level, the queue will contain all the nodes at the next level. 
I continue this process until the queue is empty, at which point I've visited all the nodes in the tree and have their values stored in a vector of vectors, where each inner vector represents a level of the tree. 
In terms of time and space complexity, this solution is O(n) because we visit each node exactly once and store all the nodes in the queue and the result vector. 
This is the optimal time and space complexity for this problem because we must visit each node at least once to perform the level order traversal."