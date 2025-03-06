SELECT menu.id AS menu_id
FROM menu

EXCEPT

SELECT po.menu_id
FROM person_order AS po
ORDER BY menu_id