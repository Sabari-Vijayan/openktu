DECLARE
  ipstring        varchar(20):= &input_number;
  reversed_string VARCHAR(20);
BEGIN
  SELECT REVERSE(ipstring) INTO reversed_string FROM DUAL;
  if ipstring=reversed_string then 
    dbms_output.put_line('Palindrome');
  else
    dbms_output.put_line('Not palindrome');
  end if;
END;
/
