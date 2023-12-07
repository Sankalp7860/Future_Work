#include<iostream>
#include<vector>
using namespace std;
int fibo(int n){
int p=0,q=1,res;
if (n==1)
{
    return 0;
}
else if (n==2)
{
    return 1;
}
for (int i = 2; i < n; i++)
{
    res=p+q;
    p=q;
    q=res;
}
return res;

}
int main() {
int n;
int res;
cout<<"Enter the nth Fibonacci number: ";
cin>>n;
cout<<"The number at position "<<n<<" in fibinacci series is: "<<fibo(n);
return 0;
}