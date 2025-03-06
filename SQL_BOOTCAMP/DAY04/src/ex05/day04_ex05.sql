CREATE VIEW v_price_with_discount AS
SELECT p.name, menu.pizza_name, price, CAST(price - (0.1*price) AS INT) AS discount_price
FROM person_order AS po
JOIN person AS p ON po.person_id = p.id
JOIN menu ON po.menu_id = menu.id
ORDER BY p.name, menu.pizza_name

-- SELECT *
-- FROM v_price_with_discount