#include "mbed.h"
#include "TextLCD.h"

void settemp();
void tempmenu();
float temp_cal();
AnalogIn temp_sen(A0);
TextLCD lcd(PTC7,PTC0,PTC3,PTC4,PTC5,PTC6);
InterruptIn button(D0);
DigitalIn push2(D1);
DigitalIn push1(D2);
DigitalIn push3(D3);
PwmOut mypwm(A5);
//DigitalOut myled(A);

int temp = 25;
float tempC,tempF,a[10],avg;

int main() { 
  tempmenu();
}
        
void settemp(){
  lcd.cls();
  lcd.printf("enter temp:  %d",temp);
  wait(0.2);
  while(1){
    
    // temp up
    if(push2 == 0 && push1 == 1){
      temp++;
      lcd.cls();
      lcd.printf("enter temp:  %d",temp);
      wait(0.2);
    }
    
    // temp down
    if(push1 == 0 && push2 == 1){
      temp--;
      lcd.cls();
      lcd.printf("enter temp:  %d",temp);
      wait(0.2);
    }
    
    // confirm
    if(push3 == 0){
//      tempmenu();
      break;
    }
    
  }
}

void tempmenu() {
  while(1){
    lcd.cls();
    // display menu
    mypwm.period_ms(10);
    lcd.printf("T:%.2f \n",temp_cal());
    lcd.printf("1 to mod temp");
    wait(0.2);
    if(temp_cal()<temp){
        wait(0.5);
        mypwm.pulsewidth_ms(8);
        }
    if(temp_cal()>=temp){
        mypwm.pulsewidth_ms(2);
        }
        
        //else{
        //myled =0;}
    // interrupt
    button.fall(&settemp);
    lcd.printf("end");
  }
}

float temp_cal(){
    avg=0;
    int i;
for(i=0;i<10;i++)
{
a[i]=temp_sen.read();
wait(.05);
}
for(i=0;i<10;i++)
{
avg=avg+(a[i]/10);
}


tempC=(avg*3.685503686*100);
tempF=(9.0*tempC)/5.0 + 32.0;
return tempC;
    }


