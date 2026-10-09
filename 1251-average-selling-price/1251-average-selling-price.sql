# Write your MySQL query statement below
select
p.product_id, 
ifnull(round(sum(price*units)/sum(units), 2), 0)
as average_price
from
Prices p
LEFT JOIN UnitsSold s
ON p.product_id = s.product_id
AND purchase_date BETWEEN start_date AND end_date
GROUP BY p.product_id
;



