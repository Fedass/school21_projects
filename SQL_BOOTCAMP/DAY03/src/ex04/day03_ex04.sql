WITH orders AS (
	SELECT DISTINCT pz.name AS pizzeria_name, p.gender
	FROM person_order AS po
	JOIN menu ON po.menu_id = menu.id
	JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
	JOIN person AS p ON po.person_id = p.id
),

men AS (
	SELECT pizzeria_name
	FROM orders
	WHERE gender = 'male'
	
	EXCEPT ALL 
	
	SELECT pizzeria_name
	FROM orders
	WHERE gender = 'female'
),

women AS (
	SELECT pizzeria_name
	FROM orders
	WHERE gender = 'female'
	
	EXCEPT ALL 
	
	SELECT pizzeria_name
	FROM orders
	WHERE gender = 'male'
	ORDER BY pizzeria_name
)

SELECT pizzeria_name
FROM men

UNION

SELECT pizzeria_name
FROM women
ORDER BY pizzeria_name

