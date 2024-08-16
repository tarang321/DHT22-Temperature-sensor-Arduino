
#include <DHT.h>
#include <Wire.h> 
//#include <lcd.h>
#include <LiquidCrystal_I2C.h>

//Constants
#define DHTPIN 4 // what pin the DHT22 Data is connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

//Variables
int chk;
float hum;  //Stores humidity value
float temp; //Stores temperature value
float tempF;
void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("Arduino");        // print message at (0, 0)
  lcd.setCursor(2, 1);         // move cursor to   (2, 1)
  lcd.print("Booting Up"); // print message at (2, 1)
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16,2);
  lcd.init(); // initialize the lcd
  lcd.backlight();
}

void loop()
{
  
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  tempF = ((temp * 1.8) + 32);
  //Print temp and humidity values to serial monitor
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  //Print temp and humidity values to LCD
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temp: "); 
  lcd.print(tempF);
  lcd.println("Fahrenheit");
  delay(2000); //Delay 2 sec between temperature/humidity check


}
