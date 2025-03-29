CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop INTEGER DEFAULT 10)
RETURNS TABLE(fib_num INTEGER) AS $$
	WITH RECURSIVE fib_series(a, b) AS (
		SELECT 0, 1
		UNION ALL
		SELECT b, a + b
		FROM fib_series
		WHERE b < pstop
	)
	SELECT a
	FROM fib_series;
$$ LANGUAGE SQL;

select * from fnc_fibonacci(100);
select * from fnc_fibonacci();