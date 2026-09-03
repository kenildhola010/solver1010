# Write your MySQL query statement below
SELECT product_id, year as first_year, quantity, price
FROM Sales
Where (product_id, year) IN ( 
    SELECT product_id, MIN(year) from Sales
    Group BY product_id
);