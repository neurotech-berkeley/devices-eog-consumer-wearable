#include "PluggableUSBHID.h"
#include "USBMouse.h"
// #include "USBKeyboard.h"
// #include "Mouse.h"
// #include "Keyboard.h"

// USBKeyboard keyboard;
USBMouse mouse;

void setup() {
  Serial.begin(9600);

  delay(3000);
}

void loop() {
  Serial.println("moving");
  // keyboard.printf(" ");
  mouse.move(0, 40);
  delay(500);
  mouse.move(40, 0);
  delay(500);
  mouse.move(0, -40);
  delay(500);
  mouse.move(-40, 0);
  delay(500);
}
