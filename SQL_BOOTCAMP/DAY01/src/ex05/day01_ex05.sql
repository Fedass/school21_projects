SELECT p1.id AS person_id, p1.name AS person_name, age, gender, address,
	p2.id AS pizzeria_id, p2.name AS pizzeria_name, rating
FROM person AS p1, pizzeria AS p2
ORDER BY person_id, pizzeria_id
