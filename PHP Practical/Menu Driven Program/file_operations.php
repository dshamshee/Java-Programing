<?php
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $action = $_POST['action'];
    $filePath = $_POST['filePath'];
}

function getFileSize($file) {
    return filesize($file) . " bytes";
}

function getFileTimes($file) {
    $lastAccess = date("F d Y H:i:s.", fileatime($file));
    $lastModified = date("F d Y H:i:s.", filemtime($file));
    $lastChanged = date("F d Y H:i:s.", filectime($file));
    
    return "Last Accessed: $lastAccess<br>Last Modified: $lastModified<br>Last Changed: $lastChanged";
}

function getFileOwner($file) {
    $owner = posix_getpwuid(fileowner($file));
    return "Owner: " . $owner['name'] . "<br>Group: " . $owner['gecos'];
}

function getFileType($file) {
    return "Type: " . filetype($file);
}

function deleteFile($file) {
    return unlink($file) ? "File deleted successfully!" : "Failed to delete file.";
}

function copyFile($source, $destination) {
    return copy($source, $destination) ? "File copied successfully!" : "Failed to copy file.";
}

function traverseDirectory($directory) {
    $files = [];
    if (is_dir($directory)) {
        $dir = opendir($directory);
        while (($file = readdir($dir)) !== false) {
            if ($file != "." && $file != "..") {
                $files[] = $file;
            }
        }
        closedir($dir);
    }
    return $files;
}

function removeDirectory($directory) {
    return rmdir($directory) ? "Directory removed successfully!" : "Failed to remove directory.";
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>File Operations</title>
</head>
<body>
    <h1>File Operations Menu</h1>
    <form method="POST">
        <label for="filePath">Enter File/Directory Path:</label>
        <input type="text" id="filePath" name="filePath" required>
        <br><br>
        <label for="action">Select Action:</label>
        <select id="action" name="action">
            <option value="size">Display Size of File</option>
            <option value="times">Display Last Access, Modified, Changed Time</option>
            <option value="owner">Display Owner and User Details</option>
            <option value="type">Display File Type</option>
            <option value="delete">Delete File</option>
            <option value="copy">Copy File</option>
            <option value="traverse">Traverse Directory</option>
            <option value="remove">Remove Directory</option>
        </select>
        <br><br>
        <input type="submit" value="Perform Action">
    </form>

    <?php
    if (isset($filePath) && isset($action)) {
        echo "<h2>Result:</h2>";
        switch ($action) {
            case 'size':
                if (file_exists($filePath)) {
                    echo "File Size: " . getFileSize($filePath);
                } else {
                    echo "File does not exist.";
                }
                break;

            case 'times':
                if (file_exists($filePath)) {
                    echo getFileTimes($filePath);
                } else {
                    echo "File does not exist.";
                }
                break;

            case 'owner':
                if (file_exists($filePath)) {
                    echo getFileOwner($filePath);
                } else {
                    echo "File does not exist.";
                }
                break;

            case 'type':
                if (file_exists($filePath)) {
                    echo getFileType($filePath);
                } else {
                    echo "File does not exist.";
                }
                break;

            case 'delete':
                if (file_exists($filePath)) {
                    echo deleteFile($filePath);
                } else {
                    echo "File does not exist.";
                }
                break;

            case 'copy':
                $destination = $_POST['destination'] ?? ''; // Input for destination path
                if (file_exists($filePath) && $destination) {
                    echo copyFile($filePath, $destination);
                } else {
                    echo "File or destination not valid.";
                }
                break;

            case 'traverse':
                if (is_dir($filePath)) {
                    $files = traverseDirectory($filePath);
                    echo "Files in the directory:<br>";
                    foreach ($files as $file) {
                        echo $file . "<br>";
                    }
                } else {
                    echo "Directory does not exist.";
                }
                break;

            case 'remove':
                if (is_dir($filePath)) {
                    echo removeDirectory($filePath);
                } else {
                    echo "Directory does not exist.";
                }
                break;

            default:
                echo "Invalid Action.";
        }
    }
    ?>
</body>
</html>
