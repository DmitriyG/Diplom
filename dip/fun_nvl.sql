CREATE FUNCTION nvl (text,text) RETURNS text AS '
BEGIN
if $1 is null then return $2;
else return $1;
end if;
END;
' LANGUAGE plpgsql;

CREATE FUNCTION nvl (integer,integer) RETURNS integer AS ' 
BEGIN
if $1 is null then return $2; 
else return $1; 
end if;
END;
' LANGUAGE plpgsql;