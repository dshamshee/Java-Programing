<?php
// Include event class
include('event_class.php');

// Handle form submission for adding a new event
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    // Get event details from the form
    $eventLabel = $_POST['eventLabel'];
    $fontSize = $_POST['fontSize'];
    $color = $_POST['color'];

    // Create a new event
    $newEvent = new Event($eventLabel, $fontSize, $color);

    // Read existing events from the file
    $eventsData = file_get_contents('events.json');
    $events = json_decode($eventsData, true);

    // Add the new event to the list
    $events[] = [
        'label' => $eventLabel,
        'font_size' => $fontSize,
        'color' => $color
    ];

    // Save updated events to the JSON file
    file_put_contents('events.json', json_encode($events, JSON_PRETTY_PRINT));

    // Redirect to homepage to see the added event
    header('Location: index.php');
    exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Admin Panel - Event Management</title>
</head>
<body>
    <h1>Admin Panel - Add New Event</h1>

    <form action="admin.php" method="POST">
        <label for="eventLabel">Event Label:</label>
        <input type="text" name="eventLabel" id="eventLabel" required><br><br>

        <label for="fontSize">Font Size:</label>
        <input type="number" name="fontSize" id="fontSize" required><br><br>

        <label for="color">Text Color:</label>
        <input type="color" name="color" id="color" required><br><br>

        <input type="submit" value="Add Event">
    </form>

    <br><br>
    <a href="index.php">Back to Events</a>
</body>
</html>
