DECLARE
  n       NUMBER := &num_terms;        
  a       NUMBER := 0;
  b       NUMBER := 1;
  c       NUMBER;
  i       NUMBER;
BEGIN
  IF n <= 0 THEN
    DBMS_OUTPUT.PUT_LINE('Please enter a positive number of terms');
  ELSIF n = 1 THEN
    DBMS_OUTPUT.PUT_LINE('Fibonacci series: ' || a);
  ELSE
    DBMS_OUTPUT.PUT_LINE('Fibonacci series:');
    DBMS_OUTPUT.PUT_LINE(a);
    DBMS_OUTPUT.PUT_LINE(b);
    FOR i IN 3 .. n LOOP
      c := a + b;
      DBMS_OUTPUT.PUT_LINE(c);
      a := b;
      b := c;
    END LOOP;
  END IF;
END;
/
