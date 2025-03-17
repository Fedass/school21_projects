SELECT p.name AS name, pizza_name, price, CAST(price * (1 - pd.discount / 100) AS NUMERIC(18,2)) AS discount_price, pz.name AS pizzeria_name
FROM person_order AS po
JOIN person AS p ON po.person_id = p.id
JOIN menu ON po.menu_id = menu.id
JOIN pizzeria AS pz ON menu.pizzeria_id = pz.id
JOIN person_discounts AS pd ON pz.id = pd.pizzeria_id AND p.id = pd.person_id
ORDER BY name, pizza_name