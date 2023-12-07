#include<iostream>
#include<utility>
using namespace std;
int main() {
pair<int,int> p;
p.first=1;
p.second=3;
cout<<p.first<<endl<<p.second;
// pair<int,pair<int,int> > q={1,{2,3}};
// cout<<q.first<<endl<<q.second.first<<endl<<q.second.second;
// pair<int,int> arr[]={{1,3},{2,3},{4,5}};
// cout<<arr[0].second;
return 0;
}