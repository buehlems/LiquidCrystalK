# LiquidCrystalK
Extends LiquidCrystal by a get_key function  

The LCD1602 uses the analog pin A0 to indicate pressed keys.  
I used the values from my LCD to determine the values for the different keys. (RIGHT, UP, ...). I set the limits in the middle between two values. So the routing should be robust enough for most modules.  
If not, just adjust the values with your measurements.  

