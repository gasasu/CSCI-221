#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t decaying_sum(uint16_t* values, uint16_t length, uint16_t decay){
if (length <= 0){
return 0;
}
uint32_t rest = decaying_sum(&values[1], length-1, decay);
uint32_t decayed = rest / decay;
return values[0] + decayed;
}


uint32_t decaying_sum2(uint16_t* values, uint16_t length, uint16_t decay, uint32_t rest){
  if (length < 1)
        return rest;

    uint32_t decayed = rest / decay;
    rest = decayed + values[length -1];
    return decaying_sum2(values, length-1, decay, rest);
     }

int main(){
    uint16_t values[] = {12,12,13,14,15};
    int length = 5;
    int decayed = 2;
    uint32_t c = decaying_sum(values, length, decayed);
    uint32_t d = decaying_sum2(values, length, decayed, 0);
    printf("%d\n",c);
    printf("%d\n", d);
     return 0;}

