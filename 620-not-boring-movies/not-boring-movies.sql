-- SELECT *
-- FROM Cinema
-- WHERE id%2 != 0 AND description != "boring"
-- ORDER BY rating DESC;


SELECT *
FROM Cinema
WHERE MOD(id,2) <> 0 AND description NOT LIKE 'boring'
ORDER BY rating DESC;