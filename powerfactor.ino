/*
Adafruit Arduino - Lesson 12. Light and Temperature
*/
 
#include <LiquidCrystal.h>
#include <avr/io.h>
#include <util/delay.h>
 
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 
void setup() 
{
  lcd.begin(16, 2);
}
int main(void)
{

  DDRC &= ~(1 << DDC4);
  DDRC &= ~(1 << DDC5);
  
TCNT1L=0x00;
TCNT1H=0x00;
do{
if(PINC & (1<<PC4))
  {TCCR1B|=(1<<CS10);
        TCCR1B|=(1<<CS11);}
   if((~(PINC & (1<<PC4)) && (TCCR1B=0xFF )))
  {
    TCCR1B=0x00;
    TCCR1B |=(0<<CS10);
                TCCR1B|=(0<<CS11);
    break;
  }
} 
while(1);

TCNT1L=0x00;
TCNT1H=0x00;
do 
{
if((PINC & (1<<PC4)))
  {
{TCCR1B |=(1<<CS10);
TCCR1B|=(1<<CS11);}
    
    if((PINC & (1<<PC5)))
    {
TCCR1B=0x00;
TCCR1B |= (0<<CS10);
TCCR1B|=(0<<CS11);
  break;

    }
  }   
  } 
 while (1);
  //         ----------------
 
  int pulses=TCNT1;
  float rad=0.00031416*4*(2500-pulses);
  double pf=cos(rad);
  pf=abs(pf  );
 lcd.print("PF");
  lcd.setCursor(6, 0);
  lcd.print(pf);

    if(pf<0.90)
    PORTD=0x01;
    _delay_ms(500);

 /* // Display Light on second row
  int lightReading = analogRead(lightPin);
  lcd.setCursor(0, 1);
  //         ----------------
  lcd.print("Light           ");  
  lcd.setCursor(6, 1);
  lcd.print(lightReading);
  delay(500);*/
 
}
