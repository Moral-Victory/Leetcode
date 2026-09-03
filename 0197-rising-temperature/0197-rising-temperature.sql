# Write your MySQL query statement below
-- select id as req
-- from Weather
-- where DAY(recordDate)=(select DAY(recordDate)+1 from Weather)
-- ;

select w1.id
from Weather as w1
inner join
Weather as w2
on DATEDIFF(w1.recordDate, w2.recordDate)=1
where w1.temperature>w2.temperature
;

-- select * from Weather