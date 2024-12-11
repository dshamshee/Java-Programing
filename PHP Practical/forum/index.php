<?php
// Include forum class
include('forum_class.php');

// Simulate a member login
$member = new Member('john_doe', 'john@example.com', 'password123');

// Simulate member activities
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    if (isset($_POST['createPost'])) {
        $member->createPost($_POST['postContent']);
    } elseif (isset($_POST['editProfile'])) {
        $member->editProfile($_POST['newEmail'], $_POST['newPassword']);
    }
}

// Show member profile
$member->showProfile();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Forum - Member Area</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Welcome to the Forum, <?php echo $member->username; ?>!</h1>
    <form action="index.php" method="POST">
        <h3>Create a Post:</h3>
        <textarea name="postContent" required></textarea><br><br>
        <input type="submit" name="createPost" value="Create Post">
    </form>

    <h3>Edit Profile:</h3>
    <form action="index.php" method="POST">
        <input type="email" name="newEmail" placeholder="New Email" required><br><br>
        <input type="password" name="newPassword" placeholder="New Password" required><br><br>
        <input type="submit" name="editProfile" value="Update Profile">
    </form>
</body>
</html>
