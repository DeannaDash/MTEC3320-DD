#include <SoftwareSerial.h>
// gives definite value
#define rxPin 3
#define txPin 2

SoftwareSerial bluetooth(rxPin, txPin); // RX, TX

int led = 9;           // the PWM pin the LED is attached to
int button = 6;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {

  int val = analogRead(0);
  int mappedVal = map(val, 0, 1023, 0, 100);
  analogWrite(led, mappedVal);

  Serial.println(val);
  //print out the mapped value 
  bluetooth.write(mappedVal);

  if (val > 800) {
    //    Serial.println(mappedVal);
  }
  if (digitalRead (button) == LOW && val > 800) {
    Serial.println("i work");
    //when button is pressed it will print out 101
    bluetooth.write(101);
  }

  //Serial.println(digitalRead (button));
  delay(30);
}
