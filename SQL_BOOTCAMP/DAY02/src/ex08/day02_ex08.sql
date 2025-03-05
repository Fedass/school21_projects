SELECT name
FROM person AS p
JOIN person_order AS po ON p.id = po.person_id
JOIN menu ON po.menu_id = menu.id
WHERE gender = 'male' AND (address = 'Moscow' OR address = 'Samara') AND (menu.pizza_name = 'pepperoni pizza' OR menu.pizza_name = 'mushroom pizza')
ORDER BY name DESC