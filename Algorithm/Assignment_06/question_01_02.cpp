#include<iostream>
#include<vector>
using namespace std;
int fibonacci(int n,vector<int>&arr){
if (arr[n-1])
{
    return(arr[n-1]);
}
   
if (n==1){
    arr[0]=0;
    return 0;}
else if (n==2 ||n==3){
    arr[n-1]=1;
    return 1;}
arr[n-1]=fibonacci(n-1,arr)+fibonacci(n-2,arr);
return fibonacci(n-1,arr)+fibonacci(n-2,arr);
}



int main(){
int n;
cout<<"Enter the nth Fibonacci number: ";
cin>>n;
vector<int>arr(n,0);
cout<<"The number at position "<<n<<" in fibinacci series is: "<<fibonacci(n,arr);
    return 0;
}