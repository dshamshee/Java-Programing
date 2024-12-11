<?php
class SubjectMIS {
    private $connection;

    // Connect to the MySQL database
    public function connect() {
        // Use the database configuration
        require_once('config.php');
        
        $this->connection = new mysqli(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_DATABASE);
        
        // Check the connection
        if ($this->connection->connect_error) {
            die("Connection failed: " . $this->connection->connect_error);
        }
        echo "Connected successfully to database.<br>";
    }

    // Disconnect from the MySQL database
    public function disconnect() {
        if ($this->connection) {
            $this->connection->close();
            echo "Disconnected from database.<br>";
        }
    }

    // Select (Retrieve) subjects from the database
    public function select($subject_id = null) {
        if ($subject_id) {
            // Select a specific subject
            $stmt = $this->connection->prepare("SELECT * FROM subjects WHERE subject_id = ?");
            $stmt->bind_param("i", $subject_id);
        } else {
            // Select all subjects
            $stmt = $this->connection->prepare("SELECT * FROM subjects");
        }
        
        $stmt->execute();
        $result = $stmt->get_result();
        
        // Fetch all results
        while ($row = $result->fetch_assoc()) {
            echo "Subject ID: " . $row['subject_id'] . "<br>";
            echo "Subject Name: " . $row['subject_name'] . "<br><br>";
        }
        
        $stmt->close();
    }

    // Insert a new subject into the database
    public function insert($subject_name) {
        $stmt = $this->connection->prepare("INSERT INTO subjects (subject_name) VALUES (?)");
        $stmt->bind_param("s", $subject_name);
        
        if ($stmt->execute()) {
            echo "New subject '$subject_name' added successfully.<br>";
        } else {
            echo "Error inserting subject: " . $stmt->error . "<br>";
        }
        
        $stmt->close();
    }

    // Delete a subject from the database
    public function delete($subject_id) {
        $stmt = $this->connection->prepare("DELETE FROM subjects WHERE subject_id = ?");
        $stmt->bind_param("i", $subject_id);
        
        if ($stmt->execute()) {
            echo "Subject with ID '$subject_id' deleted successfully.<br>";
        } else {
            echo "Error deleting subject: " . $stmt->error . "<br>";
        }
        
        $stmt->close();
    }

    // Update a subject's name in the database
    public function update($subject_id, $new_subject_name) {
        $stmt = $this->connection->prepare("UPDATE subjects SET subject_name = ? WHERE subject_id = ?");
        $stmt->bind_param("si", $new_subject_name, $subject_id);
        
        if ($stmt->execute()) {
            echo "Subject ID '$subject_id' updated to '$new_subject_name'.<br>";
        } else {
            echo "Error updating subject: " . $stmt->error . "<br>";
        }
        
        $stmt->close();
    }
}
?>
