# Write your MySQL query statement below
select query_name,
ROUND(SUM(rating / position) / count(query_name),2) as quality,
ROUND(SUM(rating < 3) * 100.0 / COUNT(query_name), 2) AS poor_query_percentage
from Queries
group by query_name;