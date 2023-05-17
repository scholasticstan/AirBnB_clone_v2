-- SQL script to display the top 3 cities' temperatures during July and August ordered by temperature (descending)

USE hbtn_0c_0;

SELECT city, MAX(temperature) AS max_temperature
FROM weather
WHERE month IN ('July', 'August')
GROUP BY city
ORDER BY max_temperature DESC
LIMIT 3;

