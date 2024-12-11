<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Image Manipulation</title>
</head>
<body>
    <h1>PHP Image Manipulation</h1>

    <!-- Form for uploading an image -->
    <form action="upload.php" method="POST" enctype="multipart/form-data">
        <label for="image">Upload an Image:</label>
        <input type="file" name="image" id="image" required>
        <input type="submit" value="Upload">
    </form>

    <h2>Manipulate the Image:</h2>
    <form action="output.php" method="POST">
        <label for="resize_width">Resize Width:</label>
        <input type="number" name="resize_width" id="resize_width" required>
        <label for="resize_height">Resize Height:</label>
        <input type="number" name="resize_height" id="resize_height" required>
        <br><br>

        <label for="crop_x">Crop X (top left corner):</label>
        <input type="number" name="crop_x" id="crop_x" required>
        <label for="crop_y">Crop Y (top left corner):</label>
        <input type="number" name="crop_y" id="crop_y" required>
        <br><br>

        <label for="crop_width">Crop Width:</label>
        <input type="number" name="crop_width" id="crop_width" required>
        <label for="crop_height">Crop Height:</label>
        <input type="number" name="crop_height" id="crop_height" required>
        <br><br>

        <label for="format">Select Output Format:</label>
        <select name="format" id="format">
            <option value="jpg">JPEG</option>
            <option value="png">PNG</option>
            <option value="gif">GIF</option>
        </select>
        <br><br>

        <input type="hidden" name="image_path" value="">
        <input type="submit" value="Manipulate Image">
    </form>

</body>
</html>
