WITH table_orders AS (
	SELECT pizzeria_id, COUNT(*) AS count
	FROM person_order AS po
	JOIN menu ON po.menu_id = menu.id
	GROUP BY menu.pizzeria_id
	ORDER BY count DESC 
),

table_visits AS (
	SELECT pizzeria_id, COUNT(*) AS count
	FROM person_visits AS pv
	GROUP BY pizzeria_id
	ORDER BY count DESC
)

SELECT pz.name, COALESCE(table_orders.count, 0) + COALESCE(table_visits.count, 0) AS total_count
FROM table_orders 
FULL OUTER JOIN table_visits ON table_orders.pizzeria_id = table_visits.pizzeria_id
LEFT JOIN pizzeria pz ON COALESCE(table_orders.pizzeria_id, table_visits.pizzeria_id) = pz.id
ORDER BY total_count DESC, pz.name 
