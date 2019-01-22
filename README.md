# Sonoff-WolkAbout
This is Sonoff WIFI Smart Switch firmware for direct connection to WolkAbout platform.

# Prerequest
 * Intalled ESP8266 board in Arduino IDE, [guide](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)
 * WolkAbout library. Type WolkAbout in Sketch/Inlude Library/Manage Libraires/
 
# Usage
 * Create device on WolkAbout IoT Platofrm importing `template.json` file
 * Insert your wifi credentials here
 ```
 const char* ssid = "wifi_ssid";
 const char* wifi_pass = "wifi_password";
 ```
 * Insert key & password given on WolkAbout platform here:
 ```
 const char *device_key = "some_key";
 const char *device_password = "some_password";
 ```
 * Open Sonofff and connect it with USB to TTL converter like it is presented on picturw below
 
 [TODO](insert picture)
 
 * Upload fimrware from Arduino IDE
 * Create dashboard on WolkAbout platform and add actuator widget

 [TODO](insert picture)