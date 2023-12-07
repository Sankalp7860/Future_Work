#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> bfs(vector<int>adjLis[],int size){
    int * vis=new int[size];
    vis[0]=1;
    queue<int>q;
    q.push(0);
    vector<int>bfs1;
    while (!(q.empty()))
    {
        int node=q.front();
        q.pop();
        bfs1.push_back(node);
            for(auto it:adjLis[node]){
                if (!(vis[it]))
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
    }
    return bfs1;
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
vector<int>bfs1=bfs(adjLis,n);
for (int i = 0; i < bfs1.size(); i++)
{
    cout<<bfs1[i]+1<<" ";
}
return 0;
}

