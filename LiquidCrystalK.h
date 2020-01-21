#ifndef LIQUIDCRYSTALK_H
#define LIQUIDCRYSTALK_H

#include <LiquidCrystal.h>

class LiquidCrystalK : public LiquidCrystal{
 public:

  LiquidCrystalK(uint8_t rs, uint8_t enable,
		 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
  LiquidCrystalK(uint8_t rs, uint8_t rw, uint8_t enable,
		 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
		 uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
  LiquidCrystalK(uint8_t rs, uint8_t rw, uint8_t enable,
		 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
  LiquidCrystalK(uint8_t rs, uint8_t enable,
		 uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);

  enum key_type { none, up, down, left, right, select };
  key_type get_key();
  // char *keyStr(key_type k); 

 private:
  // these are the expects. 
  // my measurements
  const static int RIGHT =   0;
  const static int UP    = 142;
  const static int DOWN  = 342;
  const static int LEFT  = 510;
  const static int SELECT= 730;
  const static int NONE  =1024;

  const static int LIMIT_RIGHT  = (RIGHT+UP)/2;     // less than is right
  const static int LIMIT_UP     = (UP+DOWN)/2;      // less than is up
  const static int LIMIT_DOWN   = (DOWN+LEFT)/2;    // less than is down
  const static int LIMIT_LEFT   = (LEFT+SELECT)/2;  // less than is left
  const static int LIMIT_SELECT = (SELECT+NONE)/2; // less than is select, anything else is none
  initK(); 
};
#endif
