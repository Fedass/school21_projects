SELECT p.address, pz.name, COUNT(po.person_id) AS count_of_orders 
FROM person_order AS po
JOIN person AS p ON po.person_id = p.id
JOIN menu ON po.menu_id = menu.id
JOIN pizzeria AS pz ON pz.id = menu.pizzeria_id
GROUP BY p.address, pz.name
ORDER BY address, name