--combine
SELECT a.xx, a.xxx, b.yy
    FROM Person a LEFT JOIN Big b ON a.id = b.id;

--if a is null then choose b
IFNULL(a,b) 