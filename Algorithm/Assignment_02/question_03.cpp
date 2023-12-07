#include<iostream>
#include<vector>
using namespace std;
int Ternary_Search(vector<int>arr,int n,int num){
int lowmid,highmid;
int low=0;
int high=n-1;

for (int i = 0; i < n; i++){
     lowmid=low+ (high - low)/3;
     highmid=low+ (high - low)*2/3;
    if (arr[lowmid]==num)
    {
        return lowmid;
    
    }
    else if (arr[highmid]==num)
    {
        return highmid;
        
    }
    else if (arr[lowmid]>num)
    {
        high=lowmid-1;
        
    }
    else if (arr[lowmid]<num&& num<arr[highmid])
    {
        low=lowmid+1;
        high=highmid-1;
    }  
    else if (arr[highmid]<num)
    {
        low=highmid+1;
        
    }
}
    return -1;
}
int main(){
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
int b=Ternary_Search(arr,n,num);
if (b==-1)
{
    cout<<"Number is not found in the array!!!"<<endl;
}
else
{
cout<<"Ternary Search--> The Number found at index: "<<b<<endl;
}

    return 0;
}