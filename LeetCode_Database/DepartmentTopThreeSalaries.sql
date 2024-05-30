Create table If Not Exists Employee (id int, name varchar(255), salary int, departmentId int);
Create table If Not Exists Department (id int, name varchar(255));
Truncate table Employee;
insert into Employee (id, name, salary, departmentId) values ('1', 'Joe', '85000', '1');
insert into Employee (id, name, salary, departmentId) values ('2', 'Henry', '80000', '2');
insert into Employee (id, name, salary, departmentId) values ('3', 'Sam', '60000', '2');
insert into Employee (id, name, salary, departmentId) values ('4', 'Max', '90000', '1');
insert into Employee (id, name, salary, departmentId) values ('5', 'Janet', '69000', '1');
insert into Employee (id, name, salary, departmentId) values ('6', 'Randy', '85000', '1');
insert into Employee (id, name, salary, departmentId) values ('7', 'Will', '70000', '1');
Truncate table Department;
insert into Department (id, name) values ('1', 'IT');
insert into Department (id, name) values ('2', 'Sales');

-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | IT         | Joe      | 85000  |
-- | IT         | Randy    | 85000  |
-- | IT         | Will     | 70000  |
-- | Sales      | Henry    | 80000  |
-- | Sales      | Sam      | 60000  |
-- +------------+----------+--------+
    
Select * From Employee;
Select * From Department;

-- +-------+-------+--------+--------------+
-- | name  | name  | salary | departmentId |
-- |       |       |        |              |
-- | Joe   | IT    | 85000  | 1            |
-- | Henry | Sales | 80000  | 2            |
-- | Sam   | Sales | 60000  | 2            |
-- | Max   | IT    | 90000  | 1            |
-- | Janet | IT    | 69000  | 1            |
-- | Randy | IT    | 85000  | 1            |
-- | Will  | IT    | 70000  | 1            |
-- +-------+-------+--------+--------------+
    
SELECT d.name AS Department, e.name AS Employee, e.salary AS Salary
FROM Employee e
JOIN Department d ON e.departmentId = d.id
where
    (
    select count(distinct salary)
    from Employee
    where departmentId = e.departmentId and salary > e.salary
    ) < 3
    -- or you can use
    -- where departmentId = e.departmentId and salary >= e.salary
    -- ) <= 3
order by 
    d.name, e.salary desc;