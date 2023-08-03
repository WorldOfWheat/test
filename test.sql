drop table test;
create table test(
	ID INT PRIMARY KEY,
  	name TEXT,
  	AGE INT,
  	supervisor INT
);

insert into test VALUES (1, 'test001', 10, 2);
insert into test VALUES (2, 'test002', 20, 1);
insert into test VALUES (3, 'test003', 30, 3);
insert into test VALUES (4, 'test004', 40, 1);
insert into test VALUES (5, 'test005', 50, NULL);

drop table test2;
create table test2(
	ID INT PRIMARY KEY NOT NULL,
  	name TEXT NOT NULL,
  	AGE INT NOT NULL
);

insert into test2 VALUES (1, 'supervisor1', 10);
insert into test2 VALUES (2, 'supervisor2', 20);
insert into test2 VALUES (3, 'supervisor3', 30);

select * from test;

-- update test set name = 'test555';
delete from test where name == 'test004';

select * from test;
