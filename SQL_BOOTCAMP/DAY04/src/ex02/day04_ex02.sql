CREATE VIEW v_generate_dates AS
SELECT gen::date AS generated_date
FROM generate_series('2022-01-01', '2022-01-31', '1 day'::interval) AS gen

-- SELECT *
-- FROM v_generate_dates