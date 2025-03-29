DROP FUNCTION IF EXISTS fnc_persons_female();
DROP FUNCTION IF EXISTS fnc_persons_male();

CREATE OR REPLACE FUNCTION fnc_persons(pgender TEXT DEFAULT 'female')
RETURNS TABLE (id BIGINT, name VARCHAR, age INTEGER, gender VARCHAR, address VARCHAR)
AS $$
	SELECT id, name, age, gender, address
	FROM person
	WHERE gender = pgender;
$$ LANGUAGE SQL;

select *
from fnc_persons();

select *
from fnc_persons(pgender := 'male');
