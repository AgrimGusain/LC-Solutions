# Search In A Binary Search Tree

## Problem Description
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 
Example 1:

Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]


Example 2:

Input: root = [4,2,7,1,3], val = 5
Output: []


 
Constraints:


	The number of nodes in the tree is in the range [1, 5000].
	1 <= Node.val <= 107
	root is a binary search tree.
	1 <= val <= 107



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
    TreeNode* func(TreeNode* r, int v){
        if(r->val == v) return r;
        else if(r->val < v) return func(r->left, v);
        return func(r->right, v);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return root;
        TreeNode* ans = func(root, val);
        return ans;
    }
};
```

## Code Explanation
The provided code is a solution to the "Search In A Binary Search Tree" problem on LeetCode. Here's a step-by-step breakdown of how it works:
- The code starts by defining a binary tree node structure `TreeNode` with an integer value `val`, and pointers to the left and right child nodes.
- The `Solution` class has a member function `func` that takes a `TreeNode` pointer `r` and an integer `v` as parameters. This function recursively searches for a node with a value equal to `v` in the binary search tree.
- The `func` function first checks if the current node's value `r->val` is equal to the target value `v`. If it is, the function returns a pointer to the current node.
- If the current node's value is less than the target value, the function recursively calls itself on the right child node `r->right`. This is because in a binary search tree, all nodes to the right of a given node have values greater than the given node's value.
- If the current node's value is greater than the target value, the function recursively calls itself on the left child node `r->left`. This is because in a binary search tree, all nodes to the left of a given node have values less than the given node's value.
- The `searchBST` function is the main entry point for the solution. It first checks if the input `root` node is `NULL`. If it is, the function returns `NULL` immediately.
- If the `root` node is not `NULL`, the `searchBST` function calls the `func` function to search for the target value in the binary search tree. The result of the `func` function is then returned by the `searchBST` function.

## Complexity Analysis
- **Time Complexity:** The time complexity of the solution is **O(h)**, where **h** is the height of the binary search tree. In the worst-case scenario, the tree is skewed to one side (essentially becoming a linked list), and the time complexity becomes **O(n)**, where **n** is the number of nodes in the tree. However, for a balanced binary search tree, the height **h** is approximately **log(n)**, resulting in a time complexity of **O(log n)**.
- **Space Complexity:** The space complexity of the solution is **O(h)**, which is the maximum depth of the recursive call stack. Like the time complexity, in the worst-case scenario, the space complexity becomes **O(n)**, while for a balanced binary search tree, it is **O(log n)**.

## Optimizations
The provided code is already optimal for searching in a binary search tree, with a time complexity of **O(log n)** for a balanced tree. However, there are a few potential optimizations to consider:
- **Iterative Solution:** The recursive solution can be converted to an iterative solution using a stack or queue data structure. This can help reduce the space complexity and avoid potential stack overflows for very large trees.
- **Early Exit:** The code can be optimized to return early when the target value is found, rather than continuing to traverse the tree. This is already implemented in the provided code.
- **Balanced Tree:** If the binary search tree is guaranteed to be balanced, the code can be optimized to take advantage of this property. For example, the tree can be traversed using an inorder traversal, which visits nodes in ascending order.

## Interview Explanation
Here's a sample script for explaining the solution to an interviewer:
"Okay, so the problem is asking us to find a node in a binary search tree with a given value and return the subtree rooted at that node. To solve this, I'm going to use a recursive approach.
"First, I define a helper function `func` that takes a `TreeNode` pointer and an integer value as parameters. This function will recursively search for the target value in the binary search tree.
"If the current node's value is equal to the target value, I return the current node. If the current node's value is less than the target value, I recursively call the `func` function on the right child node. And if the current node's value is greater than the target value, I recursively call the `func` function on the left child node.
"The main `searchBST` function simply calls the `func` function and returns the result. If the input `root` node is `NULL`, I return `NULL` immediately.
"In terms of time complexity, this solution has a time complexity of **O(h)**, where **h** is the height of the binary search tree. For a balanced binary search tree, this is approximately **O(log n)**. The space complexity is also **O(h)**, which is the maximum depth of the recursive call stack.
"I chose this approach because it's simple and efficient, and it takes advantage of the properties of a binary search tree. The recursive approach makes it easy to implement and understand, and it's easy to see how the solution works.
"I also considered an iterative solution using a stack or queue, but the recursive approach is more intuitive and easier to implement. Additionally, the binary search tree property makes it easy to prune the search space and avoid unnecessary traversals.
"Overall, this solution is efficient and easy to understand, and it takes advantage of the properties of a binary search tree to find the target node in **O(log n)** time."