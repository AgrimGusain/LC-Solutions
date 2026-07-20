# Reverse Linked List

## Problem Description
Given the head of a singly linked list, reverse the list, and return the reversed list.

 
Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


Example 2:

Input: head = [1,2]
Output: [2,1]


Example 3:

Input: head = []
Output: []


 
Constraints:


	The number of nodes in the list is the range [0, 5000].
	-5000 <= Node.val <= 5000


 
Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?


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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        if(head->next->next == NULL){
            ListNode* temp = head->next;
            head->next->next = head;
            head->next = NULL;
            return temp;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = second->next;

        while(third != NULL){
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        head->next = NULL;
        return second;

    }
};
```

## Code Explanation
The given code is a solution to the "Reverse Linked List" problem on LeetCode. Here's a step-by-step breakdown of how it works:
- The function `reverseList` takes the head of a singly linked list as input and returns the head of the reversed list.
- It first checks if the input list is empty or contains only one node. If so, it returns the head as it is, since there's nothing to reverse.
- If the list contains exactly two nodes, it manually reverses the list by updating the `next` pointers of the nodes.
- For lists with more than two nodes, it initializes three pointers: `first`, `second`, and `third`, pointing to the first, second, and third nodes of the list, respectively.
- It then enters a while loop that continues until it has traversed the entire list (i.e., until `third` becomes `NULL`).
- Inside the loop, it updates the `next` pointer of the `second` node to point to the `first` node, effectively reversing the link between the `first` and `second` nodes.
- It then moves the `first`, `second`, and `third` pointers one step forward in the list.
- After the loop finishes, it updates the `next` pointer of the last node (which is now the new head of the reversed list) to point to the second-to-last node, and sets the `next` pointer of the original head to `NULL`.
- Finally, it returns the new head of the reversed list, which is the `second` node.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the number of nodes in the list. This is because it only traverses the list once, and each node is visited exactly once.
- **Space Complexity:** The space complexity of this solution is O(1), meaning it uses constant space. This is because it only uses a fixed amount of space to store the `first`, `second`, and `third` pointers, regardless of the size of the input list.

## Optimizations
The given code is already quite efficient and has a time complexity of O(n) and a space complexity of O(1). However, it can be slightly optimized to reduce the number of special cases it handles. For example, instead of handling the cases where the list has zero, one, or two nodes separately, it can be simplified to handle all these cases in the main while loop. Additionally, the variable names can be made more descriptive to improve code readability.

## Interview Explanation
Here's a conversational script on how a candidate should verbally explain this solution to an interviewer:
"So, the problem asks us to reverse a singly linked list. To start, we need to consider the edge cases. If the list is empty or contains only one node, we can simply return the head as it is, because there's nothing to reverse.
For lists with more than one node, we can use a simple iterative approach. We initialize three pointers, which we'll use to keep track of the current node and the next two nodes in the list.
We then enter a while loop that continues until we've traversed the entire list. Inside the loop, we update the `next` pointer of the current node to point to the previous node, effectively reversing the link between the current node and the previous node.
We keep moving the pointers forward until we've traversed the entire list. At the end of the loop, we update the `next` pointer of the new head node to point to the second-to-last node, and set the `next` pointer of the original head to `NULL`.
The time complexity of this solution is O(n), where n is the number of nodes in the list, because we only traverse the list once. The space complexity is O(1), because we only use a fixed amount of space to store the pointers.
One thing to note is that we could also solve this problem recursively, but the iterative approach is generally more efficient because it avoids the overhead of recursive function calls.
I'd be happy to walk through an example to illustrate how this solution works. For instance, if we have a list with nodes 1, 2, 3, 4, 5, we can see how the pointers are updated at each step of the while loop, and how the list is eventually reversed."