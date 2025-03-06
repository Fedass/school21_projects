SELECT generated_date AS missing_dates
FROM v_generate_dates

EXCEPT

SELECT visit_date AS missing_dates
FROM person_visits AS pv
ORDER BY missing_dates
