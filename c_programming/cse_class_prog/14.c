#include <stdio.h>

int main() {
    int a[5];
    //printf("%d %d\n", a, &a);
    //printf("%d %d\n", main, &main);

    int *b = a;


    for (int i = 0; i < 5; i++) {
        //scanf("%d", a + i);
        //scanf("%d", &a[i]);
        //scanf("%d", b + i);
        //scanf("%d", &b[i]);
        scanf("%d", &i[a]);
    }


    int sum = 0;
    for (int i = 0; i < 5; i++)
        //sum += a[i];
        sum += i[a];
        sum += b[i];
        sum += *(a + i);
        sum += *(b + i);

    printf("%d\n", sum);
    return 0;
}
