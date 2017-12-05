#include <stdio.h>

typedef struct {
    int a,b;
} numbers;

int main() {

    numbers number[100];

    FILE *fr = fopen("numbers.txt", "r");
    FILE *fw = fopen("result.txt", "w");

    if(fr == NULL){
        printf("File does not exists.");
        return 1;
    }

    int a = 0;
    while(fscanf(fr, "%d %d", &number[a].a, &number[a].b)!= EOF){
        a++;
    }
    for (int i = 0; i < a; ++i) {
        int c = number[i].a;
        int d = number[i].b;
        int obsah = c*d;
        int obvod = 2*(c+d);
        fprintf(fw, "%d %d \n", obsah, obvod);
    }
}