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
```

## Code Explanation
The given code is a solution to the "Search In A Binary Search Tree" problem. It defines a recursive function `func` to traverse the binary search tree (BST) and find the node with a value equal to the given `val`. Here's a step-by-step breakdown:

1. The `func` function takes two parameters: `r` (the current node) and `v` (the value to search for).
2. If `r` is `NULL`, it returns `r` immediately, as there's no need to search an empty tree.
3. If the value of the current node `r->val` is equal to `v`, it returns the current node `r`. This is the base case for the recursion.
4. If `r->val` is greater than `v`, it recursively calls `func` on the left subtree `r->left`, as the BST property guarantees that all values in the left subtree are less than the current node's value.
5. If `r->val` is less than `v`, it recursively calls `func` on the right subtree `r->right`, as the BST property guarantees that all values in the right subtree are greater than the current node's value.
6. The `searchBST` function is the main entry point, which calls the `func` function with the root node and the given `val` as arguments.
7. The `searchBST` function returns the result of the `func` function, which is either the node with the matching value or `NULL` if no such node exists.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(h), where h is the height of the binary search tree. In the worst-case scenario, the tree is skewed, and the height is equal to the number of nodes (n). However, for a balanced BST, the height is logarithmic in the number of nodes (h = log(n)). Therefore, the time complexity can be O(log n) for a balanced BST.
- **Space Complexity:** The space complexity is O(h) as well, due to the recursive call stack. In the worst-case scenario, the space complexity is O(n), but for a balanced BST, it's O(log n).

## Optimizations
The given code is already optimized for the "Search In A Binary Search Tree" problem, as it takes advantage of the BST property to reduce the search space. However, some minor improvements can be made:

* The `searchBST` function is not necessary and can be removed. The `func` function can be renamed to `searchBST` to make the code more concise.
* The code can be made more robust by adding error handling for invalid inputs, such as a `NULL` root node or an empty tree.

## Interview Explanation
Here's a conversational script on how a candidate should verbally explain this solution to an interviewer:

"Okay, so the problem is to search for a node in a binary search tree with a given value. The first thing I noticed is that the tree is a binary search tree, which means that for any given node, all the values in the left subtree are less than the node's value, and all the values in the right subtree are greater.

"So, my approach is to use a recursive function to traverse the tree. I start at the root node and check if its value is equal to the given value. If it is, I return the root node, as it's the node we're looking for.

"If the root node's value is greater than the given value, I know that the node I'm looking for must be in the left subtree, because all the values in the left subtree are less than the root node's value. So, I recursively call the function on the left subtree.

"Similarly, if the root node's value is less than the given value, I know that the node I'm looking for must be in the right subtree, because all the values in the right subtree are greater than the root node's value. So, I recursively call the function on the right subtree.

"I continue this process until I find the node with the matching value or until I reach an empty subtree, in which case I return `NULL`.

"In terms of time complexity, this solution is O(h), where h is the height of the tree. In the worst-case scenario, the tree is skewed, and the height is equal to the number of nodes. However, for a balanced BST, the height is logarithmic in the number of nodes, so the time complexity is O(log n).

"The space complexity is also O(h), due to the recursive call stack. Again, in the worst-case scenario, the space complexity is O(n), but for a balanced BST, it's O(log n).

"Overall, this solution takes advantage of the BST property to reduce the search space and is efficient for both balanced and unbalanced trees."