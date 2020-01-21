#include <LiquidCrystalK.h>
#include <Arduino.h>

/****f* 
  *  NAME
  *    LiquidCrystalK -- 
  *  SYNOPSIS
  *   LiquidCrystalK(...)
  *  FUNCTION
  *    all functions just call the parent constructor and set pin A0 to input
  *  INPUTS
  *    ---
  *  RESULT
  *    ---
   ******
*/


LiquidCrystalK::LiquidCrystalK(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
  :LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)
{
  initK();
}

LiquidCrystalK::LiquidCrystalK(uint8_t rs, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
			     uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
  :LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7)
{
  initK();
}

LiquidCrystalK::LiquidCrystalK(uint8_t rs, uint8_t rw, uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
  :LiquidCrystal(rs, rw, enable, d0, d1, d2, d3)
{
  initK();
}

LiquidCrystalK::LiquidCrystalK(uint8_t rs,  uint8_t enable,
			     uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3)
  :LiquidCrystal(rs,  enable, d0, d1, d2, d3)
{
  initK();
}

/****f* 
  *  NAME
  *    initK -- 
  *  SYNOPSIS
  *   initK();
  *  FUNCTION
  *    set pin A0 to input
  *  INPUTS
  *    ---
  *  RESULT
  *    ---
   ******
*/

LiquidCrystalK::initK(){
  pinMode(A0, INPUT);     //pin 'A0' is your keypad's input.
  Serial.println("limit");
}

LiquidCrystalK::key_type LiquidCrystalK::get_key(){
  int kin = analogRead(A0);
  byte k;
  if(kin<=LIMIT_RIGHT)
    k=right;
  else if (kin <= LIMIT_UP)
    k=up;
  else if (kin <= LIMIT_DOWN)
    k=down;
  else if (kin <= LIMIT_LEFT)
    k=left;
  else if (kin <= LIMIT_SELECT)
    k=select;
  else 
    k=none;

  return(k);
}
