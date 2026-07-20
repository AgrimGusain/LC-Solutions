# Two Sum

## Problem Description
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 
Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]


Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


 
Constraints:


	2 <= nums.length <= 104
	-109 <= nums[i] <= 109
	-109 <= target <= 109
	Only one valid answer exists.


 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

## My Code
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];

            if(mp.find(need) != mp.end())
                return {mp[need], i};

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

## Code Explanation
The submitted code is a solution to the "Two Sum" problem on LeetCode. It uses an unordered_map (a hash table) to store the numbers in the input array as keys and their indices as values. Here's a step-by-step breakdown of how the code works:
1. An unordered_map `mp` is created to store the numbers and their indices.
2. The code then iterates through the input array `nums` using a for loop.
3. For each number `nums[i]`, it calculates the "need" value, which is the difference between the target and the current number (`target - nums[i]`).
4. It then checks if the "need" value is already present in the unordered_map `mp`. If it is, it means that we have found two numbers that add up to the target, and the function returns their indices as a vector.
5. If the "need" value is not present in `mp`, the current number `nums[i]` and its index `i` are added to `mp`.
6. If the loop completes without finding a pair of numbers that add up to the target, the function returns an empty vector.

## Complexity Analysis
- **Time Complexity:** The time complexity of the code is O(n), where n is the number of elements in the input array `nums`. This is because the code iterates through the array once, and the operations inside the loop (hash table lookups and insertions) take constant time on average.
- **Space Complexity:** The space complexity of the code is also O(n), as in the worst case, all numbers from the input array will be stored in the unordered_map `mp`.

## Optimizations
The code is already quite efficient and optimal for this problem. However, here are a few minor suggestions:
- Error handling: The code assumes that a solution will always be found, as stated in the problem description. In a real-world scenario, you might want to add error handling to handle cases where no solution is found.
- Input validation: The code assumes that the input array `nums` will always contain at least two elements, as stated in the problem constraints. You might want to add input validation to handle cases where the input array is too small.

## Interview Explanation
"Okay, so for this problem, we're given an array of integers and a target integer, and we need to find two numbers in the array that add up to the target. The problem statement guarantees that there will be exactly one solution, and we're not allowed to use the same element twice.

"My approach to this problem is to use a hash table, specifically an unordered_map in C++. The idea is to iterate through the array and for each number, calculate the difference between the target and that number. We'll call this difference the 'need' value.

"Then, we'll check if the 'need' value is already present in our hash table. If it is, that means we've found a pair of numbers that add up to the target, and we can return their indices.

"If the 'need' value is not present in the hash table, we'll add the current number and its index to the hash table. This way, we can keep track of all the numbers we've seen so far and their indices.

"The key insight here is that we're using the hash table to store the numbers we've seen so far, and their indices. This allows us to look up the 'need' value in constant time, which gives us an overall time complexity of O(n).

"The space complexity is also O(n), because in the worst case, we might need to store all numbers from the input array in the hash table.

"I'd like to highlight a few edge cases here. For example, if the input array is very large, we might need to consider using a more memory-efficient data structure. However, given the constraints of the problem, an unordered_map should be sufficient.

"Overall, this solution is quite efficient and scalable, and it meets the requirements of the problem. I've also considered error handling and input validation, but given the problem statement, we can assume that a solution will always be found, and the input array will always be valid."