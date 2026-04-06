# Write your MySQL query statement below
-- Select the person name who can be the last to get on the bus
SELECT q1.person_name

FROM queue q1

-- Self join:
-- For each person (q1), join with all people (q2)
-- whose turn is less than or equal to q1's turn
-- This helps us calculate cumulative weight up to that person
INNER JOIN queue q2
ON q1.turn >= q2.turn 

-- Group by each person's turn (each position in queue)
GROUP BY q1.turn

-- Calculate total weight up to that turn
-- Keep only those where total weight does not exceed 1000
HAVING SUM(q2.weight) <= 1000

-- Sort in descending order to get the last valid person
ORDER BY q1.turn DESC 

-- Return only one result (the last person who can board)
LIMIT 1;