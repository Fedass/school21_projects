SELECT p.name, COUNT(pizzeria_id) AS count_of_visits 
FROM person_visits AS pv
JOIN person AS p ON pv.person_id = p.id
JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
GROUP BY p.name
ORDER BY count_of_visits DESC, p.name
LIMIT 4