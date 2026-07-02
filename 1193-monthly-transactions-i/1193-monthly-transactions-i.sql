# Write your MySQL query statement below
select DATE_FORMAT(trans_date, "%Y-%m") as month, country, 
COUNT(id) as trans_count,
SUM(IF(state = "Approved",1,0)) as approved_count,
SUM(amount) as trans_total_amount,
SUM(IF(state = "Approved",amount,0)) as approved_total_amount
FROM Transactions
GROUP BY DATE_FORMAT(trans_date, "%Y-%m"),country;