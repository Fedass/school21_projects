SELECT pz.name, COUNT(*) AS count_of_orders, 
	ROUND(AVG(menu.price), 2) AS average_price, 
	MAX(menu.price) AS max_price, 
	MIN(menu.price) AS min_price
FROM person_order AS po
JOIN menu ON po.menu_id = menu.id
JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
GROUP BY pz.name
ORDER BY pz.name
