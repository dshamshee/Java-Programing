CREATE TABLE Departments (
    DeptID char(5) PRIMARY KEY,
    DeptName VARCHAR(50)
);
insert into Departments values ('D001', 'Finance');
insert into Departments values ('D002', 'IT');
insert into Departments values ('D003', 'HR');

CREATE TABLE Employees (
    EmpID char(5) PRIMARY KEY,
    EmpName VARCHAR(50),
    DeptID char(5)
);
insert into Employees values ('Emp01', 'Employee 1', 'D001');
insert into Employees values ('Emp02', 'Employee 2', 'D002');
insert into Employees values ('Emp03', 'Employee 3', NULL);



-- Inner Join 
SELECT Employees.EmpID, Employees.EmpName, Departments.DeptName
FROM Employees
INNER JOIN Departments ON Employees.DeptID = Departments.DeptID;


-- Left Join 
SELECT Employees.EmpID, Employees.EmpName, Departments.DeptName
FROM Employees
LEFT JOIN Departments ON Employees.DeptID = Departments.DeptID;


-- Right Join
SELECT Employees.EmpID, Employees.EmpName, Departments.DeptName
FROM Employees
RIGHT JOIN Departments ON Employees.DeptID = Departments.DeptID;


-- Full OUter Join 
SELECT Employees.EmpID, Employees.EmpName, Departments.DeptName
FROM Employees
FULL OUTER JOIN Departments ON Employees.DeptID = Departments.DeptID;


-- Cross Join 
SELECT Employees.EmpID, Employees.EmpName, Departments.DeptName
FROM Employees
CROSS JOIN Departments;


-- Self Join 
SELECT E1.EmpName AS Employee, E2.EmpName AS Manager
FROM Employees E1
INNER JOIN Employees E2 ON E1.DeptID = E2.DeptID;

