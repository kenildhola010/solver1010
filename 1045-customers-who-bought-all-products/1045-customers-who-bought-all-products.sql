# Write your MySQL query statement below
select customer_id from Customer
group by customer_id
HAVING count(DISTINCT product_key) = (select COUNT(*) from Product);
