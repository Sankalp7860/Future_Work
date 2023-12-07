#include<iostream>
#include<vector>
using namespace std;
int main() {
int n;
vector<int> arr(n,0);
cout<<"Please Enter the size of the array: ";
cin>>n;
cout<<"Enter the elements of the array: ";
for (int i=0;i<n;i++){ 
    cin >>arr[i] ; 
}
if (*(arr.begin())>(arr[n-1]))
{
    cout<<"The maximum value in the array is: "<<*arr.begin()<<endl;
    cout<<"The minimum value in the array is: "<<arr[n-1];
    
}
else
{
    cout<<"The maximum value in the array is: "<<arr[n-1]<<endl;
    cout<<"The minimum value in the array is: "<<*arr.begin();
}

return 0;
}