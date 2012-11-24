SELECT tablename FROM pg_tables
WHERE tablename NOT LIKE 'pg\\_%'
AND tablename NOT LIKE 'sql\\_%';