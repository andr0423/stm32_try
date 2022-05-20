Create sqlite3 database first.
Create file

 touch mqtt.sqlite

Open database and create table

 sqlite mqtt.sqlite

 create table mqtt ("id" INTEGER PRIMARY KEY AUTOINCREMENT, "t" float , "p" float, "h" float, "date" int);

 insert into mqtt ("t","p","h","date")  values(02, 0.2, 0.2, 125);

 select * from mqtt;

 select * from mqtt where id > (select max(id) from mqtt) - 10;

