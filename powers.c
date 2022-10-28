#include <stdio.h>
#include <stdlib.h>

int power(int base, int exponent) {
if (exponent==0) return 0;
long result = 1;
while (exponent > 1) {
if (exponent % 2 == 1) {
result = base * result;
}
base = base * base;
exponent = exponent / 2;
}
return result * base;
}

int main(){
long c = power(2,30);
printf("%d", c);
return 0;
}
