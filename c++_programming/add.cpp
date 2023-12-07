#include<iostream>
using namespace std;
int main(){
    int i,num,sum=0;
    cout<<"Enter The Number Of Elements : ";
    cin>>i;
    for (int j = 0; j < i; j++)
    {
    cout<<"Enter the number in "<<j+1<<" position: ";
    cin>>num;
    sum=sum+num;  
    }
    cout<<"The sum of the above numbers are: " <<sum;
    return 0;
}
