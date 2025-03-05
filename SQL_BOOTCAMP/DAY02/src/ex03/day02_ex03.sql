WITH filtered_visits AS (
	SELECT *
	FROM person_visits
	WHERE person_id = 1 OR person_id = 2
)

SELECT gen::date AS missing_date
FROM generate_series('2022-01-01', '2022-01-10', '1 day'::interval) AS gen
LEFT JOIN filtered_visits ON visit_date = gen
WHERE visit_date IS NULL
ORDER BY missing_date