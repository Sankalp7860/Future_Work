#include<iostream>
#include<vector>
using namespace std;
int main(){
// vector<int>v;
// v.push_back(1);
// v.emplace_back(2);
// cout<<*(v.begin())<<endl;
// cout<<v[0];
// vector<pair<int,int> >vec;
// vec.push_back({1,3});
// vec.emplace_back(1,3);
// vector<int>a(5,100);
// it means a will be of size 5 nad containg values 100 5 times
// vector<int>b(a);
// a will be copied to b


// vector<int>::iterator it=v.begin();
// it++;
// cout<<*it<<endl;
// it=it+2;
// cout<<*it<<endl;
// vector<int>::iterator ite=v.end();
// vector<int>::reverse_iterator itre=v.rend();
// vector<int>::reverse_iterator itrb=v.rbegin();
// cout<<v[0]<<endl<<v.at(1);
// cout<<v.back();



// for(vector<int>::iterator itq=v.begin();itq != v.end();itq++){
//     cout<<*itq<<endl;
// }
// for(auto itq=v[0]; itq !=v.back();itq++){
//     cout<<itq<<endl;
// }

// {10, 20, 12, 23) 
// v.erase(v.begin ()+1);
// // {10, 20, 12, 23, 35}
// v.erase (v. begin() + 2, v.begin() + 4); // // (10, 20, 35) [start, end)


vector<int>v(2, 100); // {100, 100}
// v. insert (v.begin(), 300); // {300, 100, 100};
// v. insert (v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100} 
// vector<int>copy(2,50);// {50,50}
// v. insert (v.begin(), copy.begin(), copy.end ()); // {50, 50, 300, 10, 10, 100, 100)

// cout<<v.size();
// v.pop_back();
// v1={1,3}
// v2={2,5}
// v1.swap(v2);
// cout<<v.empty();
return 0;
}