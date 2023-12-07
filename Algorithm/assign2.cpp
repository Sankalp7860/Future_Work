#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int node, vector<bool>& visited, stack<int>& stk,vector<vector<int> >& adjList) {
    visited[node]=true;
    for(int neighbor : adjList[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, visited, stk, adjList);
        }
    }
    stk.push(node);
}
vector<int> findVertices(int n,vector<vector<int > >adjLis) {
    stack<int> stk;
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, visited, stk, adjLis);
        }
    }
    vector<int> q;
    while(!stk.empty()) {
        q.push_back(stk.top());
        stk.pop();
    }
    vector<bool> vis(n, false);
    vector<int> Vertices;
    for(int node : q) {
        if (!vis[node]){
        vis[node]=true;
        Vertices.push_back(node);}
        for(int neighbor:adjLis[node]) {
            vis[neighbor]=true;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     if(!vis[i]) {
    //         Vertices.push_back(i);
    //     }
    // }
    return Vertices;
}

int main() {
    int n,m,x,y;
    cout<<"Enter Number of nodes: ";
    cin>>n;
    cout<<"Enter Number of Edges: ";
    cin>>m;
     vector<vector<int> > adjLis(n);
    for (int i = 0; i < m; i++)
    {
        cout<<"Enter the Edge pair "<<i+1<<" : ";
        cin>>x>>y;
       adjLis[x].push_back(y);
    }
    vector<int> result = findVertices(n, adjLis);
    cout << "Smallest set of vertices: ";
    for(int node : result) {
        cout<<node<<" ";
    }
    return 0;
}
