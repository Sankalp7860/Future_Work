#include<iostream>
using namespace std;

int max_arr(int * arr,int s,int n){
if ((n-s)==0)
{
    return arr[n];
}
else if ((n-s)==1)
{
        return arr[n]>arr[s]?arr[n]:arr[s];
}
return max_arr(arr,0,(s+n)/2)>max_arr(arr,((n+s)/2)+1,n)?max_arr(arr,0,(n+s)/2):max_arr(arr,((n+s)/2)+1,n);
}



int * max_min(int * arr,int s,int n){
    int *maxMin=new int[2];
if ((n-s)==0){
    maxMin[0]=arr[n];
    maxMin[1]=arr[n];
    return maxMin;
}
else if ((n-s)==1){
    
    maxMin[0]=arr[n]>arr[s]?arr[n]:arr[s];
    maxMin[1]=arr[n]<arr[s]?arr[n]:arr[s];
        return maxMin;
}
int  * max1=max_min(arr,0,(s+n)/2)>max_min(arr,((n+s)/2)+1,n)?max_min(arr,0,(n+s)/2):max_min(arr,((n+s)/2)+1,n);
int  * min1=max_min(arr,0,(s+n)/2)<max_min(arr,((n+s)/2)+1,n)?max_min(arr,0,(n+s)/2):max_min(arr,((n+s)/2)+1,n);
maxMin[0]=max1[0]>min1[0]?max1[0]:min1[0];
maxMin[1]=max1[1]<min1[1]?max1[1]:min1[1];
return maxMin;
}


int * max_Secmax(int * arr,int s,int n){
    int *max=new int[2];
if ((n-s)==0){
    max[0]=arr[n];
    max[1]=INT_MIN;
    return max;
}
else if ((n-s)==1){
    
    max[0]=arr[n]>arr[s]?arr[n]:arr[s];
    max[1]=arr[n]<arr[s]?arr[n]:arr[s];
        return max;
}
int  * max1=max_Secmax(arr,0,(s+n)/2)>max_Secmax(arr,((n+s)/2)+1,n)?max_Secmax(arr,0,(n+s)/2):max_Secmax(arr,((n+s)/2)+1,n);
int  * max2=max_Secmax(arr,0,(s+n)/2)<max_Secmax(arr,((n+s)/2)+1,n)?max_Secmax(arr,0,(n+s)/2):max_Secmax(arr,((n+s)/2)+1,n);
max[0]=max1[0]>max2[0]?max1[0]:max2[0];
if (max[0]==max1[0])
{
    max[1]=max1[1]>(max2[0]>max2[1]?max2[0]:max2[1])?max1[1]:(max2[0]>max2[1]?max2[0]:max2[1]);
}
else{
     max[1]=max2[1]>(max1[0]>max1[1]?max1[0]:max1[1])?max2[1]:(max1[0]>max1[1]?max1[0]:max1[1]);
}
return max;
}

int main(){
    int n,s=0;
    cout<<"Please Enter the size of the array: ";
    cin>>n;
    int *arr=new int(n);
    cout<<"Enter the Elements of the array: ";
    for (int i = 0; i < n;i++ )
    {
        cin>>arr[i];
    }
    int max=max_arr(arr,s,n-1);
    cout<<"The Maximum of the array is: "<<max<<endl;
    int *maxMin=max_min(arr,0,n-1);
    cout<<"The Maximum of the array is: "<<maxMin[0]<<endl<< "The minimum of the array is:  "<<maxMin[1]<<endl;
    int * maxSecmax=max_Secmax(arr,s,n-1);
     cout<<"The Maximum of the array is: "<<maxSecmax[0]<<endl<< "The second Maximum of the array is:  "<<maxSecmax[1]<<endl;
return 0;
}