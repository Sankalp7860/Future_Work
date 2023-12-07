#include<iostream>
#include<vector>
#include<utility>
#include<list>
using namespace std;
void unorderedMatrixToList(int **matrix,int * node,int n,int m){
vector<pair<int,list<int> > >adjList(n);
for (int i = 0; i < n; i++){
    adjList[i].first=node[i];}
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (matrix[i][j]!=0)
            adjList[i].second.push_back(node[j]);
cout<<"The Adjacency List of the given Adjacency Matrix is : "<<endl;
for (int i = 0; i < n; i++)
{
    cout<<node[i]<<"--> ";
    for(auto j:adjList[i].second){
        cout<<j<<" ";
    }
    cout<<endl;
}
}
int main(){
int n,m,x,y,a,b;
cout<<"Enter the number of nodes: ";
cin>>n;
cout<<"Enter the number of edges: ";
cin>>m;
int *node=new int[n];
int ** matrix=new int*[n];
for (int i = 0; i < n; i++)
{
    int *temp=new int[n];
    for (int j = 0; j < n; j++)
    {
        temp[j]=0;
    }
    matrix[i]=temp;
}

for (int i = 0; i < n; i++){
    cout<<"Enter the data for node "<<i+1<<": ";
    cin>>node[i];
}

for (int i = 0; i < m; i++)
{
    cout<<"Enter the edge pair "<<i+1<<": ";
    cin>>x;
    cin>>y;
    for (int i = 0; i < n; i++){
        if (x==node[i]){
            a=i;}
        if (y==node[i]){
            b=i;}
    }
    
    matrix[a][b]=1;
}
cout<<"The Entered Adjacency Matrix is: "<<endl;
for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
}
unorderedMatrixToList(matrix,node,n,m);
return 0;
}