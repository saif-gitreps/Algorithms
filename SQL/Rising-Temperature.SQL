# Write your MySQL query statement below
SELECT A.id from weather AS A, weather AS B 
    Where datediff(a.recordDate , b.recordDate) = 1 AND 
    a.temperature > b.temperature;
