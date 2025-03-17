SET enable_seqscan = off;

EXPLAIN ANALYZE
SELECT pizza_name, pz.name AS pizzeria_name
FROM menu
JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id