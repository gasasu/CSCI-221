#include <stdio.h>
#include <stdlib.h>

char* findsubstring(char* string, int string_size, char* substring, int substring_size){
int index = string_size - substring_size + 1;
for (int i = 0; i<index; i++){
    if (string[i] == substring[0]){
        int j = 0;
        for (j = 0; j<substring_size; j++){
            if (string[i+j] != substring[j]) break;
        }
        if (j == substring_size) return string+i;
    }
}

return string+string_size;
}

int main(){
char* string = "Hello";
char* substring = "hello";

char* pointer = findsubstring(string, 5, substring, 2);

printf("%s",pointer);
return 0;
}
