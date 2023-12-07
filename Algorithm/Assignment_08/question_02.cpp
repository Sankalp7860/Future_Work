#include<iostream>
#include<vector>
using namespace std;
int findLargestElement(int * arr,int l,int h){
    if (h==l+1)
    {
        return arr[h]>arr[l]?arr[h]:arr[l];
    }
    int mid=(l+h)/2;
    if (arr[mid]<arr[h] && arr[mid]<arr[l])
    {
        return findLargestElement(arr,l,mid);
    }
    else{
        return findLargestElement(arr,mid,h);
    }
}
int main(){
    int n;
    int * arr=new int[n];
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the Elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int num=findLargestElement(arr,0,n-1);
    cout<<"The Largest Value is: "<<num;
}