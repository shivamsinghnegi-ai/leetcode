# Write your MySQL query statement below
SELECT email FROM Person
Group by email
having count(email)>1;
