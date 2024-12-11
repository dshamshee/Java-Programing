<?php
// Hardcoded string values
$string1 = "Hello, World!";
$string2 = "PHP is awesome";

// Perform string operations
$concatenation = $string1 . " " . $string2; // Concatenate two strings
$length1 = strlen($string1); // Length of string1
$length2 = strlen($string2); // Length of string2
$substring = substr($string1, 0, 5); // Get substring of string1
$uppercase1 = strtoupper($string1); // Convert string1 to uppercase
$lowercase2 = strtolower($string2); // Convert string2 to lowercase
$findWord = strpos($string1, "World"); // Find "World" in string1
$replaceWord = str_replace("World", "Universe", $string1); // Replace word in string1
$reverse1 = strrev($string1); // Reverse string1
$compare = strcmp($string1, $string2); // Compare two strings

// Output the results in the desired format
echo "<strong> String Value 1: </strong>" . $string1 . "<br>";
echo "<strong>String Value 2: </strong>" . $string2 . "<br><br>";

echo "<strong>Concatenation: </strong>" . $concatenation . "<br><br>";
echo "<strong>Length of String 1: </strong>" . $length1 . "<br><br>";
echo "<strong>Length of String 2: </strong>" . $length2 . "<br><br>";
echo "<strong>Substring of String 1 (first 5 chars): </strong>" . $substring . "<br><br>";
echo "<strong>Uppercase String 1: </strong>" . $uppercase1 . "<br><br>";
echo "<strong>Lowercase String 2: </strong>" . $lowercase2 . "<br><br>";
echo "<strong>Position of 'World' in String 1: </strong>" . ($findWord === false ? "Not found" : $findWord) . "<br><br>";
echo "<strong>Replace 'World' with 'Universe' in String 1: </strong>" . $replaceWord . "<br><br>";
echo "<strong>Reversed String 1: </strong>" . $reverse1 . "<br><br>";

if ($compare < 0) {
    echo "<strong>String 1 is less than String 2.<br></strong>";
} elseif ($compare > 0) {
    echo "<strong>String 1 is greater than String 2.<br></strong>";
} else {
    echo "<strong>String 1 is equal to String 2.<br></strong>";
}
?>
