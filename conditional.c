#include <stdio.h>

int main(){\
int x = 0;
int y = 4;
int z = 5;
int c = !!x;
int d = ~c+1;


return (d&y) | (~d&z);
}
