SELECT p.name
FROM person AS p
JOIN person_order AS po ON p.id = po.person_id
JOIN menu ON po.menu_id = menu.id
WHERE p.gender = 'female' AND menu.pizza_name IN ('pepperoni pizza', 'cheese pizza') 
GROUP BY p.name
HAVING COUNT(DISTINCT menu.pizza_name) = 2
ORDER BY p.name