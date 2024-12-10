CREATE TABLE student_marks (
  student_id number primary key, 
  subject1_marks number,
  subject2_marks number,
  subject3_marks number,
  subject4_marks number
  );
  
  
  insert into student_marks values (1, 85, 90, 78, 92);
  insert into student_marks values (2, 70, 75, 80, 88);
  insert into student_marks values (3, 60, 65, 72, 58); 
  
DECLARE
    -- Declare variables for total, average, and grade
    v_total NUMBER;
    v_avg   NUMBER;
    v_grade CHAR(1);

    -- Cursor to fetch student data
    CURSOR student_cursor IS
        SELECT student_id, subject1_marks, subject2_marks, subject3_marks, subject4_marks
        FROM student_marks;

BEGIN
    -- Loop through each student record
    FOR student IN student_cursor LOOP
        -- Calculate total
        v_total := student.subject1_marks + student.subject2_marks + student.subject3_marks + student.subject4_marks;

        -- Calculate average
        v_avg := v_total / 4;



--Assign grade based on average
IF v_avg >= 90 THEN
 v_grade := 'A'; ELSIF v_avg >= 75 THEN 
v_grade := 'B'; ELSIF v_avg >= 60 THEN 
v_grade := 'C'; ELSE v_grade := 'D'; 
END IF;
 -- Output the results 
DBMS_OUTPUT.PUT_LINE('Student ID: ' || student.student_id); DBMS_OUTPUT.PUT_LINE('Total Marks: ' || v_total); 
DBMS_OUTPUT.PUT_LINE('Average Marks: ' || v_avg); 
DBMS_OUTPUT.PUT_LINE('Grade: ' || v_grade);
 DBMS_OUTPUT.PUT_LINE('----------------------------------'); 
END LOOP; 
END; 
/