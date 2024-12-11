<?php
$conn = new mysqli('localhost', 'root', '', 'student_result_system');
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $name = $_POST['name'];
    $roll_no = $_POST['roll_no'];
    $class = $_POST['class'];

    $stmt = $conn->prepare("INSERT INTO students (name, roll_no, class) VALUES (?, ?, ?)");
    $stmt->bind_param('sss', $name, $roll_no, $class);
    $stmt->execute();

    echo "Student details saved successfully! <a href='index.php'>Go Back</a>";
}
?>

<form method="POST">
    <h2>Student Details Entry</h2>
    <label>Name: </label><input type="text" name="name" required><br>
    <label>Roll No: </label><input type="text" name="roll_no" required><br>
    <label>Class: </label><input type="text" name="class" required><br>
    <button type="submit">Save</button>
</form>
