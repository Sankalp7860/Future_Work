#include<iostream>
using namespace std;
int missingElement(int *arr,int l,int r){
int mid=l+((r-l)/2);
if (mid==0 &&arr[mid]!=1)
{
    return 1;
}

else if (mid+1!=arr[mid] && mid==arr[mid-1])
{
    return mid+1;
}
if (mid+1==arr[mid])
{
   return missingElement(arr,mid+1,r);
}
else{
   return  missingElement(arr,l,mid-1);
}

}
int main() {
int n;
    cout<<"Please Enter the size of the array: ";
    cin>>n;
    int *arr=new int(n);
    cout<<"Enter the Elements of the array: ";
    for (int i = 0; i < n;i++ )
    {
        cin>>arr[i];
    }
    int a=missingElement(arr,0,n-1);
cout<<"The Element Missing from the array is: "<<a;
    return 0;
}