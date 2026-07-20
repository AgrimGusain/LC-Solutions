# Middle Of The Linked List

## Problem Description
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 
Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.


Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


 
Constraints:


	The number of nodes in the list is in the range [1, 100].
	1 <= Node.val <= 100



## My Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;

        while( f->next != NULL ){
            f = f->next->next;
            s = s->next;
            if(f == NULL){
                break;
            }
        }
        return s;
    }
};
```

## Code Explanation
The provided code is a solution to the "Middle Of The Linked List" problem. Here's a step-by-step breakdown of how it works:

1. Two pointers, `f` (fast) and `s` (slow), are initialized to the head of the linked list.
2. The code then enters a while loop, which continues as long as `f->next` is not `NULL`.
3. Inside the loop, `f` is moved two steps forward (`f = f->next->next`) and `s` is moved one step forward (`s = s->next`).
4. The loop checks if `f` has reached the end of the list (`if(f == NULL)`). If it has, the loop breaks.
5. Once the loop breaks, the function returns `s`, which is now pointing to the middle node of the linked list.

The reasoning behind this approach is that by moving `f` twice as fast as `s`, when `f` reaches the end of the list, `s` will be at the middle node. If the list has an even number of nodes, `f` will reach `NULL` after passing the second middle node, so `s` will be at the second middle node, which is the desired output.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the number of nodes in the linked list. This is because the while loop traverses the list once, and the operations inside the loop take constant time.
- **Space Complexity:** The space complexity is O(1), as the solution only uses a constant amount of space to store the two pointers, regardless of the size of the input.

## Optimizations
The code is already quite optimal, with a time complexity of O(n) and a space complexity of O(1). However, there are a few minor suggestions for improvement:
- Consider adding a null check for the input `head` to handle the case where the list is empty.
- Instead of checking `if(f == NULL)`, consider checking `f->next->next == NULL` to avoid a potential null pointer exception.
- The variable names `f` and `s` could be more descriptive. Consider using `fast` and `slow` instead.

## Interview Explanation
Here's a script for how a candidate could verbally explain this solution to an interviewer:

"So, to find the middle node of a linked list, we can use a two-pointer approach. We'll initialize two pointers, let's call them `fast` and `slow`, to the head of the list. The `fast` pointer will move twice as fast as the `slow` pointer, so when `fast` reaches the end of the list, `slow` will be at the middle node.

"The key insight here is that by moving `fast` twice as fast as `slow`, we can effectively find the middle node in a single pass through the list. This is because when `fast` reaches the end of the list, `slow` will have moved half the distance, which is exactly what we need to find the middle node.

"In terms of the code, we can implement this using a simple while loop. We'll keep moving `fast` and `slow` forward until `fast` reaches the end of the list, at which point we'll return `slow` as the middle node.

"One thing to note is that if the list has an even number of nodes, we'll return the second middle node, which is the desired behavior. This is because when `fast` reaches the end of the list, `slow` will be at the second middle node.

"Time complexity-wise, this solution is O(n), where n is the number of nodes in the list, because we're only traversing the list once. Space complexity-wise, we're using a constant amount of space to store the two pointers, so it's O(1).

"Overall, this solution is quite efficient and easy to implement. It's a good example of how we can use a two-pointer approach to solve problems involving linked lists."