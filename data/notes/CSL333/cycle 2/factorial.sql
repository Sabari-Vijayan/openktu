DECLARE
  n     NUMBER := &input_number;
  fact  NUMBER := 1;
  i     NUMBER;
BEGIN
  IF n < 0 THEN
    DBMS_OUTPUT.PUT_LINE('Factorial not defined for negative numbers');
  ELSE
    FOR i IN 1 .. n LOOP
      fact := fact * i;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('Factorial of ' || n || ' is: ' || fact);
  END IF;
END;
/
