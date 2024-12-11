<?php
// Database connection
$conn = new mysqli('localhost', 'root', '', 'mca_demo'); // Adjust credentials
if ($conn->connect_error) die("Connection failed: " . $conn->connect_error);

// Fetch query parameter
$query = $_GET['q'] ?? '';
$query = $conn->real_escape_string($query);

// Search in the database
$sql = "SELECT name FROM users WHERE name LIKE '%$query%'";
$result = $conn->query($sql);

// Return results
if ($result->num_rows > 0) {
    while ($row = $result->fetch_assoc()) {
        echo "<p>" . htmlspecialchars($row['name']) . "</p>";
    }
} else {
    echo "<p>No results found</p>";
}
$conn->close();
?>
