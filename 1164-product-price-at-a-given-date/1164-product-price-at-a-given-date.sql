# Write your MySQL query statement below
select DISTINCT product_id,
COALESCE(( 
    select b.new_price 
    from Products b
    where a.product_id = b.product_id
    AND b.change_date <= "2019-08-16"
    ORDER BY b.change_date DESC LIMIT 1
),10) as price
FROM(
    select product_id from Products
) AS a;