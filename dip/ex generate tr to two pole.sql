CREATE OR REPLACE FUNCTION add_to_log() RETURNS TRIGGER AS $$ DECLARE 
mstr varchar(30);
astr_0 varchar(100);
astr_o_0 varchar(100);
astr_1 varchar(100);
astr_o_1 varchar(100);
tab text;
retstr varchar(254); 
BEGIN  IF TG_OP = 'INSERT' THEN
tab='';
astr_0=NEW.fio;
astr_1=NEW.num;

mstr := ' Add new ';
retstr := ' ';

if NEW.fio is not null then
retstr := retstr || mstr; 
retstr := retstr || astr_0;
end if;

if NEW.num is not null then
retstr := retstr || mstr; 
retstr := retstr || astr_1;
end if;


INSERT INTO logs(text,added) values (retstr,NOW());RETURN NEW;
ELSIF TG_OP = 'UPDATE' THEN 
astr_0= NEW.fio;
astr_1= NEW.num;
astr_o_0= OLD.fio;
astr_o_1= OLD.num;
mstr := ' Update to ';
retstr := ' ';

if (astr_0<>astr_o_0) then 
retstr := retstr || mstr; 
retstr := retstr || astr_0; 
retstr := retstr || ' from '; 
retstr := retstr || astr_o_0;
end if;

if (astr_1<>astr_o_1) then 
retstr := retstr || mstr; 
retstr := retstr || astr_1; 
retstr := retstr || ' from '; 
retstr := retstr || astr_o_1;
end if;

INSERT INTO logs(text,added) values (retstr,NOW()); RETURN NEW;
ELSIF TG_OP = 'DELETE' THEN 
astr_o_0= OLD.fio;
astr_o_1= OLD.num;
mstr := ' Remove ';
retstr := ' ';

if OLD.fio is not null then
retstr := retstr || mstr;
retstr := retstr || astr_o_0;
end if;
 
 if OLD.num is not null then
 retstr := retstr || mstr; 
 retstr := retstr || astr_o_1;
  end if;
 INSERT INTO logs(text,added) values (retstr,NOW());
 RETURN OLD;
 END IF;END;$$ LANGUAGE plpgsql;

CREATE TRIGGER log
AFTER INSERT OR UPDATE OR DELETE ON jilci FOR EACH ROW EXECUTE PROCEDURE add_to_log();