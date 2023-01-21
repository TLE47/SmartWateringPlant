The Source Code:
// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>;
#include "pitches.h"


// Constants
// DHT - Humidity Temperature Sensor
#define waterPump A3        //3.3V waterPump
#define DHTPIN 2            
#define DHTTYPE DHT21       //DHT 21  (AM2301)
DHT dht(DHTPIN, DHTTYPE);   //Initialize DHT sensor for normal 16mhz Arduino
#define OLED_RESET 4        //Oled Screen Reset Pin
Adafruit_SSD1306 display(OLED_RESET); 


//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value
int moistureRaw; //Stores raw moisture value
int moistureReal;//Stores converted moisture value
String tmp;     // Temporary variable


void setup() {
  Serial.begin(9600);
  dht.begin();
  //Initialize display by providing the display type and its I2C address.
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);


  //Set the text size and color.
  display.setTextSize(2);
  display.setTextColor(WHITE);
  pinMode(waterPump, OUTPUT);
  pinMode(9, OUTPUT); // passive Buzzer
}


void loop() {
  // Read data and store it to variables
  hum = dht.readHumidity();
  temp= dht.readTemperature();
  moistureRaw = analogRead(A0);
  moistureReal = map(moistureRaw, 0, 400, 0, 100);


  // Clear previous image + Set to display Moisture
  display.clearDisplay();
  display.setCursor(0, 0);
  tmp = String(moistureReal);
  display.print("Moisture: " + tmp + "%");
  display.display();
  delay(1500);


    // Clear previous image + Set to display Humidity
  display.clearDisplay();
  display.setCursor(0, 1);
  tmp = String(hum);
  display.print("Humidity: " + tmp + "%");
  display.display();
  delay(1500);


    // Clear previous image + Set to display Temperature 
  display.clearDisplay();
  display.setCursor(0, 1);
  tmp = String(temp);
  display.print("Temperature: " + tmp + "C");
  display.display();
  delay(1500);


  // Print variables to serial monitor
  Serial.print("Moisture level: ");
  Serial.println(moistureReal);
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%,  Temperature: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(500);// Delay 0.5s


  // Pumping water if moisture level is low
  if (moistureReal > 90) {
    display.clearDisplay();
    display.display();
    digitalWrite(waterPump, HIGH);


  }
  else {
    display.clearDisplay();
    display.display();
    digitalWrite(waterPump, LOW);


  }


  delay(2000); //Delay 2s
}
