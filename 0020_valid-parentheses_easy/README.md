# Valid Parentheses

## Problem Description
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:


	Open brackets must be closed by the same type of brackets.
	Open brackets must be closed in the correct order.
	Every close bracket has a corresponding open bracket of the same type.


 
Example 1:


Input: s = "()"

Output: true


Example 2:


Input: s = "()[]{}"

Output: true


Example 3:


Input: s = "(]"

Output: false


Example 4:


Input: s = "([])"

Output: true


Example 5:


Input: s = "([)]"

Output: false


 
Constraints:


	1 <= s.length <= 104
	s consists of parentheses only '()[]{}'.



## My Code
```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                st.push(i);
            } else {
                if (st.empty()) return false; 
                if ((i == ')' && st.top() == '(') ||
                    (i == '}' && st.top() == '{') ||
                    (i == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false;  
                }
            }
        }
        return st.empty();  
    }
};

```

## Code Explanation
The provided code is a solution to the "Valid Parentheses" problem on LeetCode. It uses a stack data structure to keep track of the opening brackets encountered in the string. Here's a step-by-step breakdown of how it works:

1. **Initialization**: A stack `st` of characters is initialized to store the opening brackets.
2. **Iteration**: The code iterates over each character `i` in the input string `s`.
3. **Opening Bracket**: If the character is an opening bracket (`'('`, `'{'`, or `'['`), it is pushed onto the stack.
4. **Closing Bracket**: If the character is a closing bracket (`')'`, `'}'`, or `']'`), the code checks if the stack is empty. If it is, the function immediately returns `false`, as there is no corresponding opening bracket.
5. **Matching Brackets**: If the stack is not empty, the code checks if the top of the stack contains the corresponding opening bracket for the current closing bracket. If it does, the opening bracket is popped from the stack. If it doesn't, the function immediately returns `false`.
6. **Final Check**: After iterating over the entire string, the function checks if the stack is empty. If it is, the string is valid, and the function returns `true`. If the stack is not empty, it means there are unmatched opening brackets, and the function returns `false`.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the length of the input string. This is because the code iterates over the string once, performing a constant amount of work for each character.
- **Space Complexity:** The space complexity of this solution is O(n), where n is the length of the input string. This is because in the worst-case scenario (e.g., a string consisting only of opening brackets), the stack will store up to n characters.

## Optimizations
The provided code is already quite efficient and optimal for solving the "Valid Parentheses" problem. However, there are a few minor suggestions for improvement:
- Instead of using multiple conditional statements to check for matching brackets, a `std::unordered_map` could be used to map closing brackets to their corresponding opening brackets. This would simplify the code and make it easier to add support for additional bracket types.
- To handle extremely large input strings, a more efficient data structure than a stack (e.g., a custom implementation using a dynamically allocated array) could be used. However, this is unlikely to be necessary in practice, as the input string length is limited to 10^4 characters.

## Interview Explanation
Here's an example of how a candidate might verbally explain this solution to an interviewer:

"Okay, so the problem is to determine whether a given string of parentheses is valid. To solve this, I used a stack data structure. The idea is to iterate over the string and whenever we encounter an opening bracket, we push it onto the stack.

"Then, when we encounter a closing bracket, we check if the stack is empty. If it is, we immediately return false, because there's no corresponding opening bracket. If the stack is not empty, we check if the top of the stack contains the corresponding opening bracket for the current closing bracket. If it does, we pop the opening bracket from the stack. If it doesn't, we return false, because the brackets don't match.

"Finally, after iterating over the entire string, we check if the stack is empty. If it is, we return true, because all the brackets were matched correctly. If the stack is not empty, we return false, because there are unmatched opening brackets.

"In terms of complexity, the time complexity is O(n), where n is the length of the input string, because we're doing a constant amount of work for each character. The space complexity is also O(n), because in the worst-case scenario, we might need to store up to n characters in the stack.

"One potential optimization could be to use a hash map to map closing brackets to their corresponding opening brackets, which would simplify the code and make it easier to add support for additional bracket types. However, the current implementation is already quite efficient and should be sufficient for most use cases."