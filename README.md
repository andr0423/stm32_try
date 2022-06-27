VKR 2022 DEMYKIN
================


stm32_try
---------
stm32 learn for diploma VKR 2022


### Create IoT prototype

Tst002 - ... old  

Tst004 - code for stm32f746gz-nucleo, current  

mqtt - mqtt-broker, client and sqlite db  


### MQTT

https://mosquitto.org/download/


### LWIP

https://www.nongnu.org/lwip/2_1_x/index.html


Connection
----------

[bme280](https://www.bosch-sensortec.com/media/boschsensortec/downloads/datasheets/bst-bme280-ds002.pdf)  

[oled 0.96 128x64](http://www.lcdwiki.com/res/MSP096X/SPEC_LED096B_V1.0.pdf)  

```
  +-----+------+-------++--------+
  | bme | oled | STM32 || color  |
  +-----+------+-------++--------+
  | gnd | GND  |   -   || brown  |
  | vcc | VCC  |   +   || red    |
  +     +      +-------++--------+
  |     | D0   |  PF7  || BLUE   |
  |     | D1   |  PF9  || PURPLE |
  |     | RES  |  PG0  || BLACK  |
  |     | DC   |  PG1  || WHITE  |
  |     | CS   |  PE3  || GREY   |
  +     +------+-------++--------+
  | scl |      |  PF1  || yello  |
  | sda |      |  PF0  || orange |
  | csb |      |   +   ||        |
  | sdo |      |       ||        |
  +-----+------+-------++--------+
```

Troubles
--------

 - sprint not show float  
   The float formatting support is not enabled, check your MCU Settings from “Project Properties > C/C++ Build > Settings > Tool Settings”, or add manually “-u _printf_float ”In linker flags.  
   (https://programmersought.com/article/90293972367/)

 - some troubles with ETH  
   On case start without eth-connection, after attach cords eth connetction not configured, need "reset"  


Good look
---------
[more photos and videos of the prototypes](https://disk.yandex.ru/d/yaAZ7_-PIcD83w)

![MqttExplorer](./MqttExplorer2.png)

![PrototypeCharts](./PrototypeCharts2.png)

