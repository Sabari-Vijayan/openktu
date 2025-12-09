DECLARE
  x  NUMBER := &num1;
  y  NUMBER := &num2;
  op CHAR := &operator;
  result NUMBER;
BEGIN
  CASE op
    WHEN '+' THEN
      result := x + y;
    WHEN '-' THEN
      result := x - y;
    WHEN '*' THEN
      result := x * y;
    WHEN '/' THEN
      IF y = 0 THEN
        DBMS_OUTPUT.PUT_LINE('Division by zero error');
        RETURN;
      ELSE
        result := x / y;
      END IF;
    ELSE
      DBMS_OUTPUT.PUT_LINE('Invalid operator');
      RETURN;
  END CASE;

  DBMS_OUTPUT.PUT_LINE('Result of ' || x || ' ' || op || ' ' || y || ' = ' || result);
END;
/
