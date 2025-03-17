SELECT name, count, action_type
FROM (
   (SELECT pizzeria_id, COUNT(*) AS count, 'order' AS action_type
	FROM person_order AS po
	JOIN menu ON po.menu_id = menu.id
	GROUP BY menu.pizzeria_id
	ORDER BY count DESC 
	LIMIT 3)
	
UNION ALL

	(SELECT pizzeria_id, COUNT(*) AS count, 'visit' AS action_type
	FROM person_visits AS pv
	GROUP BY pizzeria_id
	ORDER BY count DESC 
	LIMIT 3)) AS visits

JOIN pizzeria AS pz ON pz.id = visits.pizzeria_id
ORDER BY action_type, count DESC