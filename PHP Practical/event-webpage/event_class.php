<?php
class Event {
    public $eventLabel;
    public $fontSize;
    public $color;

    // Constructor
    public function __construct($eventLabel, $fontSize, $color) {
        $this->eventLabel = $eventLabel;
        $this->fontSize = $fontSize;
        $this->color = $color;
    }

    // Destructor
    public function __destruct() {
        // Clean up code (if needed)
    }

    // Method to display the event
    public function show_event() {
        // Display event with applied styles
        echo "<div style='font-size:{$this->fontSize}px; color:{$this->color};'>";
        echo "<h3>{$this->eventLabel}</h3>";
        echo "</div>";
    }
}
?>
