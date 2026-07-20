# Valid Anagram

## Problem Description
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 
Example 1:


Input: s = "anagram", t = "nagaram"

Output: true


Example 2:


Input: s = "rat", t = "car"

Output: false


 
Constraints:


	1 <= s.length, t.length <= 5 * 104
	s and t consist of lowercase English letters.


 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


## My Code
```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> arr1(256, 0);
        vector<int> arr2(256, 0);
        for(auto i : s) arr1[i]++;
        for(auto i : t) arr2[i]++;
        return arr1 == arr2;
    }
};
```

## Code Explanation
The provided code is a C++ solution to the "Valid Anagram" problem on LeetCode. Here's a step-by-step breakdown of how it works:
1. The function `isAnagram` takes two strings `s` and `t` as input and returns a boolean value indicating whether `t` is an anagram of `s`.
2. The code first checks if the lengths of the two strings are equal. If they are not, it immediately returns `false`, because an anagram must have the same number of characters as the original string.
3. It then initializes two vectors `arr1` and `arr2` of size 256, each representing the frequency of characters in `s` and `t`, respectively. The size 256 is chosen because there are 256 possible ASCII characters (including lowercase English letters, uppercase English letters, digits, and special characters).
4. The code then iterates over each character in `s` and increments the corresponding index in `arr1`. For example, if the character is 'a', it increments `arr1[97]` (because 'a' has an ASCII value of 97).
5. Similarly, it iterates over each character in `t` and increments the corresponding index in `arr2`.
6. Finally, the code checks if `arr1` and `arr2` are equal. If they are, it means that the frequency of each character in `s` is the same as the frequency of that character in `t`, so it returns `true`. Otherwise, it returns `false`.

## Complexity Analysis
- **Time Complexity:** The time complexity of the solution is O(n), where n is the length of the input strings. The reason is that the solution iterates over each character in the input strings once to count their frequencies, resulting in a linear time complexity.
- **Space Complexity:** The space complexity of the solution is O(1), because the space used does not grow with the size of the input. The solution uses two vectors of size 256 to count the frequencies of characters, regardless of the length of the input strings.

## Optimizations
The code is already optimal in terms of time and space complexity. However, there are a few minor optimizations and considerations:
- Instead of using two separate vectors to count the frequencies of characters in `s` and `t`, we could use a single vector and iterate over both strings simultaneously, updating the count for each character in a single pass. This would not change the time complexity but could reduce the constant factor slightly.
- To adapt the solution to handle Unicode characters, we could use a `std::unordered_map` to count the frequencies of characters instead of a fixed-size vector. This would allow us to handle Unicode characters with arbitrary code points.
- We could also use `std::sort` to sort the characters in each string and then compare the sorted strings. However, this would increase the time complexity to O(n log n) due to the sorting step.

## Interview Explanation
Here's a conversational script on how a candidate should verbally explain this solution to an interviewer:
"Okay, so the problem asks us to determine whether two strings are anagrams of each other. An anagram is a word or phrase formed by rearranging the letters of another word or phrase, typically using all the original letters exactly once.
"To solve this problem, I used a simple and efficient approach. First, I checked if the lengths of the two input strings are equal. If they are not, I immediately returned false, because an anagram must have the same number of characters as the original string.
"Next, I used two vectors to count the frequencies of characters in each string. I chose to use vectors of size 256, because there are 256 possible ASCII characters. This allows me to efficiently count the frequencies of characters using their ASCII values as indices.
"I then iterated over each character in the input strings, incrementing the corresponding count in the vectors. Finally, I compared the two vectors to determine if they are equal. If they are, it means that the frequencies of characters in the two strings are the same, so I returned true. Otherwise, I returned false.
"In terms of time complexity, this solution is O(n), where n is the length of the input strings. This is because I only need to iterate over each character in the input strings once to count their frequencies.
"The space complexity is O(1), because the space used does not grow with the size of the input. I used two vectors of fixed size to count the frequencies of characters, regardless of the length of the input strings.
"One potential optimization worth considering is using a single vector to count the frequencies of characters in both strings, and iterating over them simultaneously. However, this would not change the overall time complexity.
"Another consideration is adapting this solution to handle Unicode characters. To do this, we could use a `std::unordered_map` to count the frequencies of characters, instead of a fixed-size vector. This would allow us to handle Unicode characters with arbitrary code points."