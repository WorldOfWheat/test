DROP TABLE IF EXISTS test;
CREATE TABLE IF NOT EXISTS test(
	id INT PRIMARY KEY,
  	name TEXT NOT NULL,
  	age INT NOT NULL,
  	supervisor_id INT
);

INSERT INTO test VALUES (1, 'test001', 10, 1);
INSERT INTO test VALUES (2, 'test002', 20, 1);
INSERT INTO test VALUES (3, 'test003', 30, 2);
INSERT INTO test VALUES (4, 'test004', 40, 2);
INSERT INTO test VALUES (5, 'test005', 50, 3);
INSERT INTO test VALUES (5, 'test006', 20, 5);

DROP TABLE IF EXISTS test2;
CREATE TABLE IF NOT EXISTS test2(
	id INT PRIMARY KEY NOT NULL,
  	name TEXT NOT NULL,
  	age INT NOT NULL
);

INSERT INTO test2 VALUES (1, 'supervisor1', 10);
INSERT INTO test2 VALUES (2, 'supervisor2', 20);
INSERT INTO test2 VALUES (3, 'supervisor3', 20);
INSERT INTO test2 VALUES (4, 'supervisor4', 30);
INSERT INTO test2 VALUES (5, 'supervisor5', 35);

-- SELECT * FROM test;
-- SELECT * FROM test2;

SELECT name FROM test WHERE supervisor_id IN (SELECT id FROM test2 WHERE age >= 20);
