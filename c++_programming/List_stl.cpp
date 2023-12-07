#include<iostream>
#include<list>
using namespace std;
int main() {
list<int> ls;
ls.push_back(2);
//{2}
ls.__emplace_back(4);
// {2, 4}

ls.push_front (5) ;
//{5, 2, 4}
// ls.__emplace_front(2);//{ 12, 4};
// rest functions same as vector
// begin, end, rbegin, rend, clear, insert, size, swap

}