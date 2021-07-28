#include "mbed.h"
 
Serial pc(PTE22, PTE23);
 
int main() {
   while(1){
    pc.printf("Hello World\n");
}}