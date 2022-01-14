#include <M5Stack.h>
#include "M5Servo.h"

int buttonState = 0;
M5Servo servo;

void setText(String txt) {
  M5.Lcd.clear(BLACK);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(65, 90);
  M5.Lcd.println(txt);
}

void setup() {
  M5.begin();
  M5.Power.begin();
  delay(500);
  M5.Lcd.setTextColor(YELLOW);
  setText("Walking Off");
  servo.attach(5);
}

void loop() {
  M5.update();

  if(M5.BtnB.wasPressed()){
    if (buttonState == 0) {
      buttonState = 1;
      setText("Walking On");
    } else {
      buttonState = 0;
      setText("Walking Off");
    }
  }

  if (buttonState == 1) {
    for (int i = -90; i <= 90; i+=10){
      servo.write(i);
      uint8_t v = map(i,-90,90,0,100);
      delay(15);
    }
  
    for (int i = 90; i >= -90; i-=10){
      servo.write(i);
      uint8_t v = map(i,-90,90,0,100);
      delay(15);
    }
  
    delay(100);
  }
  
}
