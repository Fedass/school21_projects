WITH pizza AS (
	SELECT pizza_name, pz.name, price
	FROM menu
	JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
)

SELECT p1.pizza_name, p1.name AS pizzeria_name_1, p2.name AS pizzeria_name_2, p1.price
FROM pizza AS p1
JOIN pizza AS p2 ON p1.pizza_name = p2.pizza_name AND p1.price = p2.price AND p1.name != p2.name AND p1.name < p2.name
ORDER BY p1.pizza_name