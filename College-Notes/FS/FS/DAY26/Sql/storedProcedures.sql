use test;

# ----------------------------------------
DROP PROCEDURE IF EXISTS empCount;

# Get count of employees
CREATE PROCEDURE empCount (OUT param1 INT)
SELECT COUNT(*) INTO param1 FROM emp;

# calling/invoking the procedure
  CALL empCount(@num);
  select @num;

# ------------------------------------------
DROP PROCEDURE IF EXISTS empAverageSal;

# Get average salary of employees

DELIMITER $$
CREATE PROCEDURE empAverageSal(OUT avgSal decimal(10,2))
 BEGIN
 SELECT AVG(sal) INTO avgSal FROM emp;
 END $$

DELIMITER ;

call empAverageSal(@sal);
select @sal;

# ------------------------------------------
DROP PROCEDURE IF EXISTS getJob;

# Given empno, get the job
CREATE PROCEDURE getJob (IN param1 INT, OUT param2 varchar(50))
SELECT job into param2 from emp where empno = param1; 

CALL getJob(7788, @job);
select @job;

# ------------------------------------------
DROP PROCEDURE IF EXISTS setCounter;

DELIMITER $$
CREATE PROCEDURE setCounter(INOUT count INT(3),IN inc INT(3))
BEGIN
 SET count = count + inc;
END$$
DELIMITER ;

SET @counter = 1;
CALL setCounter(@counter,1); 
CALL setCounter(@counter,2); 
CALL setCounter(@counter,3); 
SELECT @counter; 

# ------------------------------------------
DROP PROCEDURE IF EXISTS getEmpSalGrade;
DELIMITER $$
 
CREATE PROCEDURE getEmpSalGrade(
    in  p_empNo int, 
    out p_empSalGrade  varchar(10))
BEGIN
    DECLARE empSal double;
 
    SELECT sal INTO empSal
    FROM emp
    WHERE empno = p_empNo;
 
    IF empSal > 3000 THEN
      SET p_empSalGrade = 'HIGH';
    ELSEIF (empSal > 1000 && empSal <= 3000 ) THEN
      SET p_empSalGrade = 'MEDIUM';
    ELSEIF (empSal <= 1000) THEN
      SET p_empSalGrade = 'LOW';
    END IF;
 
END$$

DELIMITER ;

call getEmpSalGrade(7839, @empSalGrade);
select @empSalGrade;

call getEmpSalGrade(7369, @empSalGrade);
select @empSalGrade;

call getEmpSalGrade(7698, @empSalGrade);
select @empSalGrade;

# ------------------------------------------
DROP PROCEDURE IF EXISTS getEmpSalGrade2;
DELIMITER $$
 
CREATE PROCEDURE getEmpSalGrade2(
    in  p_empNo int, 
    out p_empSalGrade  varchar(10))
BEGIN
    DECLARE empSal double;
 
    SELECT sal INTO empSal
    FROM emp
    WHERE empno = p_empNo;
 
    CASE
    WHEN empSal > 3000 THEN
      SET p_empSalGrade = 'HIGH';
    WHEN (empSal > 1000 && empSal <= 3000 ) THEN
      SET p_empSalGrade = 'MEDIUM';
    WHEN (empSal <= 1000) THEN
      SET p_empSalGrade = 'LOW';
    END CASE;
 
END$$

DELIMITER ;

call getEmpSalGrade2(7839, @empSalGrade);
select @empSalGrade;

call getEmpSalGrade2(7369, @empSalGrade);
select @empSalGrade;

call getEmpSalGrade2(7698, @empSalGrade);
select @empSalGrade;

# ------------------------------------------
DROP PROCEDURE IF EXISTS setShippingDays;
DELIMITER $$
 
CREATE PROCEDURE setShippingDays(
    in  p_deptNo int, 
    out p_shippingDays  varchar(50))
