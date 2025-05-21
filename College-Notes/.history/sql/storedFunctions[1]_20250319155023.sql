# -----------------------------------------

use test;

SET GLOBAL log_bin_trust_function_creators = 1;

DROP function IF EXISTS getSalGrade;
DELIMITER $$
 
CREATE function getSalGrade(p_empNo int) returns varchar(10)
	DETERMINISTIC
BEGIN
    DECLARE empSal double;
    DECLARE empSalGrade varchar(10);
 
    SELECT sal INTO empSal
    FROM emp
    WHERE empno = p_empNo;
 
    IF empSal > 3000 THEN
      SET empSalGrade = 'HIGH';
    ELSEIF (empSal > 1000 && empSal <= 3000 ) THEN
      SET empSalGrade = 'MEDIUM';
    ELSEIF (empSal <= 1000) THEN
      SET empSalGrade = 'LOW';
    END IF;

    return empSalGrade; 
END$$

CREATE function getInfo(p_empNo int) returns varchar(50)
    DETERMINISTIC
    BEGIN
    DECLARE empName varchar(20);
    DECLARE empJob  varchar(20);
    DECLARE empSalGrade INT;
    DECLARE empManager varchar(20);

    SELECT ename INTO empName
    FROM emp
    WHERE empno = p_empNo;

    SELECT job INTO empJob  
    FROM emp
    WHERE empno = p_empNo;

    SELECT getSalGrade(p_empNo) INTO empSalGrade;
    SELECT mname INTO empManager
    FROM emp
    WHERE empno = p_empNo;

    return concat(empName, ' ', empJob, ' ', empSalGrade, ' ', empManager);

    END$$
DELIMITER ;

-- DELIMITER ;

select getSalGrade(7839) from emp where empno = 7839;
select sal, getSalGrade(7369) from emp where empno = 7369;
select sal, getSalGrade(7698) from emp where empno = 7698;

SHOW FUNCTION STATUS WHERE Db = 'test';


DROP function IF EXISTS getDeptSal;
DELIMITER $$
 
CREATE function getDeptSal(dno int) returns double
BEGIN
    DECLARE empSal double;
 
	select sum(sal) INTO empSal from emp where deptno = dno;
	return empSal; 
END$$

DELIMITER ;

select getDeptSal(20);