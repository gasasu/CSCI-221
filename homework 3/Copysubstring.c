#include <stdio.h>
#include <stdlib.h>

char* copysubstring(char* string,char* substring, int start, int end){

int i = 0;
for (int j = start; j < end; j++){
    substring[i] = string[j];
    i++;
}

substring[i] = '\0';
return substring;

}

int main(){
char* string = "Hello";
int start = 1;
int end = 5;
int length = end - start + 1;
char substring[length];
char* copy = copysubstring(string, substring, start, end);
printf("%s\n", copy);
return 0;
}
