CREATE INDEX idx_person_order_multi ON person_order USING BTREE (person_id, menu_id, order_date);

SET enable_seqscan = off;

EXPLAIN ANALYZE
SELECT person_id, menu_id,order_date
FROM person_order
WHERE person_id = 8 AND menu_id = 19;

-- DROP INDEX IF EXISTS idx_person_order_multi