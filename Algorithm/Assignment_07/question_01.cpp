#include<iostream>
#include<vector>
using namespace std;
int NoTie(int num){
if (num==0 || num==1){
    return 1;}
return num * NoTie(num-1);
}
int Tie(int num){
if (num==1)
{
    return 1;
}
// return NoTie(num)+


}
int main(){
int num;
vector<vector<int> >arr(5,vector<int>(3,-1));
cout<<"Enter the Number of Runners: ";
cin>>num;
cout<<"Possible Outcomes of the race without Tie between runners: "<<NoTie(num)<<endl;
cout<<"Possible Outcomes of the race with Tie between runners: "<<Tie(num);

    return 0;
}