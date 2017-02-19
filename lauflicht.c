#include <stdio.h>
#include <wiringPi.h>

int leds[] = {18,23,24,25}, btns[] = {22,17};
int ledc = 4, btnc = 2, pause = 200;


int i = 0;

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
  printf ("IO \n") ;
  setup();
  i=0;

  while(1)
  {
    if(digitalRead(btns[0]) == LOW){
      digitalWrite(leds[i], LOW);
      i--;
      if(i < 0)i = ledc - 1;
      digitalWrite(leds[i], HIGH);
      delay(pause);
    }
    else if(digitalRead(btns[1]) == LOW){
      digitalWrite(leds[i], LOW);
      i++;
      if(i >= ledc)i=0;
      digitalWrite(leds[i], HIGH);
      delay(pause);
    }
  }
  return 0 ;
}
