/*
# 177. Nth Highest Salary
## SQL Schema
Create table If Not Exists Employee (id int, salary int)
Truncate table Employee
insert into Employee (id, salary) values ('1', '100')
insert into Employee (id, salary) values ('2', '200')
insert into Employee (id, salary) values ('3', '300') 
*/

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE results INT;
  DECLARE offset_val INT;

  -- Calculate the offset value
  SET offset_val = N - 1;

  -- Retrieve the Nth highest salary
  SET results = (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET offset_val
  );

  -- Return the result
  RETURN results;
END