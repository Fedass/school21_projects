COMMENT ON TABLE person_discounts IS 'Stores personal discount information for each person and pizzeria. Discounts depend on the number of orders';
COMMENT ON COLUMN person_discounts.id IS 'Primary key. Unique identifier for each person';
COMMENT ON COLUMN person_discounts.person_id IS 'Foreign key. Refers to the person who gets the discount';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Foreign Key. Refers to the pizzeria where the discount applies';
COMMENT ON COLUMN person_discounts.discount IS 'Numeric percentage discount. Calculated based on order history. Ranges from 0 to 100%';

-- SELECT obj_description('person_discounts'::regclass, 'pg_class');
