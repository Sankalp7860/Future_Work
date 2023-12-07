#include<iostream>
using namespace std;
int * nonStableCountSort(int *arr,int n){
int *res=new int[n];
int temp=arr[0];
for (int i = 1; i < n; i++)
    if (temp<arr[i])
        temp=arr[i];
temp++;
int *temp1=new int[temp];
for (int i = 0; i < temp; i++)
    temp1[i]=0;
for (int i = 0; i < n; i++)
{
    temp1[arr[i]]++;
}
int j=0;
for (int i = 0; i < temp; i++){
    if (temp1[i]!=0){
        res[j]=i;
        temp1[i]--;
        j++;
        i--;
    }}
return res;
}
int * stableCountSort(int *arr,int n){
int *res=new int[n];
int temp=arr[0];
for (int i = 1; i < n; i++)
    if (temp<arr[i])
        temp=arr[i];
temp++;
int *temp1=new int[temp];
for (int i = 0; i < temp; i++)
    temp1[i]=0;
for (int i = 0; i < n; i++)
    temp1[arr[i]]++;
for (int i = 1; i < temp; i++)
    temp1[i]=temp1[i]+temp1[i-1];

for (int i = n-1; i >=0; i--)
{
    res[temp1[arr[i]]-1]=arr[i];
    temp1[arr[i]]--;
}
return res;
}
int main(){
int n;
cout<<"Enter the size of the array: ";
cin>>n;
int * arr=new int[n];
cout<<"Enter the Positive Elements of the array: ";
for (int i = 0; i < n; i++)
    cin>>arr[i];
int *res1=nonStableCountSort(arr,n);
cout<<"The array after non Stable Counting Sort is: ";
for (int i = 0; i < n; i++)
{
    cout<<res1[i]<<" ";
}
cout<<endl;
int *res2=stableCountSort(arr,n);
cout<<"The array after Stable Counting Sort is: ";
for (int i = 0; i < n; i++)
{
    cout<<res2[i]<<" ";
}
return 0;
}