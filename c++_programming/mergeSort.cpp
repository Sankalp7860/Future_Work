#include<iostream>
using namespace std;

void solve(int ** arr,int l,int mid,int h){
int n1=mid-l+1;
int n2=h-mid;
int * arr1=new int[n1];
int * arr2=new int[n2];
for (int i = 0; i < n1; i++)
{
    arr1[i]= (*arr)[l+i];
}
for (int i = 0; i < n2; i++)
{
    arr2[i]= (*arr)[mid+i+1];
}
int i=0,j=0,k=l;
while (i<n1 && j<n2)
{
    if (arr1[i]<=arr2[j])
    {
        (*arr)[k]=arr1[i];
        i++;
        k++;
    }
    else{
        (*arr)[k]=arr2[j];
        j++;
        k++;
    } 
}
while (i<n1)
{
    (*arr)[k]=arr1[i];
    i++;
    k++;
}
while (j<n2)
{
   (*arr)[k]=arr2[j];
    j++;
    k++;
}
}
void mergeSort(int ** arr,int l,int h){
if (l<h)
{
    int mid=l+((h-l)/2);
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    solve(arr,l,mid,h);
}}


int main() {
int n;
cout<<"Enter the size of the array: ";
cin>>n;
int * arr= new int[n];
cout<<"Enter the Elements of the array: ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
mergeSort(&arr,0,n-1);
cout<<"The array after sorting is: ";
for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}

return 0;
}