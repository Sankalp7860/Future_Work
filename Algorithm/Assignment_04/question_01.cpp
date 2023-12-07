#include<iostream>
using namespace std;
int findPeak(int * arr,int l,int r){
int mid=l+((r-l)/2);
if (arr[l]>=arr[l+1])
{
    return arr[l];
}
else if (arr[r]>=arr[r-1])
{
    return arr[r];
}
else if (arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1])
{
    return arr[mid];
}
else if (arr[mid]>=arr[mid+1] && arr[mid]<=arr[mid-1])
{
    return findPeak(arr,l,mid-1);
}
else if (arr[mid]>=arr[mid-1]&& arr[mid]<=arr[mid+1])
{
    return findPeak(arr,mid+1,r);
}
else if (arr[mid]<=arr[mid-1] && arr[mid]<=arr[mid+1])
{
    if (arr[mid-1]>=arr[mid+1])
    {
        return findPeak(arr,l,mid-1);
    }
    else{
        return findPeak(arr,mid+1,r);
    }
}
return -1;
}
int main(){
    int n;
   cout<<"Enter the size of an array: ";
   cin>>n;
   int *arr=new int[n];
   cout<<" Enter the Elements of the array: ";
   for (int  i = 0; i < n; i++)
   {
        cin>>arr[i];
   }
  int peak= findPeak(arr,0,n-1);
    cout<<"The peak Element is: "<<peak;
}