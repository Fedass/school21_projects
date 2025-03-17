SELECT pv.person_id, COUNT(pizzeria_id) AS count_of_visits
FROM person_visits AS pv
JOIN person AS p ON pv.person_id = p.id
JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
GROUP BY person_id
ORDER BY count_of_visits DESC, person_id