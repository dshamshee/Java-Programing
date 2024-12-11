<?php
if (isset($_GET['image_path'])) {
    $image_path = urldecode($_GET['image_path']);
    if (!file_exists($image_path)) {
        die("Image not found.");
    }

    // Load image
    $image = null;
    $image_info = getimagesize($image_path);
    $image_type = $image_info[2];

    // Create an image resource from the uploaded file based on its type
    switch ($image_type) {
        case IMAGETYPE_JPEG:
            $image = imagecreatefromjpeg($image_path);
            break;
        case IMAGETYPE_PNG:
            $image = imagecreatefrompng($image_path);
            break;
        case IMAGETYPE_GIF:
            $image = imagecreatefromgif($image_path);
            break;
        default:
            die("Unsupported image format.");
    }

    // Resize Image
    if (isset($_POST['resize_width']) && isset($_POST['resize_height'])) {
        $resize_width = $_POST['resize_width'];
        $resize_height = $_POST['resize_height'];
        $image_resized = imagescale($image, $resize_width, $resize_height);
    }

    // Crop Image
    if (isset($_POST['crop_x']) && isset($_POST['crop_y']) && isset($_POST['crop_width']) && isset($_POST['crop_height'])) {
        $crop_x = $_POST['crop_x'];
        $crop_y = $_POST['crop_y'];
        $crop_width = $_POST['crop_width'];
        $crop_height = $_POST['crop_height'];
        $image_cropped = imagecrop($image, ['x' => $crop_x, 'y' => $crop_y, 'width' => $crop_width, 'height' => $crop_height]);
    }

    // Apply Watermark (Optional)
    if (file_exists('watermark.png')) {
        $watermark = imagecreatefrompng('watermark.png');
        $sx = imagesx($watermark);
        $sy = imagesy($watermark);
        imagecopy($image, $watermark, imagesx($image) - $sx - 10, imagesy($image) - $sy - 10, 0, 0, $sx, $sy);
    }

    // Output Image
    $output_format = $_POST['format'] ?? 'jpg';
    switch ($output_format) {
        case 'jpg':
            header('Content-Type: image/jpeg');
            imagejpeg($image);
            break;
        case 'png':
            header('Content-Type: image/png');
            imagepng($image);
            break;
        case 'gif':
            header('Content-Type: image/gif');
            imagegif($image);
            break;
        default:
            echo "Invalid format.";
            break;
    }

    // Clean up
    imagedestroy($image);
    if (isset($image_resized)) {
        imagedestroy($image_resized);
    }
    if (isset($image_cropped)) {
        imagedestroy($image_cropped);
    }
}
?>
