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

```

## Code Explanation
The given code is a solution to the "Maximum Depth Of Binary Tree" problem on LeetCode. It calculates the maximum depth of a binary tree by recursively traversing the tree and keeping track of the maximum depth encountered. Here's a step-by-step breakdown of how the code works:
- The solution defines a recursive function `func` that takes a `TreeNode` `r` as an argument. This function calculates the maximum depth of the subtree rooted at `r`.
- If `r` is `nullptr`, the function returns 0, indicating that the subtree is empty and has no depth.
- Otherwise, the function recursively calculates the maximum depth of the left and right subtrees by calling `func` on `r->left` and `r->right`, respectively. The results are stored in the variables `l` and `ri`.
- The function then returns 1 plus the maximum of `l` and `ri`, which represents the maximum depth of the subtree rooted at `r`. The `+ 1` accounts for the current node `r`.
- The `maxDepth` function simply calls `func` on the `root` node and returns the result.

## Complexity Analysis
- **Time Complexity:** The time complexity of the given code is O(N), where N is the number of nodes in the binary tree. This is because each node is visited once during the recursive traversal.
- **Space Complexity:** The space complexity of the given code is O(H), where H is the height of the binary tree. This is because the maximum recursion depth is equal to the height of the tree, which in the worst case can be N (for an unbalanced tree) but is log(N) for a balanced tree.

## Optimizations
The given code is already quite optimal for this problem. However, here are a few potential suggestions:
- Instead of defining a separate `func` and `maxDepth` function, the recursive logic can be embedded directly into `maxDepth`.
- Error checking can be added to handle cases where the input tree is not a valid binary tree (e.g., a node has more than two children).
- For extremely large trees, an iterative solution using a queue or stack can be used to avoid the potential for stack overflow due to deep recursion.

## Interview Explanation
Here's how a candidate should verbally explain this solution to an interviewer:
"Okay, so the problem asks us to find the maximum depth of a binary tree. To approach this, I used a recursive solution. The idea is to define a function that calculates the maximum depth of a subtree rooted at a given node.
"The function works by first checking if the node is null. If it is, that means the subtree is empty, so we return 0 as the depth.
"Otherwise, we recursively call the function on the left and right children of the node, and store the results in variables `l` and `ri`.
"Then, we return 1 plus the maximum of `l` and `ri`. The `+ 1` accounts for the current node, and the `max` ensures we're taking the longer path.
"I wrapped this recursive logic in a `maxDepth` function that simply calls the recursive function on the root node and returns the result.
"In terms of time and space complexity, this solution has a time complexity of O(N) because we're visiting each node once, and a space complexity of O(H) because of the recursive call stack, where H is the height of the tree.
"One potential optimization could be to embed the recursive logic directly into the `maxDepth` function, but overall I think this solution is quite clean and effective.
"I also considered using an iterative solution with a queue or stack, but for this problem, the recursive approach seems like the most natural fit."