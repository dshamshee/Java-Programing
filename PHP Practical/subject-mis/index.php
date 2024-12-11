<?php
// Include the SubjectMIS class
include('SubjectMIS.php');

// Create an instance of the SubjectMIS class
$subjectMIS = new SubjectMIS();

// Connect to the database
$subjectMIS->connect();

// Demonstrate Insert operation
$subjectMIS->insert("Mathematics");

// Demonstrate Select operation (all subjects)
echo "<h3>All Subjects:</h3>";
$subjectMIS->select();

// Demonstrate Select operation (single subject)
echo "<h3>Subject with ID 1:</h3>";
$subjectMIS->select(1);

// Demonstrate Update operation
$subjectMIS->update(1, "Advanced Mathematics");

// Demonstrate Delete operation
$subjectMIS->delete(2);

// Disconnect from the database
$subjectMIS->disconnect();
?>
