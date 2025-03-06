CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS
SELECT DISTINCT pz.name
FROM person_visits AS pv
JOIN person AS p ON pv.person_id = p.id
JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id 
JOIN menu ON pz.id = menu.pizzeria_id
WHERE p.name = 'Dmitriy' AND pv.visit_date = '2022-01-08' AND price < 800
WITH DATA;


-- DROP MATERIALIZED VIEW mv_dmitriy_visits_and_eats;

-- SELECT *
-- FROM mv_dmitriy_visits_and_eats
