# Write your MySQL query statement below

SELECT e.name AS Employee  from  Employee  e
WHERE e.salary>(
         SELECT f.salary FROM Employee f
         WHERE e.managerId =f.id
);
