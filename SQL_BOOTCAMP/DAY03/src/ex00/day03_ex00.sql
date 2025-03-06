SELECT pizza_name, price, pz.name AS pizzeria_name, visit_date
FROM person_visits AS pv
JOIN person AS p ON pv.person_id = p.id
JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
JOIN menu ON pz.id = menu.pizzeria_id
WHERE p.name = 'Kate' AND menu.price BETWEEN 800 AND 1000
ORDER BY pizza_name, price, pizzeria_name