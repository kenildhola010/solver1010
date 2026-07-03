# Write your MySQL query statement below
SELECT employee_id
FROM Employees  
Where (manager_id) NOT IN(
    select employee_id
    from Employees
) AND
 manager_id IS  NOT NULL AND salary <30000
 Order by employee_id;