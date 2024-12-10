CREATE OR REPLACE PROCEDURE check_prime (num IN NUMBER) IS 
   -- Declare a variable to check for divisibility 
   is_prime BOOLEAN := TRUE; 
BEGIN 
   -- Special case: Numbers less than 2 are not prime 
   IF num <= 1 THEN 
      is_prime := FALSE; 
   ELSIF num = 2 THEN 
      -- 2 is a prime number 
      is_prime := TRUE; 
   ELSE 
-- Loop to check divisibility from 2 to sqrt(num) 
      FOR i IN 2..TRUNC(SQRT(num)) LOOP 
         IF num MOD i = 0 THEN 
            is_prime := FALSE;  -- If divisible by i, then it's not prime 
            EXIT;  -- Exit the loop early as we found a divisor 
         END IF; 
      END LOOP; 
   END IF;
 -- Display the result based on whether the number is prime or not 
   IF is_prime THEN 
      DBMS_OUTPUT.PUT_LINE(num || ' is a prime number.'); 
   ELSE 
   DBMS_OUTPUT.PUT_LINE(num || ' is not a prime number.'); 
   END IF; 
END; 
/  
DECLARE 
   num NUMBER := 29;  -- You can change this number to test other values 
BEGIN 
   -- Call the procedure to check if the number is prime 
   check_prime(num); 
END; 
/ 