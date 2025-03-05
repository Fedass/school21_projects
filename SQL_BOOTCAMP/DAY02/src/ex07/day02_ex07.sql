SELECT pz.name AS pizzeria_name
FROM pizzeria AS pz
JOIN person_visits AS pv ON pz.id = pv.pizzeria_id
JOIN person AS p ON pv.person_id = p.id
JOIN menu ON menu.pizzeria_id = pz.id
WHERE pv.visit_date = '2022-01-08' AND p.name = 'Dmitriy' AND menu.price < 800