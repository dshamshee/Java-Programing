<?php
// Start session
session_start();

// Hardcoded credentials for validation
$hardcoded_username = "danish";
$hardcoded_password = "danish";

// Handle form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $action = $_POST['action'];
    
    if ($action === 'login') {
        // Validate login
        $username = $_POST['username'];
        $password = $_POST['password'];
        
        if ($username === $hardcoded_username && $password === $hardcoded_password) {
            $_SESSION['username'] = $username;
            header('Location: Profile.html'); // Redirect to Profile page
            exit();
        } else {
            echo "Invalid username or password!<br>";
        }
    } elseif ($action === 'signup') {
        // Redirect to Registration page
        header('Location: Registration.html');
        exit();
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login and SignUp</title>
</head>
<body>
    <h1>Login</h1>
    <form method="POST">
        <label>Username:</label>
        <input type="text" name="username" required><br>
        <label>Password:</label>
        <input type="password" name="password" required><br>
        <button type="submit" name="action" value="login">Login</button>
    </form>
    
    <h1>SignUp</h1>
    <form method="POST">
        <button type="submit" name="action" value="signup">SignUp</button>
    </form>
</body>
</html>
