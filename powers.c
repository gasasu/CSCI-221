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

int main(int argc, char* argv[]){
int base = atoi(argv[1]);
int exponent = atoi(argv[2]);
long c = power(base, exponent);
printf("%ld\n", c);
return 0;
}
