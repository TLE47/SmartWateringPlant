# SmartWateringPlant

How to use:

1.  Connect all the components like the image
2.  Connect the Arduino through USB port
3.  In board manager (left-menu), include the libraries in Adafruit_GFX, Adafruit_SSD1306, DHT, pitches.
3.  Paste the source code (WateringControl.cpp) into Arduino IDE
4.  Verify and Upload the code


The moisture sensor will send a signal to the Arduino that will prompt the relay to activate/ deactivate the water pump. The signal will be set if the moisture level drops below a set threshold. When the sensor detects that the moisture is high enough, it will send a signal back to the Arduino and stop the pump. (You can change the moisture detection level on line 79 in the code depending on when you want the pump to water).

