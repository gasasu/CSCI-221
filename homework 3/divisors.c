#include <stdio.h>
#include <stdlib.h>

int main(){
int array[] = {2,3,5,7,11};
int size = 5;

int count = 0;

for (int i = 0; i<size;i++){
    for (int j = 0; j<size; j++){
        if (i == j) continue;
        else if (array[i]% array[j] == 0) count+= 1;
    }

}
if (count == 0){
    count += 1;
}

int divisors[count];
int dividents[count];
int w = 0;
for (int i = 0; i<size;i++){
    for (int j = 0; j<size; j++){
        if (i == j) continue;
        else if (array[i]% array[j] == 0) {
          divisors[w] = array[j];
          dividents[w] = array[i];
          w+=1;
        }
    }

}
if (w==0){
    divisors[0] = 0;
    dividents[0] = 0;
}


for (int i = 0; i<count; i++){
    printf("%d - ", divisors[i]);
    printf("%d\n", dividents[i]);
}
return 0;
}
