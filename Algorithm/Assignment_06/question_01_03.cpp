#include<iostream>
#include<vector>
using namespace std;
int main() {
int n;
int res;
cout<<"Enter the nth Fibonacci number: ";
cin>>n;
vector<int>arr(n,0);
arr[0]=0;
arr[1]=1;
arr[2]=1;
for (int i = 3; i < n; i++)
{
    arr[i]=arr[i-1]+arr[i-2];
}   
res=arr[n-1];   
cout<<"The number at position "<<n<<" in fibinacci series is: "<<res;
return 0;
}