
WITH RECURSIVE hamiltonian_graph(total_cost, tour, last_node, start_node) AS (
	SELECT 0::numeric, ARRAY[name1], name1, name1
	FROM nodes 

	UNION ALL

	SELECT total_cost + nodes.costs, tour || name2, name2, start_node
	FROM hamiltonian_graph
	JOIN nodes ON last_node = name1
	WHERE NOT name2 = ANY(tour)
	
)

SELECT total_cost, tour || start_node AS tour
FROM (
    SELECT DISTINCT ON (tour) total_cost, tour, start_node
    FROM (
        SELECT total_cost + nodes.costs AS total_cost, tour, start_node
        FROM hamiltonian_graph
        JOIN nodes ON last_node = name1 AND name2 = start_node
        WHERE array_length(tour, 1) = (SELECT COUNT(DISTINCT name1) FROM nodes) AND
              last_node IN (SELECT start_node FROM hamiltonian_graph) AND
              start_node = 'a'
        ORDER BY total_cost, tour
    ) AS sorted_tours
    ORDER BY tour, total_cost
) AS distinct_tours
ORDER BY total_cost, tour