#include <stdio.h>
#include <stdint.h>

unit8_t add(uint8_t num1, uint8_t num2){
uint8_t sign = 0b10000000;
uint8_t exp = 0b01111000;
uint8_t sig = 0b00000111;
uint8_t s1 = num1 & sign;
uint8_t s2 = num2 & sign;
uint8_t exp1 = num1 & exp;
uint8_t sig1 = num1 & sig;
uint8_t exp2 = num2 & exp;
uint8_t sig2 = num2 & sig;

unit8_t res_sig = sig1 + sig2;
return sig || exp1 || res_sig;
}



