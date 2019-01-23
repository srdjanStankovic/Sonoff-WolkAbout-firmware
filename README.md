# Sonoff-WolkAbout
This is Sonoff WIFI Smart Switch firmware for direct connection to WolkAbout platform.

# Prerequest

### Hardware
 * [Sonoff WIFI Smart Switch](https://www.sonoff.in/index.php?route=product/product&path=62&product_id=75)
 * [Female/Male 'Extension' Jumper Wires](https://www.adafruit.com/product/826)
 * [USB to TTL UART](https://www.aliexpress.com/item/CH340G-5V-USB-to-TTL-UART-Serial-Converter/32524218818.html).

### Software/Firmware
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
 * Open Sonofff case and connect it with USB to TTL converter like it is presented on picture below
 
 ![simg_3625](https://user-images.githubusercontent.com/8199494/51623138-52d79300-1f38-11e9-82d5-138c8e5cc672.jpg)
 
 * Upload fimrware from Arduino IDE. **IMPORTANT** Hold down reset switch on Sonoff(only presented switch on the board) while connecting USB to your PC. This will take Sonoff board into bootloader mode and you will be enable to upload firmware.
 * Create dashboard on WolkAbout platform and add actuator widget

 <img width="220" alt="capture" src="https://user-images.githubusercontent.com/8199494/51622123-3dfa0000-1f36-11e9-8f61-3270fa1c9c8b.PNG">
 
 
 **NOTE** By uploading this custom firmware you will not longer be able to use the eWeLink app.
