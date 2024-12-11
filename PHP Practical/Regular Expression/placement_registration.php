<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Online Placement Registration</title>
    <style>
        .error {
            color: red;
        }
    </style>
</head>
<body>
    <h1>Online Placement Registration</h1>

    <?php
    // Define variables for error messages and field values
    $nameErr = $emailErr = $phoneErr = $dobErr = $cgpaErr = "";
    $name = $email = $phone = $dob = $cgpa = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        // Name validation
        if (empty($_POST["name"])) {
            $nameErr = "Name is required";
        } elseif (!preg_match("/^[a-zA-Z\s]+$/", $_POST["name"])) {
            $nameErr = "Name can only contain letters and spaces";
        } else {
            $name = htmlspecialchars($_POST["name"]);
        }

        // Email validation
        if (empty($_POST["email"])) {
            $emailErr = "Email is required";
        } elseif (!filter_var($_POST["email"], FILTER_VALIDATE_EMAIL)) {
            $emailErr = "Invalid email format";
        } else {
            $email = htmlspecialchars($_POST["email"]);
        }

        // Phone validation
        if (empty($_POST["phone"])) {
            $phoneErr = "Phone number is required";
        } elseif (!preg_match("/^\d{10}$/", $_POST["phone"])) {
            $phoneErr = "Phone number must be 10 digits";
        } else {
            $phone = htmlspecialchars($_POST["phone"]);
        }

        // Date of birth validation
        if (empty($_POST["dob"])) {
            $dobErr = "Date of birth is required";
        } elseif (!preg_match("/^\d{4}-\d{2}-\d{2}$/", $_POST["dob"])) {
            $dobErr = "Invalid date format (YYYY-MM-DD)";
        } else {
            $dob = htmlspecialchars($_POST["dob"]);
        }

        // CGPA validation
        if (empty($_POST["cgpa"])) {
            $cgpaErr = "CGPA is required";
        } elseif (!preg_match("/^(10|[0-9](\.\d{1,2})?)$/", $_POST["cgpa"])) {
            $cgpaErr = "CGPA must be a number between 0 and 10 (e.g., 7.5)";
        } else {
            $cgpa = htmlspecialchars($_POST["cgpa"]);
        }
    }
    ?>

    <form method="POST" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" value="<?php echo $name; ?>">
        <span class="error">* <?php echo $nameErr; ?></span>
        <br><br>

        <label for="email">Email:</label>
        <input type="text" id="email" name="email" value="<?php echo $email; ?>">
        <span class="error">* <?php echo $emailErr; ?></span>
        <br><br>

        <label for="phone">Phone Number:</label>
        <input type="text" id="phone" name="phone" value="<?php echo $phone; ?>">
        <span class="error">* <?php echo $phoneErr; ?></span>
        <br><br>

        <label for="dob">Date of Birth:</label>
        <input type="date" id="dob" name="dob" value="<?php echo $dob; ?>">
        <span class="error">* <?php echo $dobErr; ?></span>
        <br><br>

        <label for="cgpa">CGPA:</label>
        <input type="text" id="cgpa" name="cgpa" value="<?php echo $cgpa; ?>">
        <span class="error">* <?php echo $cgpaErr; ?></span>
        <br><br>

        <button type="submit">Register</button>
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST" && empty($nameErr) && empty($emailErr) && empty($phoneErr) && empty($dobErr) && empty($cgpaErr)) {
        echo "<h2>Registration Successful</h2>";
        echo "<p><strong>Name:</strong> $name</p>";
        echo "<p><strong>Email:</strong> $email</p>";
        echo "<p><strong>Phone Number:</strong> $phone</p>";
        echo "<p><strong>Date of Birth:</strong> $dob</p>";
        echo "<p><strong>CGPA:</strong> $cgpa</p>";
    }
    ?>
</body>
</html>
