-- SELECT v.customer_id, COUNT(*) AS count_no_trans
-- FROM Visits AS v
-- LEFT JOIN Transactions AS t
-- ON v.visit_id = t.visit_id
-- WHERE t.transaction_id IS NULL
-- GROUP BY v.customer_id;


SELECT customer_id, COUNT(*) AS count_no_trans
FROM Visits
WHERE visit_id NOT IN (SELECT visit_id FROM transactions)
GROUP BY customer_id;