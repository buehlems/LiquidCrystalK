//
//Program: Sainsmart_LCD_Button_Readings
//
//Author: Markus Buehler
//
//Requires: -Sainsmart LCD Keypad Shield
//          -Arduino 
//
/*
  This example shows the use of the LiquidCrystalK library
*/

#include <Arduino.h>
#include <LiquidCrystalK.h>


//Define your lcd pins
LiquidCrystalK lcd( 8, 9, 4, 5, 6, 7 );

void setup()
{
 lcd.begin(16,2);        //'16,2' is 16 columns, 2 rows on the display
 pinMode(10, OUTPUT);    // LiquidCrystal light. Unfortunately this pin maybe used by other shields as well
 Serial.begin(115200);
}
 
void loop()
{
  char *keystr="";
  LiquidCrystalK::key_type k;
  k=lcd.get_key();
 
  switch(k){
  case lcd.none  : keystr=" none";   break;
  case lcd.up    : keystr=" up";     break;
  case lcd.down  : keystr=" down";   break;
  case lcd.left  : keystr=" left";   break;
  case lcd.right : keystr=" right";  break;
  case lcd.select: keystr=" select"; break;
  }

  //Display the readings on the keypad
  lcd.print("Key: ");
  lcd.print(k);
  lcd.print(keystr);
  Serial.print("Key:");
  Serial.print(k);
  Serial.println(keystr);

    if(k == lcd.select){
      // lcd.noDisplay(); // display nothing
      digitalWrite(10,LOW); // turn off light
    }else{
      // lcd.display(); // display on
      digitalWrite(10,HIGH); // light on
    }
  lcd.setCursor(0,0);
 
  //To help things work nice and pretty-like =)
  delay(1000);
  lcd.clear();
}
 
