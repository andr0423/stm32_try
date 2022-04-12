


test_send:
	@# terminal 1
	mosquitto_pub -h localhost -t test -m "Hello, Mosquitto"

test_catch:
	@# terminal 2
	mosquitto_sub -h localhost -t test

start:
	@echo Start mosquitto
	brew services start mosquitto

stop:
	@echo Stop mosquitto
	@brew services stop mosquitto

status:
	@echo Status mosquitto
	@(brew services | grep -E '^Name|^mosquitto')


