-- Creating a function to calculate factorial
CREATE OR REPLACE FUNCTION calculate_factorial(num IN NUMBER)
RETURN NUMBER IS
  factorial NUMBER := 1;
BEGIN
  IF num < 0 THEN
    RETURN NULL; -- Factorial is not defined for negative numbers
  ELSIF num = 0 THEN
    RETURN 1; -- Factorial of 0 is 1
  ELSE
    FOR i IN 1..num LOOP
      factorial := factorial * i;
    END LOOP;
    RETURN factorial;
  END IF;
END calculate_factorial;
/

-- Using an anonymous block to test the function
DECLARE
  input_number NUMBER := 5; -- Change this to test with other numbers
  result NUMBER;
BEGIN
  result := calculate_factorial(input_number);
  
  IF result IS NULL THEN
    DBMS_OUTPUT.PUT_LINE('Factorial is not defined for negative numbers.');
  ELSE
    DBMS_OUTPUT.PUT_LINE('The factorial of ' || input_number || ' is: ' || result);
  END IF;
END;
/