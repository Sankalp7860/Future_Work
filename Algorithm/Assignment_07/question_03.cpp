#include<iostream>
#include<vector>
using namespace std;
int main(){
int n,t;
cout<<"Enter the size of the Square Matrix: ";
cin>>n;
vector<vector<int> >arr1;
vector<vector<int> >arr2;
cout<<"Enter the Elements of the First Matrix: ";
for (int i = 0; i < n; i++)
{
    vector<int>temp;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        temp.push_back(t);
    }
    arr1.push_back(temp);
}
cout<<"Enter the Elements of the Second Matrix: ";
for (int i = 0; i < n; i++)
{
    vector<int>temp;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        temp.push_back(t);
    }
    arr2.push_back(temp);
}



}