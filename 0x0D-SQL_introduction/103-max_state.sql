-- SQL script to display the maximum temperature 
-- +of each state, ordered by state name

USE hbtn_0c_0;

SELECT state, MAX(temperature) AS max_temperature
FROM weather
GROUP BY state
ORDER BY state;
