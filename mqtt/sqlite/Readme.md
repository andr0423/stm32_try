Sqlite3 DB
==========

Create sqlite3 database
-----------------------

Create file

 > touch mqtt.sqlite

Open database and create table

 > sqlite mqtt.sqlite  

 > create table mqtt ("id" INTEGER PRIMARY KEY AUTOINCREMENT, "t" float , "p" float, "h" float, "date" int);  

Insert into table

 > insert into mqtt ("t","p","h","date")  values( 0.2, 0.2, 0.2, 1234567890123 );  

Show table

 > select * from mqtt;  

Select last 10 rows

 > select * from mqtt where id > (select max(id) from mqtt) - 10;  


