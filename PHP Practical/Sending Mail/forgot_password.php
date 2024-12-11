<?php
// Define the email address to send the message to (could be the user's email in a real system)
$userEmail = "user@example.com";

// Define the subject of the email
$subject = "Forgot Password Recovery";

// Define the message content
$message = "
    <html>
    <head>
        <title>Forgot Password Recovery</title>
    </head>
    <body>
        <p>Dear User,</p>
        <p>You requested to recover your password. Please click the link below to reset your password:</p>
        <p><a href='https://github.com/dshamshee'>Reset Password</a></p>
        <p>If you did not request this, please ignore this email.</p>
        <p>Best Regards,<br>Your Website Team</p>
    </body>
    </html>
";

// Set content-type header for HTML email
$headers = "MIME-Version: 1.0" . "\r\n";
$headers .= "Content-type:text/html;charset=UTF-8" . "\r\n";

// Additional headers
$headers .= "From: noreply@yourwebsite.com" . "\r\n";

// Send the email
if(mail($userEmail, $subject, $message, $headers)) {
    echo "A password recovery email has been sent to " . $userEmail;
} else {
    echo "Failed to send the email. Please try again later.";
}
?>
