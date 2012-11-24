SELECT attname FROM pg_attribute, pg_type
WHERE typname = 'jilci'
AND attrelid = typrelid
AND attname NOT IN ('cmin', 'cmax', 'ctid', 'oid', 'tableoid', 'xmin', 'xmax');
