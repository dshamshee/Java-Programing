-- Create 
create table student (
    Roll_Number char(10) constraint STU_RL_PK primary key,
    Name varchar(30),
    Course varchar(20),
    Phone char(10),
    Aadhar char(12),
    Email varchar(30),
    Address varchar(50)
);
insert into student values ('24PG11000', 'Guddu Pandit', 'MCA', '1234567890', '312547856325', 'student@gmail.com', 'Vadodara');


-- Read 
select *from student;

-- Update
update student set address = 'Uttar Pradesh' where Roll_Number = '24PG11000';

-- Delete
delete from student where Roll_Number = '24PG11000';