<?php
// Include forum class
include('forum_class.php');

// Create administrator object
$admin = new Administrator('admin_user', 'admin@example.com', 'adminpass123');

// Simulate admin activities
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['createForum'])) {
        $admin->createForum($_POST['forumName']);
    } elseif (isset($_POST['deleteForum'])) {
        $admin->deleteForum($_POST['forumName']);
    } elseif (isset($_POST['banMember'])) {
        $admin->banMember($_POST['memberUsername']);
    }
}

// Admin login (optional, based on form input)
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['login'])) {
    $admin->login($_POST['adminUsername'], $_POST['adminPassword']);
}

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Panel - Forum Management</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Administrator Panel</h1>

    <h3>Admin Login:</h3>
    <form action="admin.php" method="POST">
        <input type="text" name="adminUsername" placeholder="Username" required><br><br>
        <input type="password" name="adminPassword" placeholder="Password" required><br><br>
        <input type="submit" name="login" value="Login">
    </form>

    <h3>Create Forum:</h3>
    <form action="admin.php" method="POST">
        <input type="text" name="forumName" placeholder="Forum Name" required><br><br>
        <input type="submit" name="createForum" value="Create Forum">
    </form>

    <h3>Delete Forum:</h3>
    <form action="admin.php" method="POST">
        <input type="text" name="forumName" placeholder="Forum Name to Delete" required><br><br>
        <input type="submit" name="deleteForum" value="Delete Forum">
    </form>

    <h3>Ban Member:</h3>
    <form action="admin.php" method="POST">
        <input type="text" name="memberUsername" placeholder="Member Username" required><br><br>
        <input type="submit" name="banMember" value="Ban Member">
    </form>

</body>
</html>
