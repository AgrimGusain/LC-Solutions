# Rotting Oranges

## Problem Description
You are given an m x n grid where each cell can have one of three values:


	0 representing an empty cell,
	1 representing a fresh orange, or
	2 representing a rotten orange.


Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 
Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4


Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.


Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.


 
Constraints:


	m == grid.length
	n == grid[i].length
	1 <= m, n <= 10
	grid[i][j] is 0, 1, or 2.



## My Code
```
/* Failed to capture code. */
```

## Code Explanation
Since the provided code was not captured, I will provide a general explanation of how a typical solution to the "Rotting Oranges" problem works. The code usually involves a breadth-first search (BFS) approach to simulate the rotting process.

1. Initialize a queue with the positions of all rotten oranges (cells with value 2) in the grid. Also, initialize a variable to keep track of the number of fresh oranges (cells with value 1) and the minutes elapsed.
2. Perform a BFS traversal starting from each rotten orange in the queue. For each cell visited, check if it is a fresh orange (value 1). If it is, mark it as rotten (value 2) and decrement the count of fresh oranges.
3. After visiting all cells adjacent to the current rotten orange, increment the minutes elapsed and add the newly rotten oranges to the queue.
4. Repeat steps 2-3 until the queue is empty or there are no more fresh oranges in the grid.
5. If there are still fresh oranges left in the grid after the BFS traversal is complete, it means that it's impossible to rot all the fresh oranges, so return -1. Otherwise, return the minutes elapsed.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(m * n), where m and n are the dimensions of the grid. This is because in the worst-case scenario, we might need to visit each cell in the grid once.
- **Space Complexity:** The space complexity is also O(m * n), which is used to store the queue of rotten oranges. In the worst case, the queue can contain all cells in the grid.

## Optimizations
To optimize this solution further, we could consider the following:
- Check for edge cases where the grid is empty or contains no fresh oranges before proceeding with the BFS traversal.
- Use a more efficient data structure than a queue to store the rotten oranges, such as a deque, which allows for O(1) append and pop operations from both ends.
- Avoid visiting the same cell multiple times by keeping track of visited cells using a separate data structure, such as a set or a boolean array.

## Interview Explanation
Here's an example of how a candidate could explain this solution to an interviewer:

"Okay, so to solve this problem, we use a breadth-first search approach. We start by initializing a queue with the positions of all the rotten oranges in the grid. We also keep track of the number of fresh oranges and the minutes elapsed.

"Then, we perform a BFS traversal starting from each rotten orange in the queue. For each cell we visit, we check if it's a fresh orange. If it is, we mark it as rotten and decrement the count of fresh oranges.

"After visiting all cells adjacent to the current rotten orange, we increment the minutes elapsed and add the newly rotten oranges to the queue.

"We repeat this process until the queue is empty or there are no more fresh oranges in the grid. If there are still fresh oranges left after the BFS traversal is complete, it means that it's impossible to rot all the fresh oranges, so we return -1. Otherwise, we return the minutes elapsed.

"In terms of time complexity, this solution is O(m * n), where m and n are the dimensions of the grid. This is because in the worst-case scenario, we might need to visit each cell in the grid once.

"The space complexity is also O(m * n), which is used to store the queue of rotten oranges. In the worst case, the queue can contain all cells in the grid.

"To optimize this solution further, we could consider using a more efficient data structure than a queue to store the rotten oranges, such as a deque. We could also avoid visiting the same cell multiple times by keeping track of visited cells using a separate data structure, such as a set or a boolean array.

"Overall, this solution has a time complexity of O(m * n) and a space complexity of O(m * n), making it efficient for solving this problem."