#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void dfs(int node,vector<int>adjLis[],vector<int>&vis,vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it: adjLis[node]){
        if (!vis[it])
        {
            dfs(it,adjLis,vis,ls);
        }
        
    }
}



int main(){
int n,m,x,y;
cout<<"Enter the number of nodes: ";
cin>>n;
cout<<"Enter the number of edges: ";
cin>>m;
vector<int>adjLis[n];
for (int i = 0; i < m; i++)
{
    cout<<"Enter the edge pair: ";
    cin>>x>>y;
    adjLis[x-1].push_back(y-1);
    adjLis[y-1].push_back(x-1);
}
vector<int>vis(n,0);
vector<int>ls;
dfs(0,adjLis,vis,ls);
for (int i = 0; i < ls.size(); i++)
{
    cout<<ls[i]+1<<" ";
}
return 0;
}