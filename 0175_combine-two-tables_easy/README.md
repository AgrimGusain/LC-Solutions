# Combine Two Tables

## Problem Description
Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| personId    | int     |
| lastName    | varchar |
| firstName   | varchar |
+-------------+---------+
personId is the primary key (column with unique values) for this table.
This table contains information about the ID of some persons and their first and last names.


 

Table: Address

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| addressId   | int     |
| personId    | int     |
| city        | varchar |
| state       | varchar |
+-------------+---------+
addressId is the primary key (column with unique values) for this table.
Each row of this table contains information about the city and state of one person with ID = PersonId.


 

Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.

Return the result table in any order.

The result format is in the following example.

 
Example 1:

Input: 
Person table:
+----------+----------+-----------+
| personId | lastName | firstName |
+----------+----------+-----------+
| 1        | Wang     | Allen     |
| 2        | Alice    | Bob       |
+----------+----------+-----------+
Address table:
+-----------+----------+---------------+------------+
| addressId | personId | city          | state      |
+-----------+----------+---------------+------------+
| 1         | 2        | New York City | New York   |
| 2         | 3        | Leetcode      | California |
+-----------+----------+---------------+------------+
Output: 
+-----------+----------+---------------+----------+
| firstName | lastName | city          | state    |
+-----------+----------+---------------+----------+
| Allen     | Wang     | Null          | Null     |
| Bob       | Alice    | New York City | New York |
+-----------+----------+---------------+----------+
Explanation: 
There is no address in the address table for the personId = 1 so we return null in their city and state.
addressId = 1 contains information about the address of personId = 2.



## My Code
```mysql
# Write your MySQL query statement below
select p.firstname, p.lastname, a.city, a.state from person as p left join address a
on p.personid = a.personid;
```

## Code Explanation
The given solution is a SQL query that combines data from the `Person` and `Address` tables based on the `personId` column. Here's a step-by-step breakdown of how it works:

1. `select p.firstname, p.lastname, a.city, a.state`: This line selects the columns that we want to include in our output. We're choosing `firstname` and `lastname` from the `Person` table, and `city` and `state` from the `Address` table.
2. `from person as p`: This line specifies the `Person` table as the source of our data. The `as p` part assigns the alias `p` to the `Person` table, which we can use later in the query to refer to it.
3. `left join address a`: This line combines the `Person` table with the `Address` table using a left join. A left join returns all the rows from the left table (`Person`), and the matching rows from the right table (`Address`). If there's no match, the result is NULL on the right side.
4. `on p.personid = a.personid`: This line specifies the condition for the join. We're joining the `Person` and `Address` tables based on the `personId` column.

By using a left join, we ensure that we include all rows from the `Person` table, even if there's no matching row in the `Address` table. This is necessary because the problem statement requires us to report NULL for the city and state if the address of a person is not present in the `Address` table.

## Complexity Analysis
- **Time Complexity:** The time complexity of this query is O(n + m), where n is the number of rows in the `Person` table and m is the number of rows in the `Address` table. This is because we're performing a left join, which requires us to iterate over all the rows in both tables.
- **Space Complexity:** The space complexity of this query is O(n + m), as we need to store the results of the join in memory. However, the actual space complexity may be lower if the database is able to optimize the query and reduce the amount of memory needed.

## Optimizations
The given query is already quite optimal, as it uses a left join to combine the two tables. However, there are a few potential optimizations to consider:

* If the `personId` column is not indexed in either table, adding an index could improve the performance of the query.
* If the `Address` table is very large, it may be more efficient to use a subquery or a join with a derived table instead of a left join.
* Depending on the database management system being used, there may be other optimizations available, such as using a hash join or a merge join instead of a nested loop join.

## Interview Explanation
Here's a script for how a candidate could explain this solution to an interviewer:

"Okay, so the problem asks us to report the first name, last name, city, and state of each person in the `Person` table. We're also told that if the address of a person is not present in the `Address` table, we should report NULL for the city and state.

"To solve this problem, I used a SQL query that combines the `Person` and `Address` tables using a left join. A left join returns all the rows from the left table, and the matching rows from the right table. If there's no match, the result is NULL on the right side.

"So, in this case, we're joining the `Person` table with the `Address` table on the `personId` column. This ensures that we include all rows from the `Person` table, even if there's no matching row in the `Address` table.

"I chose to use a left join because it allows us to include all the rows from the `Person` table, while still getting the city and state information from the `Address` table. If we had used an inner join instead, we would only get the rows where there's a match between the two tables, which isn't what we want.

"In terms of the query itself, I started by selecting the columns that we want to include in our output. I chose `firstname` and `lastname` from the `Person` table, and `city` and `state` from the `Address` table.

"Then, I specified the `Person` table as the source of our data, and assigned it the alias `p`. I did the same thing for the `Address` table, assigning it the alias `a`.

"Next, I used the `left join` clause to combine the two tables. I specified the `Address` table as the right table, and used the `on` clause to specify the condition for the join. In this case, we're joining on the `personId` column.

"Finally, I executed the query and got the results. As you can see, we get all the rows from the `Person` table, along with the city and state information from the `Address` table. If there's no match, we get NULL for the city and state.

"I think this solution is pretty efficient, as it only requires a single pass over the data. However, if the `Address` table is very large, we might be able to optimize the query further by using a subquery or a join with a derived table. We could also consider adding an index to the `personId` column if it's not already indexed."