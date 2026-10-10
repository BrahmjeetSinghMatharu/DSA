SELECT today.id 
FROM Weather as today
INNER JOIN Weather as yesterday
ON today.recordDate = DATE_ADD(yesterday.recordDate,INTERVAL 1 DAY)
WHERE today.temperature > yesterday.temperature;