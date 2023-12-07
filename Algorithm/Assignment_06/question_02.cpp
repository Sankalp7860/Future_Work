#include<iostream>
#include<vector>
using namespace std;
int mediansOfMedians(vector<int>&arr){
int k=0,n=arr.size();
vector<vector<int> >arr1;
vector<int>temp(5),res(n/5);
for (int i = 0; i < n/5; i++)
{
    for (int j = 0; j < 5; j++)
    {
        temp[j]=arr[k];
        k++;
    }
    arr1.push_back(temp);
    temp.clear();
}
for (int i = 0; i < n/5; i++)
{
    sort(arr1[i].begin(),arr1[i].end());
}

cout<<arr1[0][2];
// for (int i = 0; i < n/5; i++)
// {
// vector<int>temp1=arr1[i];
// res.push_back(temp1[2]);
// temp1.clear();
// }


for (int i = 0; i <2; i++)
{
    cout<<res[i]<<" ";
}
return 0;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the Elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int res=mediansOfMedians(arr);
}