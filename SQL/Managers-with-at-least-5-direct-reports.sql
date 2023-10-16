# Write your MySQL query statement below
# we are bascially selecting the group of managersIds which has a count of more than 5 and then we check if our name is IN that list. 
Select name from employee where ID in (select managerId from employee group by managerId having count(managerId)>=5);
