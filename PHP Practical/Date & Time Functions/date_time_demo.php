<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Date and Time Functions Demo</title>
</head>
<body>
    <h1>Date and Time Functions Demo</h1>

    <?php
    // Set a base date and time
    $given_date = "2024-12-11";
    $given_time = "14:30:00";

    // Combine into a DateTime object
    $datetime = new DateTime("$given_date $given_time");

    // Display the original date and time
    echo "Given Date/Time: " . $datetime->format('Y-m-d H:i:s') . "<br><br>";

    // Array to store operations and results
    $operations = [];

    // Perform operations
    $operations[] = [
        "operation" => "Add 10 days",
        "result" => $datetime->modify('+10 days')->format('Y-m-d H:i:s')
    ];

    $operations[] = [
        "operation" => "Subtract 2 hours",
        "result" => $datetime->modify('-2 hours')->format('Y-m-d H:i:s')
    ];

    $operations[] = [
        "operation" => "Display only date",
        "result" => $datetime->format('Y-m-d')
    ];

    $operations[] = [
        "operation" => "Display only time",
        "result" => $datetime->format('H:i:s')
    ];

    $operations[] = [
        "operation" => "Get day of the week",
        "result" => $datetime->format('l') // Day of the week
    ];

    $operations[] = [
        "operation" => "Convert to Unix timestamp",
        "result" => $datetime->getTimestamp()
    ];

    $operations[] = [
        "operation" => "Convert from Unix timestamp to DateTime",
        "result" => (new DateTime())->setTimestamp($datetime->getTimestamp())->format('Y-m-d H:i:s')
    ];

    $operations[] = [
        "operation" => "Get difference from now",
        "result" => $datetime->diff(new DateTime())->format('%R%a days')
    ];

    // Display results
    echo "<table border='1' cellspacing='0' cellpadding='5'>";
    echo "<tr><th>Operation</th><th>Result</th></tr>";
    foreach ($operations as $op) {
        echo "<tr><td>{$op['operation']}</td><td>{$op['result']}</td></tr>";
    }
    echo "</table>";
    ?>
</body>
</html>
