# Author
- ROSA FREIRE SOUSA Camilla

# How to Run
To run the code, follow these steps:
1. Configure the Arduino IDE by going to `File > Preferences > Additional boards manager URLs` and add the following URL: `https://dl.espressif.com/dl/package_esp32_index.json`.
2. Install the ESP32 board support in the Arduino IDE.
3. Select the ESP32 Wrover Module as your target board in the IDE settings.
4. Connect the board to the computer and click on "Upload" in the Arduino IDE interface.
5. Monitor the code output through the Serial Monitor.

# Developer's Guide
To execute the code, update the WiFi network name and password. This code utilizes a mocked JSON file to simulate data extraction from an API, but also provides a function to directly extract data from the API (see instructions in the comments for adaptations). Additionally, all sources of information used to assist in the construction of the code are properly cited in the comments.

# References
In addition to classroom examples and the code from the TB3 Final Project, this project was built based on information obtained from the following resources:
- Official Arduino documentation on programming functions: [Arduino Programming Functions](https://docs.arduino.cc/learn/programming/functions/)
- Official Arduino JSON documentation for DynamicJsonDocument: [Arduino JSON DynamicJsonDocument](https://arduinojson.org/v6/api/dynamicjsondocument/)
- Official Arduino reference for generating random numbers: [Arduino Random Numbers](https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)
- Arduino Forum discussion on printing elements of a string array: [Arduino Forum - Printing Elements of a String Array](https://forum.arduino.cc/t/trying-to-print-elements-of-a-string-array/393090/3)
- Example usage of the Arduino Fetch library for ESP32: [Arduino Fetch Example](https://github.com/instanceofMA/arduino-fetch/blob/main/examples/esp32/sync/get/get.ino)

