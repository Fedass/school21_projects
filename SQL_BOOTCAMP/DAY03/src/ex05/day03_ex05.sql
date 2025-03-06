WITH andrey_visits AS (
	SELECT pz.name AS pizzeria_name
	FROM person_visits AS pv
	JOIN person AS p ON p.id = pv.person_id
	JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
	WHERE p.name = 'Andrey' 
), 

andrey_orders AS (
	SELECT pz.name AS pizzeria_name
	FROM person_order AS po
	JOIN person AS p ON p.id = po.person_id
	JOIN menu ON po.menu_id = menu.id
	JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
	WHERE p.name = 'Andrey'
)

SELECT pizzeria_name
FROM andrey_visits

EXCEPT

SELECT pizzeria_name
FROM andrey_orders
ORDER BY pizzeria_name


