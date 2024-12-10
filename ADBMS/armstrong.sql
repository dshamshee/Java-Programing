-- Creating a function to check Armstrong number
CREATE OR REPLACE FUNCTION is_armstrong(num IN NUMBER)
RETURN BOOLEAN IS
  digit NUMBER;
  sum_of_powers NUMBER := 0;
  temp NUMBER := num;
  num_of_digits NUMBER := 0;
BEGIN
  -- Calculate the number of digits
  WHILE temp > 0 LOOP
    num_of_digits := num_of_digits + 1;
    temp := FLOOR(temp / 10); -- Correct division to get integer part
  END LOOP;

  -- Reset temp to the input number
  temp := num;

  -- Calculate the sum of digits raised to the power of num_of_digits
  WHILE temp > 0 LOOP
    digit := MOD(temp, 10); -- Extract the last digit
    sum_of_powers := sum_of_powers + POWER(digit, num_of_digits);
    temp := FLOOR(temp / 10); -- Remove the last digit
  END LOOP;

  -- Check if the sum of powers equals the original number
  RETURN sum_of_powers = num;
END is_armstrong;
/

-- Using an anonymous block to print Armstrong numbers within a range
DECLARE
  start_num NUMBER := 1; -- Starting number
  end_num NUMBER := 1000; -- Ending number
BEGIN
  DBMS_OUTPUT.PUT_LINE('Armstrong Numbers between ' || start_num || ' and ' || end_num || ':');
  FOR i IN start_num..end_num LOOP
    IF is_armstrong(i) THEN
      DBMS_OUTPUT.PUT_LINE(i);
    END IF;
  END LOOP;
END;
/