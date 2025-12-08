DECLARE
  n NUMBER := &input_number;
BEGIN
  IF MOD(n, 2) = 0 THEN
    DBMS_OUTPUT.PUT_LINE(n || ' is Even');
  ELSE
    DBMS_OUTPUT.PUT_LINE(n || ' is Odd');
  END IF;
END;
/
