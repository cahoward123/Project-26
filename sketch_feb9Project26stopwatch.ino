// Project 26 – Digital Stopwatch 
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);   //Select pins used
#define btnSELECT 4
#define btnNONE 5
long offset=0;

int lcd_key =0;
int adc_key_in =0;

int read_LCD_buttons(){
  adc_key_in = analogRead(0);

  if (adc_key_in < 850 && adc_key_in > 651 ) return btnSELECT;

  else return btnNONE;

}

void setup()
{
  lcd.begin (16,2);  //Starts the library
  lcd.setCursor (0,1);
  lcd.print ("Sec:    ms:");
  lcd.setCursor (0,0);
  lcd.print ("Hr:    Min:");
  
}


void loop()
{
  long m=millis()-offset;
int hours = (m/3600000) % 100;
int minutes = (m/60000) % 60;
int seconds = (m/1000) % 60;
int ms = (m /10) % 100;

  lcd.setCursor (11, 0);
  lcd.print (minutes);   //Displays Minutes

  lcd.setCursor (11, 1);
  lcd.print (ms);        //Displays Milliseconds

  lcd.setCursor (4, 1);
  lcd.print (seconds);   //Displays Seconds

  lcd.setCursor (3, 0);           
  lcd.print (hours);     //Displays Hours

  lcd_key = read_LCD_buttons();   //read buttons
  switch (lcd_key){
    case btnSELECT:{
      delay(15000);
      offset+=15000;
      break;
    }
  }
}
    
