<?php
// Include event class
include('event_class.php');

// Read events data from a JSON file
$eventsData = file_get_contents('events.json');
$events = json_decode($eventsData, true);

// Create Event objects from the stored data
$eventObjects = [];
foreach ($events as $event) {
    $eventObjects[] = new Event($event['label'], $event['font_size'], $event['color']);
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Online Events</title>
    <link rel="stylesheet" href="styles.css">
</head>
<body>
    <h1>Upcoming Events</h1>
    <div id="event-list">
        <?php
        // Display events using the show_event method
        foreach ($eventObjects as $event) {
            $event->show_event();
        }
        ?>
    </div>
    <br>
    <a href="admin.php">Admin Panel</a>
</body>
</html>
