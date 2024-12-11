<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_FILES['image'])) {
    // Set the upload directory
    $upload_dir = 'uploads/';

    // Check if the uploads directory exists
    if (!file_exists($upload_dir)) {
        echo "Uploads directory does not exist.";
        exit;
    }

    // Get the image name and target path
    $image_name = basename($_FILES['image']['name']);
    $target_file = $upload_dir . $image_name;

    // Check if the file is an image
    $imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));
    if (in_array($imageFileType, ['jpg', 'png', 'gif'])) {
        // Attempt to move the uploaded file to the uploads directory
        if (move_uploaded_file($_FILES['image']['tmp_name'], $target_file)) {
            // Redirect to output.php for image manipulation
            header("Location: output.php?image_path=" . urlencode($target_file));
            exit;
        } else {
            echo "Sorry, there was an error uploading your file.";
        }
    } else {
        echo "Only JPG, PNG & GIF files are allowed.";
    }
}
?>
