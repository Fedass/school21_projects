SELECT address, CAST((MAX(age) - (MIN(age)::float4 / MAX(age))) AS NUMERIC(10, 2)) AS formula, ROUND(AVG(age), 2) AS average,
	CASE WHEN (MAX(age) - (MIN(age) / MAX(age))) > ROUND(AVG(age), 2) THEN 'true'
	ELSE 'false' END AS comparison
FROM person
GROUP BY address
ORDER BY address