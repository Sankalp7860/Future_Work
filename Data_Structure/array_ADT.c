#include <stdio.h>
#include<stdlib.h>
struct myArray
{
    int totalSize;
    int usedSize;
    int * ptr;
};
void createArray(struct myArray * a,int tsize,int usize){
    a->totalSize=tsize;
    a->usedSize=usize;
    a->ptr=(int *)malloc(tsize*sizeof(int));
}
void showArray(struct myArray * a){
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
    
}
void setVal(struct myArray * a){
    int n;
    for (int i = 0; i < a->usedSize; i++)
    {
        printf("Enter Element at index %d: ",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
    

}
int main()
{
    struct myArray marks;
    createArray(&marks,100,4);
    printf("We are running setval now\n");
    setVal(&marks);
    printf("We are running showArray now\n");
    showArray(&marks);
    return 0;
}