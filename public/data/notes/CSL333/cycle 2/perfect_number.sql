DECLARE
  n       NUMBER := &input_number;
  sum_div NUMBER := 0;
  i       NUMBER;
BEGIN
  IF n <= 1 THEN
    DBMS_OUTPUT.PUT_LINE(n || ' is NOT a perfect number');
  ELSE
    FOR i IN 1 .. n/2 LOOP
      IF MOD(n, i) = 0 THEN
        sum_div := sum_div + i;
      END IF;
    END LOOP;

    IF sum_div = n THEN
      DBMS_OUTPUT.PUT_LINE(n || ' is a Perfect number');
    ELSE
      DBMS_OUTPUT.PUT_LINE(n || ' is NOT a Perfect number');
    END IF;
  END IF;
END;
/
