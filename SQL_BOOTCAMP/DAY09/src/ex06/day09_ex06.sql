CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(pperson VARCHAR DEFAULT 'Dmitriy', 
																pprice NUMERIC DEFAULT 500, 
																pdate DATE DEFAULT '2022-01-08')
RETURNS TABLE(name VARCHAR)
AS $$
BEGIN 
	RETURN QUERY 
	SELECT DISTINCT pz.name
	FROM person_visits AS pv
	JOIN person AS p ON pv.person_id = p.id
	JOIN pizzeria AS pz ON pv.pizzeria_id = pz.id
	JOIN menu ON pz.id = menu.pizzeria_id
	WHERE p.name = pperson AND menu.price < pprice AND visit_date = pdate;
END;
$$ LANGUAGE plpgsql;

select *
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *
from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');