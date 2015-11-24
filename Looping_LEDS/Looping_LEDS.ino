#include <WS2812.h>

#define output_pin 3
#define num_leds 24

WS2812 LED(num_leds);
cRGB value; 
byte intensity;
byte sign;
int offset = 0;

void setup() {
  LED.setOutput(output_pin);

  LED.setColorOrderRGB();

  intensity = 255;
  sign = 1;

}

void loop() {
  if(offset<24){
    offset++;
  }else{
    offset=0;
  }
  for (int i = 0; i < num_leds; i++) {
    value.b = 0;
    value.g = 0;
    value.r = 0; // RGB Value -> Green Only
    LED.set_crgb_at(i+offset, value);
    LED.sync();
    delay(50);
  }
   
  }

