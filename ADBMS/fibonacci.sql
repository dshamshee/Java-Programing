-- Create a function to calculate the nth Fibonacci number
CREATE OR REPLACE FUNCTION fibonacci (n IN NUMBER) 
RETURN NUMBER 
IS
   -- Declare variables for Fibonacci calculation
   a NUMBER := 0;
   b NUMBER := 1;
   c NUMBER := 0;
BEGIN
   -- Special case for 1st term (Fibonacci number at position 1)
   IF n = 1 THEN
      RETURN a;
   ELSIF n = 2 THEN
   RETURN b;
   ELSE
      -- Loop to calculate Fibonacci numbers for positions greater than 2
      FOR i IN 3..n LOOP
         c := a + b;      -- Fibonacci relation: F(n) = F(n-1) + F(n-2)
         a := b;          -- Move a to the next position
         b := c;          -- Move b to the next position
      END LOOP;
      RETURN c;           -- Return the Fibonacci number at position n
   END IF;
END;
/
-- Anonymous PL/SQL Block to generate Fibonacci series
DECLARE
   num_terms NUMBER := 10;  -- Set the number of terms to generate
   i NUMBER;
   fib NUMBER;
BEGIN
   -- Displaying the Fibonacci series header
   DBMS_OUTPUT.PUT_LINE('Fibonacci Series:');
   DBMS_OUTPUT.PUT_LINE('------------------');
   
   -- Loop to call the Fibonacci function and display the series
   FOR i IN 1..num_terms LOOP
      fib := fibonacci(i); -- Get the Fibonacci number at position i
      DBMS_OUTPUT.PUT_LINE('Term ' || i || ': ' || fib); -- Print each term
   END LOOP;
END;
/