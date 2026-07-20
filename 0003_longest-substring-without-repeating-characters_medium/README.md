# Longest Substring Without Repeating Characters

## Problem Description
Given a string s, find the length of the longest substring without duplicate characters.

 
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.


Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


 
Constraints:


	0 <= s.length <= 5 * 104
	s consists of English letters, digits, symbols and spaces.



## My Code
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        vector<int> ch(256, 0);  // frequency array
        int count = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            ch[s[right]]++;

            // If duplicate, shrink window
            while (ch[s[right]] > 1) {
                ch[s[left]]--;
                left++;
            }

            count = max(count, right - left + 1);
        }
        return count;
    }
};

```

## Code Explanation
The provided code solves the "Longest Substring Without Repeating Characters" problem using the sliding window technique. Here's a step-by-step breakdown of how it works:

1. **Initialization**: The code starts by checking if the input string `s` has a length of 1 or less. If it does, the function returns the length of the string, as it's already the longest substring without repeating characters.

2. **Frequency Array**: A vector `ch` of size 256 is created to store the frequency of each character in the string. The size 256 is chosen because it can accommodate all possible ASCII characters.

3. **Variables**: Two variables, `count` and `left`, are initialized. `count` stores the maximum length of the substring without repeating characters found so far, and `left` represents the left boundary of the sliding window.

4. **Right Pointer Movement**: The code then iterates over the string using a `right` pointer. For each character, it increments the corresponding frequency count in the `ch` vector.

5. **Shrinking the Window**: If the frequency of the current character exceeds 1, it means a duplicate character is found. In this case, the code enters a while loop, where it decrements the frequency count of the character at the `left` index and increments the `left` pointer. This process continues until the frequency of the current character is 1, effectively shrinking the window to remove the duplicate character.

6. **Updating Count**: After adjusting the window, the code updates the `count` variable with the maximum length of the substring without repeating characters found so far. The length is calculated as `right - left + 1`, which represents the current window size.

7. **Return**: Finally, the function returns the `count` variable, which holds the length of the longest substring without repeating characters.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the length of the input string. This is because the code makes a single pass through the string, and the while loop inside the for loop doesn't change the overall time complexity, as each character is visited at most twice (once by the `right` pointer and once by the `left` pointer).
- **Space Complexity:** The space complexity is O(1), as the code uses a fixed-size vector `ch` to store the frequency of characters. Although the size of the vector is 256, it's considered a constant and doesn't grow with the input size.

## Optimizations
The provided code is already optimal in terms of time and space complexity. However, there are a few minor improvements that could be made:

- Instead of using a fixed-size vector `ch`, the code could use an unordered map to store the frequency of characters. This would allow it to handle strings with characters outside the ASCII range.
- The code could use more descriptive variable names, such as `windowStart` instead of `left`, to improve readability.

## Interview Explanation
Here's a detailed, conversational script on how a candidate should verbally explain this solution to an interviewer:

"Okay, so the problem asks us to find the length of the longest substring without repeating characters in a given string. To solve this, we can use a technique called the sliding window approach.

"First, we initialize a frequency array to store the count of each character in the string. We also keep track of the maximum length of the substring without repeating characters found so far.

"Then, we start by iterating over the string from left to right. For each character, we increment its count in the frequency array.

"If we encounter a character that's already present in the frequency array, meaning it's a duplicate, we need to shrink the window to remove the previous occurrence of that character. We do this by moving the left pointer of the window to the right until the duplicate character is removed.

"After adjusting the window, we update the maximum length of the substring without repeating characters found so far.

"We repeat this process until we've iterated over the entire string, and finally, we return the maximum length found.

"In terms of time complexity, this solution has a linear time complexity of O(n), where n is the length of the input string. This is because we make a single pass through the string, and the while loop inside the for loop doesn't change the overall time complexity.

"For space complexity, we use a fixed-size frequency array, which gives us a constant space complexity of O(1).

"One potential optimization we could make is using an unordered map instead of a fixed-size array to store the frequency of characters. This would allow us to handle strings with characters outside the ASCII range.

"Overall, this solution uses a simple yet efficient approach to solve the problem, and it's well-suited for large input strings."