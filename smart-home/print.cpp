// Print "Hello World" to the PC

#include "mbed.h"

Serial pc(USBTX, USBRX);

int main() {
    pc.printf("Hello World\n");
}
