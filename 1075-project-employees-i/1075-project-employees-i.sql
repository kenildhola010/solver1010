# Write your MySQL query statement below

select a.project_id,
ROUND(SUM(b.experience_years) / count(b.employee_id),2) as average_years 
from Project a left join Employee b
on a.employee_id = b.employee_id
group by project_id;