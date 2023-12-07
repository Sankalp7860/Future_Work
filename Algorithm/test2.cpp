#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the Elements of the array: ";
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    
    cout<<"Enter the integer d: ";
    int d;
    cin>>d;
    int * dp=new int[n];

    for (int i=0;i<n;i++) dp[i]=1;

    for (int i=1;i<n; i++) 
        for (int j=0;j<i;j++) 
            if (arr[i]>arr[j] && arr[i]-arr[j]>=d) 
                dp[i] =max(dp[i],dp[j]+1);
            
        
    int maxLength = 0;

    for (int i=0; i<n;i++) maxLength =max(maxLength,dp[i]);
    cout <<"The length of the longest increasing subsequence is:"<< maxLength;
    return 0;
}
