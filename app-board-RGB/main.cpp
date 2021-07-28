#include "mbed.h"

PwmOut r (p23);
PwmOut g (p24);
PwmOut b (p25);

int main()
{
    r.period(0.001);
    while(1) {
        for(float i = 0.0; i < 1.0 ; i += 0.001) {
            float p = 3 * i;
            r = 1.0 - ((p < 1.0) ? 1.0 - p : (p > 2.0) ? p - 2.0 : 0.0);
            g = 1.0 - ((p < 1.0) ? p : (p > 2.0) ? 0.0 : 2.0 - p);
            b = 1.0 - ((p < 1.0) ? 0.0 : (p > 2.0) ? 3.0 - p : p - 1.0);  ;  
            wait (0.01);
        }
    }
}