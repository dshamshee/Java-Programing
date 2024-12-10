-- Create a PL/SQL package specification
CREATE OR REPLACE PACKAGE math_operations AS
   -- Procedure to add two numbers with an output parameter
   PROCEDURE add_numbers(x NUMBER, y NUMBER, result OUT NUMBER);

   -- Function to multiply two numbers
   FUNCTION multiply_numbers(x NUMBER, y NUMBER) RETURN NUMBER;
END math_operations;
/

-- Create the body of the math_operations package
CREATE OR REPLACE PACKAGE BODY math_operations AS
   -- Implementation of the add_numbers procedure
   PROCEDURE add_numbers(x NUMBER, y NUMBER, result OUT NUMBER) IS
   BEGIN
      result := x + y;
   END add_numbers;
    -- Implementation of the multiply_numbers function
   FUNCTION multiply_numbers(x NUMBER, y NUMBER) RETURN NUMBER IS
   BEGIN
      RETURN x * y;
   END multiply_numbers;
END math_operations;
/

-- PL/SQL block to test the math_operations package
DECLARE
   -- Declare variables to store results
   sum_result NUMBER;
   product_result NUMBER;
BEGIN
   -- Call the procedure and pass output parameter
   math_operations.add_numbers(5, 7, sum_result);
   -- Display the result of the add_numbers procedure
   DBMS_OUTPUT.PUT_LINE('Sum Result: ' || sum_result);

   -- Call the function and retrieve the result
   product_result := math_operations.multiply_numbers(3, 4);
   -- Display the result of the multiply_numbers function
   DBMS_OUTPUT.PUT_LINE('Product Result: ' || product_result);
END;
/