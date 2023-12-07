#include <stdio.h>
#include <math.h>


void main(){
    int decimal = 18;
    int binary = 0;
    int place = 1;
    while (decimal){
        binary = binary + place * (decimal % 2);
        place *= 10;
        decimal /= 2;
    }
    printf("%d", binary);
}
