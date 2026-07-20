# Linked List Cycle

## Problem Description
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 
Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


 
Constraints:


	The number of the nodes in the list is in the range [0, 104].
	-105 <= Node.val <= 105
	pos is -1 or a valid index in the linked-list.


 
Follow up: Can you solve it using O(1) (i.e. constant) memory?


## My Code
```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           
            fast = fast->next->next;    

            if (slow == fast) return true;  
        }

        return false;  
    }
};

```

## Code Explanation
The provided code is a solution to the "Linked List Cycle" problem on LeetCode, which determines if a linked list has a cycle in it. Here's a step-by-step breakdown of how the code works:

1. The function `hasCycle` takes the head of a linked list as input and checks if the list has a cycle.
2. It first checks if the head is `NULL` or if the head's next node is `NULL`. If either of these conditions is true, it means the list is empty or only has one node, so it returns `false` as there can't be a cycle.
3. It then initializes two pointers, `slow` and `fast`, both pointing to the head of the list.
4. The code enters a while loop that continues as long as `fast` and `fast->next` are not `NULL`. This is because `fast` moves two steps at a time, so it needs to check if the next two nodes exist to avoid a null pointer exception.
5. Inside the loop, `slow` moves one step at a time (`slow = slow->next`), and `fast` moves two steps at a time (`fast = fast->next->next`).
6. The code then checks if `slow` and `fast` have met at some point (`if (slow == fast)`). If they have, it means there is a cycle in the list, so it returns `true`.
7. If the loop completes without `slow` and `fast` meeting, it means there is no cycle in the list, so it returns `false`.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the number of nodes in the linked list. This is because in the worst-case scenario, the `fast` pointer will reach the end of the list, and the `slow` pointer will have moved through the entire list.
- **Space Complexity:** The space complexity of this solution is O(1), which means it uses constant space. This is because the solution only uses a fixed amount of space to store the `slow` and `fast` pointers, and it does not use any data structures that scale with the input size.

## Optimizations
The provided code is already optimized for this problem. It uses the Floyd's Tortoise and Hare algorithm, also known as the "slow and fast runners" technique, which is the most efficient way to detect a cycle in a linked list. This algorithm has a time complexity of O(n) and a space complexity of O(1), making it optimal for this problem. However, it's worth noting that the code could be made more robust by adding additional error checking, such as checking if the input is valid.

## Interview Explanation
Here's how a candidate should verbally explain this solution to an interviewer:

"Okay, so the problem is asking us to determine if a linked list has a cycle in it. To approach this, I'm going to use the Floyd's Tortoise and Hare algorithm, which is also known as the 'slow and fast runners' technique.

"The idea behind this algorithm is that we have two pointers, a slow pointer and a fast pointer, both starting at the head of the list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time.

"If there is a cycle in the list, the fast pointer will eventually catch up to the slow pointer. This is because the fast pointer is moving twice as fast as the slow pointer, so it will eventually lap the slow pointer if there is a cycle.

"On the other hand, if there is no cycle in the list, the fast pointer will reach the end of the list. In this case, we know that there is no cycle, and we can return false.

"I'm going to initialize both pointers to the head of the list, and then I'm going to enter a loop that continues as long as the fast pointer and the next node after the fast pointer are not null. This is because the fast pointer moves two steps at a time, so we need to make sure that the next two nodes exist to avoid a null pointer exception.

"Inside the loop, I'll move the slow pointer one step at a time, and the fast pointer two steps at a time. I'll also check if the slow pointer and the fast pointer have met at some point. If they have, it means that there is a cycle in the list, and I'll return true.

"If the loop completes without the slow pointer and the fast pointer meeting, it means that there is no cycle in the list, and I'll return false.

"The time complexity of this solution is O(n), where n is the number of nodes in the linked list, and the space complexity is O(1), which means it uses constant space. This is because we're only using a fixed amount of space to store the slow and fast pointers, and we're not using any data structures that scale with the input size.

"I think this solution is optimal for this problem because it has a linear time complexity and constant space complexity, making it efficient for large inputs."