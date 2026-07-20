# Product Of Array Except Self

## Problem Description
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

 
Constraints:


	2 <= nums.length <= 105
	-30 <= nums[i] <= 30
	The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.


 
Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)


## My Code
```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> ans(n);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (int i = n-2; i >= 0; i--) {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * suffix[i];
        }

        return ans;
    }
};

```

## Code Explanation
The provided code is a solution to the "Product Of Array Except Self" problem, where the goal is to calculate the product of all numbers in the input array except for each individual number. The solution works as follows:
1. It initializes three vectors: `prefix`, `suffix`, and `ans`, each with the same length as the input array `nums`. The `prefix` vector is used to store the product of all numbers to the left of each index, the `suffix` vector is used to store the product of all numbers to the right of each index, and the `ans` vector is used to store the final result.
2. The code then populates the `prefix` vector by iterating over the input array from left to right. For each index `i`, it calculates the product of all numbers to the left of `i` by multiplying the product of the numbers to the left of `i-1` (which is stored in `prefix[i-1]`) with the number at `i-1` (which is `nums[i-1]`).
3. Next, the code populates the `suffix` vector by iterating over the input array from right to left. For each index `i`, it calculates the product of all numbers to the right of `i` by multiplying the product of the numbers to the right of `i+1` (which is stored in `suffix[i+1]`) with the number at `i+1` (which is `nums[i+1]`).
4. Finally, the code populates the `ans` vector by multiplying the corresponding elements of the `prefix` and `suffix` vectors. The product of all numbers except for the number at index `i` is the product of the numbers to the left of `i` (stored in `prefix[i]`) and the numbers to the right of `i` (stored in `suffix[i]`).

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the length of the input array. This is because the solution involves three separate passes over the input array: one to populate the `prefix` vector, one to populate the `suffix` vector, and one to populate the `ans` vector. Each pass takes O(n) time, resulting in an overall time complexity of O(n) + O(n) + O(n) = O(3n), which simplifies to O(n) because constant factors are ignored in big O notation.
- **Space Complexity:** The space complexity of this solution is O(n), where n is the length of the input array. This is because the solution involves creating three additional vectors (`prefix`, `suffix`, and `ans`), each with the same length as the input array. The space required to store these vectors is proportional to the length of the input array, resulting in a space complexity of O(n).

## Optimizations
The code can be optimized further by reducing the space complexity. Instead of using three separate vectors (`prefix`, `suffix`, and `ans`), we can use only two vectors: `prefix` and `ans`. We can calculate the `suffix` product on the fly while populating the `ans` vector. Here's how it can be done:
- First, populate the `prefix` vector as before.
- Then, initialize the `ans` vector with the same length as the input array and the `suffix` product to 1.
- Iterate over the input array from right to left. For each index `i`, calculate the product of all numbers except for the number at `i` by multiplying the product of the numbers to the left of `i` (stored in `prefix[i]`) with the current `suffix` product. Store this product in `ans[i]`.
- Update the `suffix` product by multiplying it with the number at `i`.

By using only two vectors, we can reduce the space complexity from O(n) to O(n), but the code will be slightly more efficient.

## Interview Explanation
When explaining this solution to an interviewer, you could say something like this:
"Okay, so the problem asks us to calculate the product of all numbers in the input array except for each individual number. To solve this, I'm going to use a technique called prefix and suffix products. The idea is to calculate the product of all numbers to the left of each index and the product of all numbers to the right of each index, and then multiply these two products together to get the final result.

"I'll start by initializing three vectors: `prefix`, `suffix`, and `ans`. The `prefix` vector will store the product of all numbers to the left of each index, the `suffix` vector will store the product of all numbers to the right of each index, and the `ans` vector will store the final result.

"Next, I'll populate the `prefix` vector by iterating over the input array from left to right. For each index `i`, I'll calculate the product of all numbers to the left of `i` by multiplying the product of the numbers to the left of `i-1` with the number at `i-1`.

"Then, I'll populate the `suffix` vector by iterating over the input array from right to left. For each index `i`, I'll calculate the product of all numbers to the right of `i` by multiplying the product of the numbers to the right of `i+1` with the number at `i+1`.

"Finally, I'll populate the `ans` vector by multiplying the corresponding elements of the `prefix` and `suffix` vectors. The product of all numbers except for the number at index `i` is the product of the numbers to the left of `i` and the numbers to the right of `i`.

"The time complexity of this solution is O(n), where n is the length of the input array, because we're making three separate passes over the input array. The space complexity is also O(n), because we're using three additional vectors to store the prefix and suffix products.

"One optimization we could make is to reduce the space complexity by using only two vectors: `prefix` and `ans`. We could calculate the `suffix` product on the fly while populating the `ans` vector, which would make the code slightly more efficient.

"I hope that makes sense! Do you have any questions about the solution or would you like me to explain any part of it in more detail?"