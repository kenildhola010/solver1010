# Write your MySQL query statement below

select a.product_id,
ROUND(IFNULL(SUM(a.price * b.units) / SUM(b.units), 0), 2) as average_price 
from Prices a
left join UnitsSold b
on a.product_id = b.product_id
AND b.purchase_date BETWEEN a.start_date AND a.end_date
group by a.product_id;