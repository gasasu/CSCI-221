#include <stdio.h>

int main(){
int x = -5;

return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}
