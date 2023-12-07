#include<iostream>
#include<vector>
using namespace std;
int Binary_Search(vector<int> arr,int n,int num){
int mid;
int low=0;
int high=n-1;

for (int i = 0; i < n; i++){
     mid=low+ (high - low)/2;
    if (arr[mid]==num)
    {
        return mid;
        break;
    }
    else if (arr[mid]>num)
    {
        high=mid-1;
    }
    else if (arr[mid]<num)
    {
        low=mid+1;
    }  
}
    return -1;
}
int Alpha_Search(vector<int> arr,int n,int num){
int mid;
int low=0;
int high=n-1;

for (int i = 0; i < n; i++){
     mid=low+ (high - low)*2/3;
    if (arr[mid]==num)
    {
        return mid;
        break;
    }
    else if (arr[mid]>num)
    {
        high=mid-1;
    }
    else if (arr[mid]<num)
    {
        low=mid+1;
    }  
}
    return -1;
}
int Beta_Search(vector<int> arr,int n,int num){
int mid;
int low=0;
int high=n-1;

for (int i = 0; i < n; i++){
     mid=low+ (high - low)*1/4;
    if (arr[mid]==num)
    {
        return mid;
        break;
    }
    else if (arr[mid]>num)
    {
        high=mid-1;
    }
    else if (arr[mid]<num)
    {
        low=mid+1;
    }  
}
    return -1;
}

int main() {
int n,num;
vector<int> arr(n,0);
cout<<"Please Enter the size of the array: ";
cin>>n;
cout<<"Enter the elements of the array: ";
for (int i=0;i<n;i++){ 
    cin >>arr[i] ;
     }
cout<<"Enter the Element to be search: ";
cin>>num; 
int b=Binary_Search(arr,n,num);
if (b==-1)
{
    cout<<"Number is not found in the array!!!"<<endl;
}
else
{
cout<<"Binary Search--> The Number found at index: "<<b<<endl;
}
int a=Alpha_Search(arr,n,num);
if (a==-1)
{
    cout<<"Number is not found in the array!!!"<<endl;
}
else
{
cout<<"Alpha Search--> The Number found at index: "<<a<<endl;
}
int c=Beta_Search(arr,n,num);
if (c==-1)
{
    cout<<"Number is not found in the array!!!"<<endl;
}
else
{
cout<<"Beta Search--> The Number found at index: "<<c<<endl;
}

return 0;
}
