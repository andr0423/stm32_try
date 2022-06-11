VKR 2022 DEMYKIN
================


# stm32_try
stm32 learn for diploma VKR 2022


## Create IoT prototype

Tst002 - codece for stm32f767zi-nucleo  

mqtt - mqtt-broker, client and sqlite db  


## MQTT

https://mosquitto.org/download/


## LWIP

https://www.nongnu.org/lwip/2_1_x/index.html


Connection
------------


+-----+------+-----+--------+  
| bmp | OLED |  mk | color  |  
+-----+------+-----+--------+  
| gnd | GND  |  -  | brown  |  
| vcc | VCC  |  +  | red    |  
+     +      +-----+--------+  
|     | D0   | PF7 | BLUE   |
|     | D1   | PF9 | PURPLE |
|     | RES  | PG0 | BLACK  |
|     | DC   | PG1 | WHITE  |
|     | CS   | PE3 | GREY   |
+     +------+-----+--------+  
| scl |      | PF1 | yello  |
| sda |      | PF0 | orange |
| csb |      |  +  |        |
| sdo |      |     |        |  
+-----+------+-----+--------+  


Troubles
--------

## sprint not show float

The float formatting support is not enabled, check your MCU Settings from “Project Properties> C/C++ Build> Settings> Tool Settings”, or add manually “-u _printf_float ”In linker flags.

https://programmersought.com/article/90293972367/

