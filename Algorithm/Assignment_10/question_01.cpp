#include<iostream>
#include<vector>
#include<utility>
#include<list>
#include<queue>
using namespace std;
bool isBipartite(vector<pair<int, list<int> > >& adjList, int start) {
    
    vector<int> colors(adjList.size(), -1);
    
    colors[start] = 0;
    
    queue<int> q;
    q.push(start);
    
    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        
        for (int adjVertex : adjList[currVertex].second) {
            if (colors[adjVertex] == -1) {
                colors[adjVertex] = 1 - colors[currVertex];
                q.push(adjVertex);
            }
            else if (colors[adjVertex] == colors[currVertex]) {
                return false;
            }
        }
    }
    
    return true;
}
int main(){
int n,m,x,y;
cout<<"\tPlease Make Sure Your Graph is Connected Graph!!!\n";
cout<<"Enter the number of nodes: ";
cin>>n;
cout<<"Enter the number of edges: ";
cin>>m;
vector<int>data(n);
vector<pair<int,list<int> > >adjList(n);
for (int i = 0; i < n; i++)
{
    cout<<"Enter the data of the node No. "<<i+1<<" : ";
    cin>>data[i];
    adjList[i].first=data[i];
}
for (int i = 0; i < m; i++)
{
    cout<<"Enter the edge pair No. "<<i+1<<": ";
    cin>>x;
    cin>>y;
    for (int j = 0; j < n; j++)
    {
        if (x==data[j])
        {
            adjList[j].second.push_back(y);
        }
        if (y==data[j])
        {
            adjList[j].second.push_back(x);
        }
    }
}
bool check=isBipartite(adjList,0);
if (check)
{
    cout<<"Graph is bipartite";
}
else{
    cout<<"Graph is not bipartite";
}
return 0;
}