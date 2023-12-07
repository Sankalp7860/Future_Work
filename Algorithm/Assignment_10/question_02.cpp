#include<iostream>
#include<vector>
#include<utility>
#include<list>
#include<queue>
using namespace std;


int bfs(vector<pair<int, list<int>>>& adjList, int start) {
    vector<bool> visited(adjList.size(), false);
    vector<int> distance(adjList.size(), 0);
    
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int currVertex = q.front();
        q.pop();
        
        for (int adjVertex : adjList[currVertex].second) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                distance[adjVertex] = distance[currVertex] + 1;
                q.push(adjVertex);
            }
        }
    }
    
    return *max_element(distance.begin(), distance.end());
}

int findDiameter(vector<pair<int, list<int>>>& adjList) {
    int diameter = 0;
    
    for (int i = 0; i < adjList.size(); i++) {
        int maxDistance = bfs(adjList, i);
        diameter = max(diameter, maxDistance);
    }
    
    return diameter;
}
int main(){
int n,m,x,y;
cout<<"\tPlease Make Sure Your Graph is Connected Graph!!!";
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
cout<<"The Diameter of the graph is: "<<findDiameter(adjList);

return 0;
}




