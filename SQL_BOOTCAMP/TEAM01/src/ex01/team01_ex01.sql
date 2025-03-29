insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29'); 
insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');

SELECT COALESCE(u.name, 'not defined') AS name,
       COALESCE(u.lastname, 'not defined') AS lastname,
       c.name  AS currency_name,
       b.money * c.rate_to_usd AS currency_in_usd
FROM balance b
LEFT JOIN "user" AS u ON b.user_id = u.id
JOIN currency AS c ON (b.currency_id = c.id AND c.updated = COALESCE((SELECT MAX(c_past.updated)
                    													  FROM currency AS c_past
                    													  WHERE c.id = c_past.id AND b.updated >= c_past.updated
                    													  GROUP BY c_past.id),
                   														 (SELECT MIN(c_future.updated)
                    													  FROM currency AS c_future
                    													  WHERE c.id = c_future.id AND b.updated < c_future.updated
                    													  GROUP BY c_future.id)))
ORDER BY name DESC, lastname, currency_name
