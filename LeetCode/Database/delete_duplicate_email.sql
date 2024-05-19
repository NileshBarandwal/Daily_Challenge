# Write your MySQL query statement below
-- DELETE FROM Person 
-- WHERE id NOT IN (
--     SELECT id FROM (
--         SELECT MIN(id) as id
--         FROM Person
--         GROUP BY email
--     ) as temp
-- );

DELETE p1 FROM Person p1
JOIN Person p2 ON p1.email = p2.email AND p1.id > p2.id;