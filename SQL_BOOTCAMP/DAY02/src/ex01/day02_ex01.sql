SELECT gen::date AS missing_date
FROM generate_series('2022-01-01', '2022-01-10', '1 day'::interval) AS gen
LEFT JOIN (SELECT *
		   FROM person_visits
		   where person_id = 1 OR person_id = 2) as pv
ON visit_date = gen
WHERE visit_date IS NULL
ORDER BY missing_date