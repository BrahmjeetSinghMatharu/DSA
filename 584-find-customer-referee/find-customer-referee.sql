-- SELECT name 
-- FROM Customer
-- WHERE referee_id IS NULL OR referee_id != 2;


-- SELECT name 
-- FROM Customer
-- WHERE CASE
--     WHEN referee_id IS NULL THEN 1
--     WHEN referee_id != 2 THEN 1
--     ELSE 0
-- END = 1;


-- SELECT name 
-- FROM Customer
-- WHERE CASE
--     WHEN referee_id IS NULL THEN TRUE
--     WHEN referee_id != 2 THEN TRUE
--     ELSE FALSE
-- END;



SELECT name
FROM Customer
WHERE COALESCE(referee_id, 0) != 2;