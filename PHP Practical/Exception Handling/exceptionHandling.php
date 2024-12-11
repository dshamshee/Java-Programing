<?php
// Error Reporting: Display all errors
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Custom error handler
function customErrorHandler($errno, $errstr, $errfile, $errline) {
    echo "<b>Error:</b> [$errno] $errstr - in $errfile on line $errline<br>";
    // Log error to a file
    file_put_contents('error_log.txt', "$errstr in $errfile on line $errline\n", FILE_APPEND);
}
set_error_handler("customErrorHandler");

// Exception handler
function customExceptionHandler($exception) {
    echo "<b>Exception:</b> " . $exception->getMessage() . "<br>";
    // Log exception to a file
    file_put_contents('exception_log.txt', $exception->getMessage() . "\n", FILE_APPEND);
}
set_exception_handler("customExceptionHandler");

// Example: Trigger error
echo "Triggering an error:<br>";
trigger_error("This is a custom warning!", E_USER_WARNING);

// Example: Throw exception
echo "Throwing an exception:<br>";
throw new Exception("This is a custom exception!");

// Example: Divide by zero (Error)
echo "Dividing by zero:<br>";
echo 10 / 0;
?>
