
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int prevMappedVal = -1;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {

  // get a reading of the potentiometer
  int potVal = analogRead(5);
  // but we only want 5 values or so...
  int mappedVal = map(potVal, 0, 1023, 0, 5); // 0 and how ever many hints we have

  // only if the value has changed...
  if (prevMappedVal != mappedVal) {

    if (mappedVal == 0) {
      backStory("HELLO", 2);
      delay(3000);
      backStory("TURN KNOB SLOWLY", 1);
      delay(3000);
      backStory("TO REVEAL HINTS FOR EACH GAME", 2);
      delay(3000);
    }

    if (mappedVal == 1) {
     backStory("THIS IS THE 1ST HINT", 1);//patch bay
      delay(2000);
      backStory("MATCH SOUND TO LIGHT", 1);
      delay(2000);
      backStory("CONNECT WIRES FROM TOP 2 BOTTOM", 2);
    }

     if (mappedVal == 2) {
      backStory("THIS IS THE 2ND HINT", 2);//phone
      delay(2000);
     backStory("10 GREENS TO PASS",2);
      delay(2000);
      backStory("FIND THE EMAIL",2);
    }

     if (mappedVal == 3) {
     backStory("THIS IS THE 3RD HINT", 2);//simon says
      delay(2000);
      backStory("THIS IS A SIMON STYLE GAME", 2);
      delay(2000);
     backStory("FOLLOW THE SEQUENCE", 2);
    }

    
    prevMappedVal = mappedVal;
  }
}

void backStory(String _test, int _lines) {
  lcd.clear();
  for (int i = 0; i <= _lines; i++) {
    Serial.println(i);
    String top = _test.substring((16 * i) * 2, 16 + ((16 * i) * 2));

    lcd.setCursor(0, 0);
    lcd.print(top);
    lcd.setCursor(0, 1);
    String bottom = _test.substring((16 + ((16 * i) * 2)), 32 + (16 + ((16 * i) * 2)));
    lcd.print(bottom);

  }

}


