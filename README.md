# Sonoff-WolkAbout-firmware
This is Sonoff WIFI Smart Switch firmware for direct connection to WolkAbout platform. It is developed under Arduino IDE and also with this IDE programming is done.

# Prerequest

### Hardware
 * [Sonoff WIFI Smart Switch](https://www.sonoff.in/index.php?route=product/product&path=62&product_id=75)
 * [Female/Male 'Extension' Jumper Wires](https://www.adafruit.com/product/826)
 * [USB to TTL UART](https://www.aliexpress.com/item/CH340G-5V-USB-to-TTL-UART-Serial-Converter/32524218818.html).

### Software/Firmware
 * Arduino IDE with following:
    * Configured ESP8266 board, [guide](https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/)
    * Installed WolkAbout library. Type WolkAbout in Sketch/Inlude Library/Manage Libraires/
 
# Usage
 * Create device on WolkAbout IoT Platofrm importing `template.json` file
 * Open `sonoff-wolkabout-firmware.ino` in Arduino IDE. This file is located in `sonoff-wolkabout-firmware` folder.
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
 * Open Sonofff case and connect it with USB to TTL converter using jumper wires like it is presented on picture below
 
 ![simg_3625](https://user-images.githubusercontent.com/8199494/51623138-52d79300-1f38-11e9-82d5-138c8e5cc672.jpg)
 
 * Upload fimrware from Arduino IDE. **IMPORTANT** Hold down reset switch on Sonoff(only presented switch on the board) while connecting USB to your PC. This will take Sonoff board into bootloader mode and you will be enable to upload firmware.
 * Create dashboard on WolkAbout platform and add actuator widget

![screenshot from 2019-02-05 07-28-58](https://user-images.githubusercontent.com/8199494/52256667-f00ed000-2917-11e9-8b5d-a2624d5425ea.png)
 
 
 **NOTE** By uploading this custom firmware you will not longer be able to use the *eWeLink app*.
 
 # LED SIGNALS
Green LED presented on Sonoff can generate one of messages:
 * One blink with duration 1s is START(device boot)
 * 4s ON - 4s OFF device can't connect to WIFI
 * Led is permanent ON then Output is ON 
 * Led is permanent OFF then Output is OFF
