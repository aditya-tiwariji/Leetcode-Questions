# Write your MySQL query statement below


SELECT l1.name,l2.unique_id 
FROM Employees AS l1 
LEFT JOIN EmployeeUNI AS l2
ON l1.id=l2.id;
