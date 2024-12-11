<?php
$conn = new mysqli('localhost', 'root', '', 'student_result_system');

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $student_id = $_POST['student_id'];
    $exam_id = $_POST['exam_id'];
    $marks_obtained = $_POST['marks_obtained'];

    $stmt = $conn->prepare("INSERT INTO marks (student_id, exam_id, marks_obtained) VALUES (?, ?, ?)");
    $stmt->bind_param('iii', $student_id, $exam_id, $marks_obtained);
    $stmt->execute();

    echo "Marks saved successfully! <a href='index.php'>Go Back</a>";
}

// Fetch students and exams for dropdown
$students = $conn->query("SELECT * FROM students");
$exams = $conn->query("SELECT * FROM exams");
?>

<form method="POST">
    <h2>Marks Entry</h2>
    <label>Student: </label>
    <select name="student_id" required>
        <?php while ($row = $students->fetch_assoc()) { ?>
            <option value="<?php echo $row['student_id']; ?>"><?php echo $row['name']; ?></option>
        <?php } ?>
    </select><br>
    <label>Exam (Date - Subject): </label>
    <select name="exam_id" required>
        <?php while ($row = $exams->fetch_assoc()) { ?>
            <option value="<?php echo $row['exam_id']; ?>">
                <?php echo $row['exam_date'] . " - " . $row['subject']; ?>
            </option>
        <?php } ?>
    </select><br>
    <label>Marks Obtained: </label><input type="number" name="marks_obtained" required><br>
    <button type="submit">Save</button>
</form>
