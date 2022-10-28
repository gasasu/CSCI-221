#include <stdio.h>
#include <stdlib.h>
struct point2d{
int x;
int y;
};
// argc should be an int
// added [] to argv
int main(int argc, char* argv[]) {
int m = atoi(argv[1]);
struct point2d *p = malloc(sizeof(struct point2d));
p->x = atoi(argv[2]);
p->y = atoi(argv[3]);
struct point2d *z = malloc(sizeof(struct point2d));
z->x = 0;
// should initialize z->y
z->y = 0;
z->y = z->y - (m * p->x);
printf("x coord: %d\n", p->x);
printf("y coord: %d\n", p->y);
printf("The y coord of z:  %d\n", z->y);
// free our pointers
free(p);
free(z);
return 0;
}
