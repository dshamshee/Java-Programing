<?php
$conn = new mysqli('localhost', 'root', '', 'student_result_system');

$query = "SELECT students.name, exams.exam_date, exams.subject, exams.max_marks, marks.marks_obtained 
          FROM marks 
          JOIN students ON marks.student_id = students.student_id 
          JOIN exams ON marks.exam_id = exams.exam_id";

$results = $conn->query($query);
?>

<h2>Generated Results</h2>
<table border="1">
    <tr>
        <th>Student Name</th>
        <th>Exam Date</th>
        <th>Subject</th>
        <th>Max Marks</th>
        <th>Marks Obtained</th>
    </tr>
    <?php while ($row = $results->fetch_assoc()) { ?>
        <tr>
            <td><?php echo $row['name']; ?></td>
            <td><?php echo $row['exam_date']; ?></td>
            <td><?php echo $row['subject']; ?></td>
            <td><?php echo $row['max_marks']; ?></td>
            <td><?php echo $row['marks_obtained']; ?></td>
        </tr>
    <?php } ?>
</table>
<a href="index.php">Go Back</a>
