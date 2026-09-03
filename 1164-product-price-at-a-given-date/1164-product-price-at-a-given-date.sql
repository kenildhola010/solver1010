# Write your MySQL query statement below
SELECT distinct product_id,
COALESCE(
    (
        SELECT b.new_price 
        FROM Products b
        WHERE a.product_id = b.product_id
        AND b.change_date <= "2019-08-16"
        Order BY b.change_date DESC LIMIT 1
    ),10) as price
FROM (SELECT  product_id from Products) AS a;