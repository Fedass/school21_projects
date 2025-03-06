WITH visits AS (
	SELECT pz.name AS pizzeria_name, p.gender
	FROM person_visits AS pv
	JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
	JOIN person AS p ON pv.person_id = p.id
)

(SELECT pizzeria_name
FROM visits
WHERE gender = 'male'

EXCEPT ALL 

SELECT pizzeria_name
FROM visits
WHERE gender = 'female'
)

UNION ALL

(SELECT pizzeria_name
FROM visits
WHERE gender = 'female'

EXCEPT ALL 

SELECT pizzeria_name
FROM visits
WHERE gender = 'male'
ORDER BY pizzeria_name
)
