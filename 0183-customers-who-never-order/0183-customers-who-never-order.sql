# Write your MySQL query statement below
SELECT c.name AS Customers from Customers c
left JOIN Orders o ON c.id=o.customerId
WHERE o.customerId IS NULL;
