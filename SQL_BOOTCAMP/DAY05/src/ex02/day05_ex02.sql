CREATE INDEX idx_person_name ON person USING BTREE(UPPER(name));

SET enable_seqscan = off;

EXPLAIN ANALYZE
SELECT name
FROM person
WHERE UPPER(name) = 'Peter'