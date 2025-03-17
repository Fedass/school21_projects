CREATE table nodes (
	name1 varchar not null,
	name2 varchar not null,
	costs numeric not null default 1
);

INSERT INTO nodes VALUES ('a', 'b', 10);
INSERT INTO nodes VALUES ('a', 'c', 15);
INSERT INTO nodes VALUES ('a', 'd', 20);
INSERT INTO nodes VALUES ('b', 'a', 10);
INSERT INTO nodes VALUES ('b', 'c', 35);
INSERT INTO nodes VALUES ('b', 'd', 25);
INSERT INTO nodes VALUES ('c', 'a', 15);
INSERT INTO nodes VALUES ('c', 'b', 35);
INSERT INTO nodes VALUES ('c', 'd', 30);
INSERT INTO nodes VALUES ('d', 'a', 20);
INSERT INTO nodes VALUES ('d', 'b', 25);
INSERT INTO nodes VALUES ('d', 'c', 30);

WITH RECURSIVE hamiltonian_graph(total_cost, tour, last_node) AS (
    SELECT 0::NUMERIC, ARRAY['a'], 'a'::VARCHAR 
    
    UNION ALL

    SELECT total_cost + nodes.costs, tour || name2, name2
    FROM hamiltonian_graph
    JOIN nodes ON last_node = name1
    WHERE NOT name2 = ANY(tour)
)


SELECT total_cost, tour || '{a}' AS tour
FROM (
    SELECT total_cost + nodes.costs AS total_cost, tour
    FROM hamiltonian_graph
    JOIN nodes ON last_node = name1 AND name2 = 'a'  
    WHERE array_length(tour, 1) = (SELECT COUNT(DISTINCT name1) FROM nodes)
) AS all_tours
WHERE total_cost = (SELECT MIN(total_cost) FROM (
    SELECT total_cost + nodes.costs AS total_cost
    FROM hamiltonian_graph
    JOIN nodes ON last_node = name1 AND name2 = 'a'
    WHERE array_length(tour, 1) = (SELECT COUNT(DISTINCT name1) FROM nodes)
) AS min_cost)
ORDER BY total_cost, tour;