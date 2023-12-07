#include<iostream>
using namespace std;
int medOfMed(int * arr,int size){
if (size<=5)
{
    sort(arr,arr+size);
    return arr[size/2];
}

int **arr1=new int*[(size/5)+1];
int l=0;
for (; l < size-(size%5);l=l+5)
{
    sort(arr+l,arr+5+l);
    
}
sort(arr+l,arr+size);
int j=0,k=0;
for (int i = 0; i < (size/5)+1; i++)
{
    int * temp=new int[5];
    while (j!=5)
    {
        temp[j]=arr[k];
        j++;
        k++;
    }
    arr1[i]=temp;
    j=0;
}
int *temp1=new int[(size/5)+1];
for (int i = 0; i < (size/5); i++)
{
    temp1[i]=arr1[i][2];
}
return medOfMed(temp1,(size/5)+1);


}
int main(){
int n;
cout<<"Enter the size of the array: ";
cin>>n;
int *arr=new int[n];
cout<<"Enter the Elements of the array: ";
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
int res=medOfMed(arr,n);
cout<<"Median of Medians is: "<<res;

return 0;
}