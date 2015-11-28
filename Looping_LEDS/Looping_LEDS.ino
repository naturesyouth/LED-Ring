#include <WS2812.h>

#define output_pin 3
#define num_leds 24

WS2812 LED(num_leds);
cRGB value; 
byte intensity[4];
byte sign;
int offset = 0;

void setup() {

  Serial.begin(9600);
  LED.setOutput(output_pin);
  sign = 1;
  Serial.println("starting");
  set_all_LED(32,0,0);
  delay(100);
    set_all_LED(0,32,0);
  delay(100);
    set_all_LED(0,0,32);
  delay(100);
    set_all_LED(0,0,0);
  delay(10);

}

void loop() {


  byte serialred = Serial.read();
  Serial.println(serialred);
   while(!Serial.available());
  byte serialgreen = Serial.read();
   while(!Serial.available());
  Serial.println(serialgreen);
  byte serialblue = Serial.read();
  Serial.println(serialblue);


  Serial.println("setting leds");
  set_all_LED(serialred,serialgreen,serialblue);
  
   if(offset<num_leds){
    offset++;
  }else{
    offset=0;
  }
delay(10);
  }
  
  void set_all_LED(byte r, byte b, byte g){
  for (int i = 0; i < num_leds; i++) {
    value.r = r;
    value.g = g;
    value.b = b;
    LED.set_crgb_at(i, value);
  }
    LED.sync();
}

