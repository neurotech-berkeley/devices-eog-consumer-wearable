#include "PluggableUSBHID.h"
#include "USBMouse.h"
#include <time.h>

int screen_width = 1920;
int screen_height = 1080;
float scale_x = 1920/1023;
float scale_y = 1080/1023;

int GAZE_THRESHOLD = 500; //500 ms
int offset_x = 0;
int offset_y = 0;
int dot_r = 20;

/**
int min_x = offset_x + 50;
int min_y = offset_y + 50;
int max_x = screen_width - 50;
int max_y = screen_height - 50;


**/

int last_x = 0;
int last_y = 0;
int curr_x = 0;
int curr_y = 0;

bool move = true;
time_t seconds = time(NULL);
int last_move_time = seconds;
int now = 0;
int time_diff = 0;

USBMouse mouse;

void window_switch(int eye_x, int eye_y) {
//  mouse.move(1920, 1080);
//  mouse.move(-(1920 - (2 * eye_x)), -(1080 - eye_y));
  //mouse.move(eye_x, eye_y)
  mouse.move(curr_x - last_x, curr_y - last_y);
  Serial.print(scale_x * eye_x);
  Serial.print(" ");
  Serial.print(scale_y * eye_y);
  Serial.print(" ");
  if(eye_y * scale_y < 540) {
    if(eye_x * scale_x > 960) {
      Serial.print("1");
    }
    else Serial.print("2");
  }
  else if(eye_x * scale_x < 960) {
    Serial.print("3");
  }
  else Serial.print("4");

  Serial.println(" ");

  //mouse.click(MOUSE_LEFT);
}

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  curr_x = scale_x * analogRead(A0);
  curr_y = scale_y * analogRead(A1);
  
  //printing so we can make csv easily
  Serial.print(millis());
  Serial.print(" ");
  Serial.print(curr_x);
  Serial.print(" ");
  Serial.println(curr_y);

  //if(curr_x > 800 || curr_x < 200 || curr_y > 800 || curr_y < 200) {
  //  window_switch(curr_x, curr_y);
  //  delay(300);
  //}
  window_switch(curr_x, curr_y);
  last_x = curr_x;
  last_y = curr_y;

  //move = last_x != curr_x || last_y != curr_y;
  
  /*
  if(move) {
    last_move_time = time(NULL);
  }
  else {
    now = time(NULL);
    time_diff = now - last_move_time;
    if(time_diff >= GAZE_THRESHOLD) {
      window_switch(curr_x, curr_y);
    }
  }
  */
  delay(1000);
}

