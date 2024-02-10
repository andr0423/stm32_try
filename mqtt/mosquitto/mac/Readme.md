Use Mosquittto on MacOS
=======================

Use **"brew"** for **MacOS**

 > brew search  mosquitto  
 > brew install mosquitto  

 > brew services status  
 > brew services start mosquitto  
 > brew services stop  mosquitto  

Init agent file here:

 > ~/Library/LaunchAgents/homebrew.mxcl.mosquitto.plist  

Config file here:

 > /usr/local/etc/mosquitto/mosquitto.conf  

Add/set to config

 > max_keepalive 0  
 > listener 1883 0.0.0.0  
 > log_dest file /usr/local/var/mosquitto/mosquitto.log  
 > allow_anonymous true  

