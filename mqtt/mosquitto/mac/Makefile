
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


DIR   = $(abspath $(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
SQLITE_DB=$(DIR)/../../sqlite/mqtt.sqlite

sql: sql_create
	@sqlite3 --box -header $(SQLITE_DB) 'select * from mqtt where id > (select max(id) from mqtt) -10 ;'
	@sqlite3 --column -header $(SQLITE_DB) 'select count(id) as "COUNT" from mqtt;'

sql_delete:
	-sqlite3 $(SQLITE_DB) 'delete from mqtt;'

sql_drop:
	-rm -f   $(SQLITE_DB)

sql_create: $(SQLITE_DB)

$(SQLITE_DB):
	touch   $(SQLITE_DB)
	sqlite3 $(SQLITE_DB) 'CREATE TABLE IF NOT EXISTS mqtt ("id" INTEGER PRIMARY KEY AUTOINCREMENT, "t" float , "p" float, "h" float, "date" int);'

sql_clean: sql_drop sql_create



mosquitto_start:
	@echo Start mosquitto
	brew services start mosquitto

mosquitto_stop:
	@echo Stop mosquitto
	@brew services stop mosquitto

mosquitto_status:
	@echo Status mosquitto
	@(brew services | grep -E '^Name|^mosquitto')

mosquitto_conf_show:
	cat /usr/local/etc/mosquitto/mosquitto.conf | grep -vE '^#|^$$'



ping: ping_gw ping_mqtt ping_proto

ping_gw:
	@echo "--------------------------------"
	@ping -c 1 192.168.100.1

ping_mqtt:
	@echo "--------------------------------"
	@ping -c 1 192.168.100.100

ping_proto:
	@echo "--------------------------------"
	@ping -c 1 192.168.100.200


