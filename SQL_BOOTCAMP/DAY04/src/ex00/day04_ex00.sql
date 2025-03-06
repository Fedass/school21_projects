CREATE VIEW v_person_female AS 
SELECT id, name, age, gender, address 
FROM person AS p
WHERE gender = 'female';

CREATE VIEW v_person_male AS 
SELECT id, name, age, gender, address 
FROM person AS p
WHERE gender = 'male';


-- SELECT *
-- FROM v_person_male
-- SELECT *
-- FROM v_person_female