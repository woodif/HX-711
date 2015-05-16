#include "HX711.h"
#include <SoftwareSerial.h>
#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0
//LiquidCrystal_I2C lcd(0x27, 16, 2);

HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library
//SoftwareSerial mySerial(10, 9); // RX, TX

  static float buf ;
  static float raw ;
void setup() {
 Serial.begin(115200);
  Serial.println("HX711 Demo");
  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());			// print a raw reading from the ADC
///////////////////////////////////////////////////////////////
//        lcd.begin();
//	lcd.print("Term Project");
//        lcd.setCursor(0, 1);
//        lcd.print("Weight Sensor");
//        delay(3000);
// Serial.begin(57600);
 // mySerial.begin(9600);
}

void loop() {

  raw = (scale.read() - 8625100.00f) / 41850.11091f;
  raw -= 26.35;
  raw *=  2.049335863f;
//  buf = buf + 0.9f*(raw - buf);
////  buf -= 0 ;
//  buf *= -1 ;
  Serial.print("real reading:\t");
  Serial.print(scale.read());
  Serial.print("\t| one reading:\t");
  Serial.println(raw);
//  Serial.print("\t| average:\t");
//  Serial.println(buf,1);
}
///////////////////////////////////////////////////////
// if (buf >= 1){
////  lcd.begin();
////  lcd.print("Weight Unit Kg.");
////  lcd.setCursor(0, 1);
////  lcd.print(buf,1);
//delay(10);
// }
// else {
////  lcd.begin();
////  lcd.print("Weight Sensor");
////  lcd.setCursor(0, 1);
////  lcd.print("By Elec. RMUTL");
// }
//
////if (mySerial.available())
////    Serial.write(mySerial.read());
////  if (Serial.available())
//    mySerial.print(buf,1);
//delay(100);
//}
