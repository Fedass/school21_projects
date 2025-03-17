CREATE UNIQUE INDEX idx_person_discounts_unique ON person_discounts USING BTREE(person_id, pizzeria_id);

SET enable_seqscan = off;

EXPLAIN ANALYZE
SELECT *
FROM person_discounts
WHERE discount < 30
