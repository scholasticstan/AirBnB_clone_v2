-- SQL script to display the average temperature (Fahrenheit)
-- +by city ordered by temperature (descending)

USE hbtn_0c_0;

SELECT city, AVG(temperature) AS avg_temperature
FROM weather
GROUP BY city
ORDER BY avg_temperature DESC;

