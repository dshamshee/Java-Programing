<?php
// Declare variables of different types
$intVar = 10;                // Integer
$floatVar = 10.5;            // Float
$stringVar = "123.45";      // String
$boolVar = true;             // Boolean
$arrayVar = [1, 2, 3];       // Array

// Function to display variable information
function displayConversion($varName, $varValue, $convertedType, $convertedValue) {
    echo "$varName " . gettype($varValue) . " $convertedType $convertedValue<br>";
}

// Perform type casting and display results
// Integer variable
echo"<strong>Integer Value: $intVar</strong><br>";
displayConversion("intVar", $intVar, "float", (float)$intVar);
displayConversion("intVar", $intVar, "string", (string)$intVar);
displayConversion("intVar", $intVar, "boolean", (bool)$intVar);
echo"<br>";

// Float variable
echo"<strong>Float Value: $floatVar</strong> <br>";
displayConversion("floatVar", $floatVar, "integer", (int)$floatVar);
displayConversion("floatVar", $floatVar, "string", (string)$floatVar);
displayConversion("floatVar", $floatVar, "boolean", (bool)$floatVar);
echo"<br>";

// String variable
echo"<strong>String Value: $stringVar</strong> <br>";
displayConversion("stringVar", $stringVar, "integer", (int)$stringVar);
displayConversion("stringVar", $stringVar, "float", (float)$stringVar);
displayConversion("stringVar", $stringVar, "boolean", (bool)$stringVar);
echo"<br>";

// Boolean variable
echo"<strong>Boolean Value: $boolVar</strong> <br>";
displayConversion("boolVar", $boolVar, "integer", (int)$boolVar);
displayConversion("boolVar", $boolVar, "float", (float)$boolVar);
displayConversion("boolVar", $boolVar, "string", (string)$boolVar);
echo"<br>";

// Array variable (only to string, as other conversions may cause warnings)
echo"<strong>Array Value: [1,2,3]</strong> <br>";
displayConversion("arrayVar", $arrayVar, "string", json_encode($arrayVar));
?>
