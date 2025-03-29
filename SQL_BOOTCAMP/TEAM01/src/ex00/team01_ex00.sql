WITH latest_currency AS (
	SELECT c1.id, c1.name AS currency_name, c1.rate_to_usd, c1.updated
	FROM currency AS c1
	WHERE c1.updated = (SELECT MAX(c2.updated)
						FROM currency AS c2
						WHERE c1.id = c2.id)
)							

SELECT COALESCE(u.name, 'not defined') AS name,
		COALESCE(u.lastname, 'not defined') AS lastname,
		b.type, SUM(b.money) AS volume, 
		COALESCE(lc.currency_name, 'not defined') AS currency_name,
		COALESCE(lc.rate_to_usd, 1) AS last_rate_to_usd,
		(SUM(b.money) * COALESCE(lc.rate_to_usd, 1)) AS total_volume_in_usd

		
FROM balance AS b
LEFT JOIN latest_currency AS lc ON b.currency_id = lc.id
LEFT JOIN "user" AS u ON b.user_id = u.id
GROUP BY name, lastname, b.type, lc.currency_name, lc.rate_to_usd
ORDER BY name DESC, lastname, b.type
