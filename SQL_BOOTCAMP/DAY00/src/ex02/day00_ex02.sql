SELECT name, rating
FROM pizzeria
WHERE rating >= 3.5 AND rating <= 5
ORDER BY rating DESC

SELECT name, rating
FROM pizzeria
WHERE rating BETWEEN 3.5 and 5
ORDER BY rating DESC