# Article Views I

## Problem Description
Table: Views

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
There is no primary key (column with unique values) for this table, the table may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.


 

Write a solution to find all the authors that viewed at least one of their own articles.

Return the result table sorted by id in ascending order.

The result format is in the following example.

 
Example 1:

Input: 
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+
Output: 
+------+
| id   |
+------+
| 4    |
| 7    |
+------+



## My Code
```mysql
# Write your MySQL query statement below
select distinct author_id as id from Views where author_id = viewer_id order by author_id ASC;
```

## Code Explanation
The provided MySQL query statement solves the "Article Views I" problem by selecting distinct `author_id` values from the `Views` table where the `author_id` is equal to the `viewer_id`. This is based on the problem's note that equal `author_id` and `viewer_id` indicate the same person, implying the author viewed their own article. Here's a step-by-step breakdown:

1. **Selecting Data**: The query starts by using the `SELECT` statement to choose data from the `Views` table. Specifically, it selects the `author_id` but alias it as `id` to match the required output format.

2. **Distinct Values**: The `DISTINCT` keyword ensures that each `author_id` (aliased as `id`) is only included once in the output, even if there are multiple instances where an author viewed their own article.

3. **Condition**: The `WHERE` clause applies a condition that `author_id` must be equal to `viewer_id`. This condition filters the data to only include rows where the author of the article also viewed the article, i.e., where the viewer and the author are the same person.

4. **Sorting**: Finally, the `ORDER BY` statement sorts the resulting list of `id`s (which are actually `author_id`s) in ascending order. This ensures the output table is ordered as required.

## Complexity Analysis
- **Time Complexity:** The time complexity of this query can be considered as O(n log n) due to the sorting operation, where n is the number of rows in the table that satisfy the condition. The `DISTINCT` operation may also contribute to the time complexity, depending on the implementation, but in most cases, it does not exceed O(n). The filtering operation (WHERE clause) is typically less expensive than sorting, especially if indexed properly.

- **Space Complexity:** The space complexity is primarily determined by the space required to store the distinct `author_id`s that meet the condition. In the worst case, if all authors viewed their own articles, this could be up to O(n), where n is the number of unique authors. However, since we're only storing the `author_id`s and not the entire rows, the space usage is relatively efficient.

## Optimizations
The query is already quite optimized as it directly selects the required data with the necessary constraints and sorts the output. However, to further improve performance, especially on large datasets:

- **Indexing**: Creating an index on `author_id` and `viewer_id` could significantly speed up the filtering process.
- **Database Tuning**: Depending on the database system being used, tuning the database parameters for better performance with large datasets could be beneficial.
- **Data Partitioning**: If the `Views` table is extremely large, partitioning it based on specific criteria (like date ranges) could make queries more efficient by reducing the amount of data the database needs to scan.

## Interview Explanation
When explaining this solution to an interviewer, you might say something like:

"Well, to start solving the 'Article Views I' problem, the first step is to understand what the question is asking for. We need to find all authors who have viewed at least one of their own articles. The table we're working with, called `Views`, includes columns for `article_id`, `author_id`, `viewer_id`, and `view_date`. 

"The key insight here is recognizing that when `author_id` equals `viewer_id`, it means the author of the article is also the viewer. So, our query should filter the table to only include rows where `author_id` equals `viewer_id`.

"To implement this, we use a `SELECT DISTINCT` statement to ensure we're only getting unique `author_id`s, because even if an author views their article multiple times, we only want to count them once. We alias `author_id` as `id` to match the required output format.

"The `WHERE` clause applies the condition that `author_id` must be equal to `viewer_id`, effectively filtering out any rows where the viewer is not the author.

"Finally, we sort the resulting list of `id`s in ascending order using the `ORDER BY` statement to ensure our output is properly organized.

"In terms of complexity, this query has a time complexity of O(n log n) due to the sorting operation, where n is the number of rows that satisfy the condition. The space complexity is relatively efficient, being up to O(n) for storing the distinct `author_id`s.

"If we were looking to optimize this query further, especially on a very large dataset, we might consider indexing `author_id` and `viewer_id` to speed up the filtering process, or even look into database tuning and data partitioning strategies."