BEGIN
    DECLARE cLocation varchar(50);
 
    SELECT location INTO cLocation
    FROM dept
    WHERE deptno = p_deptNo;
    
    CASE cLocation
    when  'Dallas' THEN
      SET p_shippingDays = '1 day shipping';
    when  'Tempe' THEN
      SET p_shippingDays = '2 days shipping';
    when  'Chicago' THEN
      SET p_shippingDays = '3 days shipping';
    ELSE 
      SET p_shippingDays = '7 days shipping';
    END CASE;
 
END$$

DELIMITER ;

call setShippingDays(20, @custShippingDays);
select @custShippingDays;

call setShippingDays(50, @custShippingDays);
select @custShippingDays;

call setShippingDays(30, @custShippingDays);
select @custShippingDays;

# ------------------------------------------

DROP PROCEDURE IF EXISTS initDB;
DELIMITER $$
 
CREATE PROCEDURE initDB()
BEGIN
  delete from emp;
	delete from dept;
	delete from salgrade;
 
END$$

DELIMITER ;

call initDB();

SHOW PROCEDURE STATUS WHERE Db = 'test';

# ------------------------------------------

-- 15 SQL QUERIES --

--Write a sql procedure to retrieve all employees with their deptartment names.

DELIMITER $$
CREATE PROCEDURE getEmpDept()
BEGIN
  SELECT e.empno, e.ename, e.job, d.dname
  FROM emp e, dept d
  WHERE e.deptno = d.deptno;
END$$
DELIMITER ;

CALL getEmpDept();

--Write a sql procedure to count employees in each department.

DELIMITER $$
CREATE PROCEDURE getEmpCount()
BEGIN
  SELECT d.dname as DeptName, count(e.empno) as emp_count
  FROM emp e right join dept d
  on e.deptno = d.deptno
  GROUP BY d.deptno;
END$$
DELIMITER ;

CALL getEmpCount();

--Write a SQL procedure to lost departments with no employees assigned to it.
DELIMITER $$
CREATE PROCEDURE getDeptWithNoEmp()
BEGIN
  SELECT d.dname, d.location AS DeptName FROM dept d WHERE deptno NOT IN(select deptno from emp);
END$$
DELIMITER ;

CALL getDeptWithNoEmp();

-- Write SQL procedure to find employess with duplicate names.
DELIMITER $$
CREATE PROCEDURE getDupNameEmp()
BEGIN
  SELECT ename, count(ename) as emp_count FROM emp GROUP BY ename HAVING count(ename) > 1;
END$$
DELIMITER ;

CALL getDeptWithNoEmp();

--  5. Write a SQL procedure to find employees earning above 2500 and return their count.
-- **Procedure:** (IN parameter: min_salary = 2500)
-- CALL GetHighEarners(@count); SELECT @count;
-- +-------+---------+--------+
-- | ename | sal     | deptno |
-- +-------+---------+--------+

-- +--------+
-- | @count |
-- +--------+
DELIMITER $$
CREATE PROCEDURE getHighEarners( OUT count int)
BEGIN
  SELECT ename, sal, deptno FROM emp WHERE sal > 2500;
  SELECT count(*) INTO count FROM emp WHERE sal > 2500;
END$$
DELIMITER ;

CALL getHighEarners(@count);
SELECT @count;


--  6. Write a SQL procedure to list employees and their managers' names and count employees with no manager.
-- **Procedure:** (No IN parameters, only OUT)
-- +----------+-----------+---------+
-- | employee | job       | manager |
-- +----------+-----------+---------+

-- +---------+
-- | @no_mgr |
-- +---------+

DELIMITER $$
CREATE PROCEDURE getNoMgr( OUT res VARCHAR(100))
BEGIN
  SELECT e.ename as employee, e.job, e.mgr as manager FROM emp e join emp m on e.mgr = m.empno;
  SELECT ename into res FROM emp WHERE mgr IS NULL;
END$$
DELIMITER ;

CALL getNoMgr(@res);
SELECT @res;

--  7. Write a SQL procedure to calculate the total salary expenditure by department and return the highest total.
-- **Procedure:** (No IN parameters, only OUT)
-- CALL TotalSalaryByDept(@max); SELECT @max;
-- +------------+--------------+
-- | dname      | total_salary |
-- +------------+--------------+

-- +----------+
-- | @max     |
-- +----------+