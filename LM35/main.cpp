#include "mbed.h"
#include "TextLCD.h"

AnalogIn LM35(p15);

TextLCD lcd(p21,p22,p23,p24,p25,p26);

int main()
{
 float tempC,tempF,a[10],avg;
 int i;
 
 while(1)
 {
 
 avg=0;
for(i=0;i<10;i++)
{
a[i]=LM35.read();
wait(.02);
}
for(i=0;i<10;i++)
{
avg=avg+(a[i]/10);
}


tempC=(avg*3.685503686*100);
tempF=(9.0*tempC)/5.0 + 32.0;
lcd.locate(0,0);
lcd.printf("  Temperature   ");
lcd.locate(0,1);
lcd.printf("%.2f C %.2f F",tempC,tempF);

wait(.5);      
    }
 }