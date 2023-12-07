#include<iostream>
using namespace std;
int fibonacci(int n){
if (n==1){
    return 0;}
else if (n==2 ||n==3){
    return 1;}
return fibonacci(n-1)+fibonacci(n-2);
}



int main(){
    int n;
    cout<<"Enter the nth Fibonacci number: ";
    cin>>n;
    cout<<"The number at position "<<n<<" in fibinacci series is: "<<fibonacci(n);
    return 0;
}