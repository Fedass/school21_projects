CREATE UNIQUE INDEX idx_menu_unique ON menu USING BTREE(pizzeria_id, pizza_name);

set enable_seqscan = off;

EXPLAIN ANALYZE

SELECT pizzeria_id, pizza_name
FROM menu
WHERE pizzeria_id = 5 AND pizza_name = 'cheese pizza'