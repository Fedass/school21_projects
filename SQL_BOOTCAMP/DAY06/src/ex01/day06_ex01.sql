INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)
SELECT ROW_NUMBER( ) OVER ( ) AS id, po.person_id, menu.pizzeria_id, 
		CASE WHEN COUNT(pizzeria_id) = 1 THEN 10.5
		WHEN COUNT(pizzeria_id) = 2 THEN 22
		ELSE 30 END AS discount
FROM person_order AS po
JOIN menu ON po.menu_id = menu.id
GROUP BY po.person_id, menu.pizzeria_id

-- SELECT *
-- FROM person_discounts