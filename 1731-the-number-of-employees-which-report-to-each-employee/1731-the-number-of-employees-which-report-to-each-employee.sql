# Write your MySQL query statement below
Select a.employee_id, a.name,
count(b.reports_to) as reports_count , 
Round(avg(b.age)) as average_age 
FROM Employees a JOIN Employees b
on a.employee_id = b.reports_to
group by b.reports_to
order by a.employee_id;