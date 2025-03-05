SELECT menu.pizza_name, pz.name AS pizzeria_name
FROM person_order AS po
JOIN (SELECT *
	  FROM person
	  WHERE name = 'Denis' or name = 'Anna') AS p ON po.person_id = p.id 
JOIN menu ON po.menu_id = menu.id
JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
ORDER BY pizza_name, pizzeria_name