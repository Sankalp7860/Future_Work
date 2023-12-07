#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool dfs(int node,int parent,vector<int>adjList[],vector<int>&vis){
vis[node]=1;
for(auto adjNode:adjList[node]){
    if(!(vis[adjNode])){
        if (dfs(adjNode,node,adjList,vis)==true){
            return true;
        }}
    else if(adjNode!=parent){
        return true;
    }
    
}
return false;
}
bool isCycle(int V,vector<int>adjList[]){
vector<int>vis(V,0);
for (int i = 0; i < V; i++){
    if(!vis[i]){
        if (dfs(i,-1,adjList,vis)==true)
        {
            return true;
        }
    }
}
return false;
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

if (isCycle(n,adjLis)){
    cout << "Graph contains cycle";
}
else{
    cout << "Graph does not contain cycle";
}
return 0;
}



