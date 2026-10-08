# Write your MySQL query statement below
-- select
-- * 
-- -- student_id, student_name, subject_name
-- -- ,count(subject_name) as attended_exams
-- from Examinations as e
-- left join
-- Students as s
-- using(student_id)
-- union
-- select *
-- from Examinations as e
-- right join
-- Students as s
-- using(student_id)
-- -- group by student_name, subject_name
-- ;

-- select st.*, su.*
-- , count() as attended_exams
-- from 
-- (Students as st
-- cross join
-- Subjects as su)
-- left join
-- (Examinations as e
-- left join
-- Students as st2
-- using(student_id))
-- using(student_id)
-- order by student_id
-- ;


-- select
-- * 
-- from Examinations as e
-- left join
-- Students as s
-- using(student_id)
-- ;

select 
St.*, Sb.*
, count(Ex.subject_name) as attended_exams
from
(Students as St
cross join
Subjects as Sb)
left join
(Examinations as Ex)
on
(St.student_id =Ex.student_id
and
Sb.subject_name=Ex.subject_name)
group by
Sb.subject_name,
St.student_name,
St.student_id
order by 
St.student_id 
, Sb.subject_name
;
