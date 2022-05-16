
dt = $(shell date +%s)

test_send:
	@# terminal 1
	mosquitto_pub -h localhost -t test -m '{"t": 20.00, "p": 765.00, "h": 50.00, "date": $(dt) }'

test_hello:
	@# terminal 1
	mosquitto_pub -h localhost -t test -m "Hello, Mosquitto"

test_catch:
	@# terminal 2
	mosquitto_sub -h localhost -t vkr_topic

show_conf:
	cat /usr/local/etc/mosquitto/mosquitto.conf | grep -vE '^#|^$$'

SQLITE_DB=../../sqlite/mqtt.sqlite

sql:
	sqlite3 --box -header $(SQLITE_DB) 'select * from mqtt where id > (select max(id) from mqtt) -10 ;'
	sqlite3 --column -header $(SQLITE_DB) 'select count(id) as "COUNT" from mqtt;'

drop_sql:
	sqlite3 $(SQLITE_DB) 'delete from mqtt;'
	rm -f $(SQLITE_DB)

create_sql:
	touch ../../sqlite/mqtt.sqlite
	sqlite3 ../../sqlite/mqtt.sqlite 'create table mqtt ("id" INTEGER PRIMARY KEY AUTOINCREMENT, "t" float , "p" float, "h" float, "date" int);'

start:
	@echo Start mosquitto
	brew services start mosquitto

stop:
	@echo Stop mosquitto
	@brew services stop mosquitto

status:
	@echo Status mosquitto
	@(brew services | grep -E '^Name|^mosquitto')


