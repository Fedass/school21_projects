INSERT INTO person_order (id, person_id, menu_id, order_date)
SELECT (SELECT MAX(id) + gs.id FROM person_order GROUP BY gs.id),
		gs.id, (SELECT id FROM menu WHERE pizza_name = 'greek pizza'),
		'2022-02-25'
FROM generate_series(1, (SELECT COUNT(id) FROM person)) AS gs(id)

-- SELECT *
-- FROM person_order
