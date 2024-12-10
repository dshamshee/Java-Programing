-- Create student table
CREATE TABLE student (
    Id INT,
    Name VARCHAR2(20),
    Score INT
);

-- Insert into student Table 
INSERT INTO student (Id, Name, Score) VALUES (1, 'Sam', 800);
INSERT INTO student (Id, Name, Score) VALUES (2, 'Ram', 699);
INSERT INTO student (Id, Name, Score) VALUES (3, 'Tom', 250);
INSERT INTO student (Id, Name, Score) VALUES (4, 'Om', 350);
INSERT INTO student (Id, Name, Score) VALUES (5, 'Jay', 750);
-- insert statement should be written for each entry in Oracle Sql Developer

CREATE TABLE Affect (
    Id INT,
    Name VARCHAR2(20),
    Score INT
);
-- BEFORE INSERT trigger
CREATE OR REPLACE TRIGGER BEFORE_INSERT
BEFORE INSERT ON student
FOR EACH ROW
BEGIN
    INSERT INTO Affect (Id, Name, Score)
    VALUES (:NEW.Id, :NEW.Name, :NEW.Score);
END;
/
INSERT INTO student (Id, Name, Score) VALUES (6, 'Arjun', 500);
BEFORE DELETE Trigger
-- BEFORE DELETE trigger
CREATE OR REPLACE TRIGGER BEFORE_DELETE
BEFORE DELETE ON student
FOR EACH ROW
BEGIN
    INSERT INTO Affect (Id, Name, Score)
    VALUES (:OLD.Id, :OLD.Name, :OLD.Score);
END;
/
DELETE FROM student WHERE Id = 3;
-- BEFORE UPDATE trigger
CREATE OR REPLACE TRIGGER BEFORE_UPDATE
BEFORE UPDATE ON student
FOR EACH ROW
BEGIN
    INSERT INTO Affect (Id, Name, Score)
    VALUES (:OLD.Id, :OLD.Name, :OLD.Score);
END;
/
UPDATE student SET Score = 900 WHERE Id = 5;
SELECT * FROM Affect; 
SELECT * FROM student; 