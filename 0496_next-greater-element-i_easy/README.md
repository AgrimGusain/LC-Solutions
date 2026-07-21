# Next Greater Element I

## Problem Description
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 
Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.


 
Constraints:


	1 <= nums1.length <= nums2.length <= 1000
	0 <= nums1[i], nums2[i] <= 104
	All integers in nums1 and nums2 are unique.
	All the integers of nums1 also appear in nums2.


 
Follow up: Could you find an O(nums1.length + nums2.length) solution?

## My Code
```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        vector<int> nxt(n2, -1);
        vector<int> ans(n1, -1);
        st.push(nums2[n2-1]);
        for(int i = n2-2; i>=0; i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
                if(st.empty()) break;
            }
            if(!st.empty() && nums2[i] < st.top()){
                nxt[i] = st.top();
            }
            st.push(nums2[i]);
        }

        for(int i = 0; i<n1; i++){
            int index = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            ans[i] = nxt[index];
        }

        return ans;
        
    }
};
```

## Code Explanation
The given code is a solution to the "Next Greater Element I" problem on LeetCode. It takes two distinct 0-indexed integer arrays `nums1` and `nums2` as input, where `nums1` is a subset of `nums2`. The task is to find the next greater element for each value in `nums1` within `nums2`. 

Here's a step-by-step breakdown of how the code works:

1. It initializes a stack `st` to keep track of the elements in `nums2` and two vectors `nxt` and `ans` of size `n2` and `n1` respectively, both filled with -1. `nxt` is used to store the next greater element for each element in `nums2`, and `ans` is used to store the final result.

2. It pushes the last element of `nums2` into the stack `st`.

3. It then iterates over the elements of `nums2` in reverse order (from the second last element to the first element). For each element `nums2[i]`, it checks if the top element of the stack is less than `nums2[i]`. If it is, it pops the top element from the stack until it finds an element greater than `nums2[i]` or the stack becomes empty.

4. If the stack is not empty after the above steps, it means that the top element of the stack is the next greater element for `nums2[i]`. It then updates the `nxt` vector with the next greater element for the current index `i`.

5. After updating the `nxt` vector, it pushes the current element `nums2[i]` into the stack.

6. Once it has processed all elements of `nums2`, it then iterates over the elements of `nums1`. For each element `nums1[i]`, it finds its index in `nums2` using the `find` function.

7. It then updates the `ans` vector with the next greater element for the current element `nums1[i]` using the `nxt` vector.

8. Finally, it returns the `ans` vector, which contains the next greater elements for each value in `nums1`.

## Complexity Analysis
- **Time Complexity:** The time complexity of the given solution is O(n1 + n2), where n1 and n2 are the sizes of `nums1` and `nums2` respectively. This is because the solution iterates over the elements of `nums1` and `nums2` once. The `find` function used to find the index of an element in `nums2` takes O(n2) time in the worst case, but since it is used within a loop of size n1, the overall time complexity remains O(n1 + n2).
- **Space Complexity:** The space complexity of the given solution is O(n2), where n2 is the size of `nums2`. This is because the solution uses two vectors `nxt` and `ans` of size n2 and n1 respectively, and a stack to keep track of the elements.

## Optimizations
The given solution is already optimal with a time complexity of O(n1 + n2). However, a minor optimization could be to use a `unordered_map` to store the indices of the elements in `nums2` instead of using the `find` function, which would reduce the time complexity of finding an element in `nums2` to O(1). This would be beneficial when n2 is very large.

## Interview Explanation
"Okay, so to explain this solution, let's break it down into steps. We're given two arrays, `nums1` and `nums2`, where `nums1` is a subset of `nums2`. Our task is to find the next greater element for each value in `nums1` within `nums2`.

First, we initialize a stack `st` to keep track of the elements in `nums2`. We also create two vectors `nxt` and `ans` of size `n2` and `n1` respectively, both filled with -1. `nxt` is used to store the next greater element for each element in `nums2`, and `ans` is used to store the final result.

Then, we push the last element of `nums2` into the stack `st`. We iterate over the elements of `nums2` in reverse order, and for each element, we check if the top element of the stack is less than the current element. If it is, we pop the top element from the stack until we find an element greater than the current element or the stack becomes empty.

If the stack is not empty after this, we update the `nxt` vector with the next greater element for the current index. We then push the current element into the stack.

Once we've processed all elements of `nums2`, we iterate over the elements of `nums1`. For each element, we find its index in `nums2` using the `find` function, and then update the `ans` vector with the next greater element for the current element using the `nxt` vector.

Finally, we return the `ans` vector, which contains the next greater elements for each value in `nums1`.

In terms of time complexity, this solution is O(n1 + n2), where n1 and n2 are the sizes of `nums1` and `nums2` respectively. The space complexity is O(n2), where n2 is the size of `nums2`.

One potential optimization could be to use a `unordered_map` to store the indices of the elements in `nums2` instead of using the `find` function, which would reduce the time complexity of finding an element in `nums2` to O(1). However, since the `find` function is only used once for each element in `nums1`, the overall time complexity remains O(n1 + n2)."