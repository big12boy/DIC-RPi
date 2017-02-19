#include <stdio.h>
#include <wiringPi.h>
int leds[] = {18,23,24,25}, btns[] = {27, 17};
int ledc = 4, btnc = 1, pause = 100;

int i = 0, time = 0, state = 0;
void setup(){
  wiringPiSetupGpio() ;
  for(i=0 ; i<ledc ; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  for(i=0 ; i<btnc ; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

int main (void)
{
  printf ("Timer \n") ;
  setup();
  i=0;

  while(1)
  {
    if(state == 1){
      time++;
      for (i = 0; i < ledc; ++i) {
        digitalWrite(leds[i], time & (1 << i) ? 1 : 0);
      }
      delay(pause);
    }

    if(digitalRead(btns[0]) == LOW){
      if(state == 0)state = 1;
      else{
        state = 0;
        delay(500);
      }
    }
    if(digitalRead(btns[1]) == LOW){
      printf("Time %dms\n",time*pause);
      time = 0;
      for (i = 0; i < ledc; ++i) {
        digitalWrite(leds[i], time & (1 << i) ? 1 : 0);
      }
      delay(500);
    }
  }
  return 0 ;
}
