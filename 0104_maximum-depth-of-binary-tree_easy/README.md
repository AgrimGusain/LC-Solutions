# Maximum Depth Of Binary Tree

## Problem Description
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 
Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3


Example 2:

Input: root = [1,null,2]
Output: 2


 
Constraints:


	The number of nodes in the tree is in the range [0, 104].
	-100 <= Node.val <= 100



## My Code
```cpp
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
```

## Code Explanation
The given code is a solution to the "Maximum Depth Of Binary Tree" problem, where it calculates the maximum depth of a binary tree. Here's a step-by-step breakdown of how the code works:

1. **Base Case**: It first checks if the root node is `NULL`, in which case it returns `0` because there are no nodes in the tree.
2. **Initializing a Stack**: It initializes a stack to store pairs of `TreeNode` pointers and their corresponding depths.
3. **Pushing the Root Node**: It pushes the root node onto the stack with a depth of `1`.
4. **Iterating Through the Stack**: It enters a while loop that continues until the stack is empty.
5. **Popping a Node**: Inside the loop, it pops a node from the stack and updates the `maxdepth` if the current depth is greater than the maximum depth found so far.
6. **Pushing Child Nodes**: If the popped node has a right child or a left child, it pushes them onto the stack with their corresponding depths (i.e., the current depth plus one).
7. **Returning the Maximum Depth**: Once the stack is empty, it returns the `maxdepth`, which is the maximum depth of the binary tree.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is **O(n)**, where n is the number of nodes in the binary tree. This is because each node is visited exactly once and pushed onto the stack.
- **Space Complexity:** The space complexity of this solution is **O(n)** in the worst case, which occurs when the tree is completely unbalanced (i.e., each node has only one child). This is because the maximum depth of the recursion call stack or the number of nodes in the stack can go up to n.

## Optimizations
The given code is already quite efficient. However, some minor improvements could be made:
- Instead of using a stack, we could use a recursive approach with a depth-first search (DFS) to find the maximum depth. This would simplify the code but might lead to a stack overflow error for very large trees due to Python's recursion limit.
- We could also consider using a level-order traversal (BFS) approach using a queue to find the maximum depth, but this would likely be slower than the DFS approach for very deep trees.

## Interview Explanation
Here's a conversational script on how to explain the solution to an interviewer:

"Okay, so the problem requires us to find the maximum depth of a binary tree. To solve this, I've used an iterative approach with a stack.

"First, we check if the root node is NULL. If it is, we return 0 because there are no nodes in the tree.

"Next, we initialize a stack to store pairs of tree nodes and their corresponding depths. We start by pushing the root node onto the stack with a depth of 1.

"Then, we enter a loop that continues until the stack is empty. Inside the loop, we pop a node from the stack and update the maximum depth if the current depth is greater than the maximum depth found so far.

"After that, we check if the popped node has any child nodes. If it does, we push them onto the stack with their corresponding depths, which is the current depth plus one.

"We repeat this process until the stack is empty. At that point, we've visited all the nodes in the tree, and the maximum depth variable will hold the correct value.

"In terms of time and space complexity, this solution has a time complexity of O(n), where n is the number of nodes in the tree, because we visit each node exactly once. The space complexity is also O(n) in the worst case, which occurs when the tree is completely unbalanced.

"I chose an iterative approach over a recursive one to avoid potential stack overflow errors for very large trees. However, a recursive approach could also be used, and it would likely be simpler to implement. But for very deep trees, the iterative approach is generally safer.

"Overall, this solution is efficient and easy to understand, and it handles all the edge cases correctly."