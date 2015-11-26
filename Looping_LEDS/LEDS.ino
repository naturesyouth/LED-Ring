#include <WS2812.h>

#define output_pin 3
#define num_leds 24

WS2812 LED(num_leds);
cRGB value; 
byte intensity;
byte sign;
int offset = 0;

void setup() {

  serial.begin(9600);
  LED.setOutput(output_pin);

  intensity = 255;
  sign = 1;

}

void loop() {

  while(!Serial.available());

  value.r =(INT)Serial.read();
  value.g 
 
  set_all_LED(139,45,128);
  
   if(offset<num_leds){
    offset++;
  }else{
    offset=0;
  }

  }

void set_all_LED(int r, int b, int g){
  for (int i = 0; i < num_leds; i++) {
    value.r = r;
    value.g = g;
    value.b = b;
    LED.set_crgb_at(i, value);
  }
    LED.sync();
}

