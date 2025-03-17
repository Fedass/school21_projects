SELECT p.name, COUNT(*) AS count_of_visits
FROM person_visits AS pv 
JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
JOIN person AS p ON pv.person_id = p.id
GROUP BY 1
HAVING COUNT(*) > 3