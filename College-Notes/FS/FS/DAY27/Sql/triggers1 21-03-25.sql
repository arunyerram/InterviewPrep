

DROP TABLE IF EXISTS emp_audit;

CREATE TABLE emp_audit (
    id INT AUTO_INCREMENT PRIMARY KEY,
    empno INT NOT NULL,
    ename VARCHAR(50) NOT NULL,
	deptno int NOT NULL,
    changedat DATETIME DEFAULT NULL,
    action VARCHAR(50) DEFAULT NULL
);
************************************************************************************
### Setup (Already in your schema)

### 1. BEFORE INSERT Trigger
Write a SQL Trigger to ensure salary is not below the department minimum salary before inserting a new employee into the emp table.

### ANS.

DELIMITER $$
CREATE TRIGGER beforeEmpInsert
BEFORE INSERT 
ON emp FOR EACH ROW
BEGIN
    IF NEW.sal < (SELECT MIN(sal) FROM emp WHERE NEW.deptno = emp.deptno) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Salary cannot be below department minimum salary';
    END IF;
END $$
DELIMITER ;

Trigger 1
INSERT INTO emp VALUES (9991, 'TEST1', 'CLERK', 7902, '23/1/1', 600, 0, 20);

+-------+--------+-----------+------+------------+---------+---------+--------+
| empno | ename  | job       | mgr  | hiredate   | sal     | comm    | deptno |
+-------+--------+-----------+------+------------+---------+---------+--------+

### 2. AFTER INSERT Trigger
Write a SQL Trigger to log new employee hires with their department details in the emp_audit table after insertion into the emp table.

DELIMITER $$
CREATE TRIGGER afterEmpInster
AFTER INSERT
ON emp FOR EACH ROW
BEGIN
    INSERT INTO emp_audit
    SET action = "NEW HIRE",
    empno = NEW.empno, ename = NEW.ename, deptno = NEW.deptno, changedat = NOW();
END$$

Trigger 2
INSERT INTO emp VALUES (9992, 'TEST2', 'ANALYST', 7566, '23/1/2', 2000, NULL, 20);

SELECT * FROM emp_audit;


+----+-------+-------+--------+---------------------+----------+
| id | empno | ename | deptno | changedat           | action   |
+----+-------+-------+--------+---------------------+----------+
|  1 |  9992 | TEST2 |     20 | 2025-03-20 02:03:11 | New Hire |
+----+-------+-------+--------+---------------------+----------+
---

### 3. BEFORE UPDATE Trigger
Write a SQL Trigger to prevent department changes if the employee is a manager before updating the emp table.

DELIMITER $$
CREATE TRIGGER beforeEmpUpdate
BEFORE UPDATE
ON emp FOR EACH ROW
BEGIN
    IF OLD.empno = (SELECT mgr FROM emp) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Cannot change department of a manager';
    END IF;
END$$

-- Trigger 3 
UPDATE emp SET deptno = 30 WHERE empno = 7782;
(45000): Cannot change department of a manager

UPDATE emp SET sal = 3500 WHERE empno = 7788;

+-------+--------+-----------+------+------------+---------+---------+--------+
| empno | ename  | job       | mgr  | hiredate   | sal     | comm    | deptno |
+-------+--------+-----------+------+------------+---------+---------+--------+
---

### 4. AFTER UPDATE Trigger
Write a SQL Trigger to record salary changes in the emp_audit table after an update to the emp table.


DELIMITER $$
CREATE TRIGGER afterEmpUpdate
AFTER UPDATE
ON emp FOR EACH ROW
BEGIN
    INSERT INTO emp_audit
    SET action = CONCAT('Salary changed from ', OLD.sal, ' to ', NEW.sal),
    empno = NEW.empno, ename = NEW.ename, deptno = NEW.deptno, changedat = NOW();
END$$


-- Trigger 4

UPDATE emp SET sal = 4500 WHERE empno = 7788;

SELECT * FROM emp_audit;
+----+-------+-------+--------+---------------------+----------------------------------------+
| id | empno | ename | deptno | changedat           | action                                 |
+----+-------+-------+--------+---------------------+----------------------------------------+
|  1 |  7788 | SCOTT |     20 | 2025-03-20 02:07:39 | Salary changed from 3500.00 to 4500.00 |
+----+-------+-------+--------+---------------------+----------------------------------------+

---

### 5. BEFORE DELETE Trigger
Write a SQL Trigger to prevent deletion of employees with commission before deleting from the emp table.

DELIMITER $$
CREATE TRIGGER beforeEmpDelete
BEFORE DELETE
ON emp FOR EACH ROW
BEGIN
    IF (OLD.comm IS NOT NULL) or (OLD.comm != 0) THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'Cannot delete employee with commission';
    END IF;
END$$
DELIMITER ;
-- Trigger 5 
DELETE FROM emp WHERE empno = 7499; 
(45000): Cannot delete employee with commission

DELETE FROM emp WHERE empno = 7900;

SELECT * FROM emp;

+-------+--------+-----------+------+------------+---------+---------+--------+
| empno | ename  | job       | mgr  | hiredate   | sal     | comm    | deptno |
+-------+--------+-----------+------+------------+---------+---------+--------+
---

### 6. AFTER DELETE Trigger
Write a SQL Trigger to log deleted employees with their job title in the emp_audit table after deletion from the emp table.

DELIMITER $$
CREATE TRIGGER afterEmpDelete
AFTER DELETE
ON emp FOR EACH ROW
BEGIN
    INSERT INTO emp_audit
    SET action = CONCAT('Deleted - Job: ', OLD.job),
    empno = OLD.empno, ename = OLD.ename, deptno = OLD.deptno, changedat = NOW();
END$$
DELIMITER ;

-- Trigger 6
DELETE FROM emp WHERE empno = 7839; 
+----+-------+-------+--------+---------------------+----------------------------------------+
| id | empno | ename | deptno | changedat           | action                                 |
+----+-------+-------+--------+---------------------+----------------------------------------+
|  1 |  7839 | KEVIN |     40 | 2025-03-20 02:14:22 | Deleted - Job: PRESIDENT               |
+----+-------+-------+--------+---------------------+----------------------------------------+
DELETE FROM emp WHERE empno = 7876;
+----+-------+-------+--------+---------------------+----------------------------------------+
| id | empno | ename | deptno | changedat           | action                                 |
+----+-------+-------+--------+---------------------+----------------------------------------+
|  1 |  7839 | KEVIN |     40 | 2025-03-20 02:14:22 | Deleted - Job: PRESIDENT               |
|  2 |  7876 | KEVIN |     20 | 2025-03-20 02:15:41 | Deleted - Job: CLERK                   |
+----+-------+-------+--------+---------------------+----------------------------------------+
SELECT * FROM emp_audit;





