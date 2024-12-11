<?php
$conn = new mysqli('localhost', 'root', '', 'student_result_system');

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $exam_date = $_POST['exam_date'];
    $subject = $_POST['subject'];
    $max_marks = $_POST['max_marks'];

    $stmt = $conn->prepare("INSERT INTO exams (exam_date, subject, max_marks) VALUES (?, ?, ?)");
    $stmt->bind_param('ssi', $exam_date, $subject, $max_marks);
    $stmt->execute();

    echo "Exam details saved successfully! <a href='index.php'>Go Back</a>";
}
?>

<form method="POST">
    <h2>Exam Details Entry</h2>
    <label>Exam Date: </label><input type="date" name="exam_date" required><br>
    <label>Subject: </label><input type="text" name="subject" required><br>
    <label>Max Marks: </label><input type="number" name="max_marks" required><br>
    <button type="submit">Save</button>
</form>
