#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
   vector<int> rank,parent,size;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for (int i = 0; i <=n; i++)
            {
                parent[i]=i;
                size[i]=i;
            }
        }
        int findParent(int node){
            if (node==parent[node])
            {
                return node;
            }
            return parent[node]=findParent(parent[node]);
        }
        void unionByRank(int u,int v){
            int ultpU=findParent(u);
            int ultpV=findParent(v);
            if (ultpU==ultpV){
                return;
            }
            else if (rank[ultpU<rank[ultpV]])
            {
                parent[ultpU]=ultpV;
            }
            else if(rank[ultpU]>rank[ultpV]){
                parent[ultpV]=ultpU;
            }
            else{
                parent[ultpV]=ultpU;
                rank[ultpU]++;
            }
        }

};
class Solution{
public:
    vector<pair<int,pair<int,int> > > spanningTree(int n,vector<vector<int> >adj[]){
        vector<pair<int,pair<int,int> > >edges;
        vector<pair<int,pair<int,int> > >res;
        pair<int,int>a;
        pair<int,pair<int,int> >b;
        for (int i = 0; i < n; i++){
            for(auto it:adj[i]){
                int wt=it[1];
                 a.first=i;
                a.second=it[0];
                b.first=wt;
                b.second=a;
                edges.push_back(b);
            }}
        DisjointSet ds(n);
        sort(edges.begin(),edges.end());
            for(auto it: edges){
                int wt=it.first;
                int u=it.second.first;
                int v=it.second.second;

                if (ds.findParent(u) != ds.findParent(v)){
                    pair<int,int>resA;
                    pair<int,pair<int,int> >resB;
                    resB.first=wt;
                    resA.first=u;
                    resA.second=v;
                    resB.second=resA;
                    ds.unionByRank(u,v);
                    res.push_back(resB);
                }}
            return res;
    }
};
int main(){
int m,n,x,y,w;
cout<<"Enter No. of nodes: ";
cin>>n;
cout<<"Enter No. of edges: ";
cin>>m;
vector<vector<int> >adj[n];
for (int i = 0; i < m; i++)
{
    cout<<"Enter the edge pair: ";
    cin>>x;
    cin>>y;
    cout<<"Enter the edge weight of edge pair "<<x<<" "<<y<<" : ";
    cin>>w;
    vector<int>t1,t2;
    t1.push_back(y-1);
    t1.push_back(w);
    adj[x-1].push_back(t1);
    t2.push_back(x-1);
    t2.push_back(w);
    adj[y-1].push_back(t2);

}
Solution obj;
vector<pair<int,pair<int,int> > > res=obj.spanningTree(n,adj);
for(auto it: res){
cout<<"edge: ("<<it.second.first+1<<","<<it.second.second+1<<") & weight: "<<it.first<<endl;
}

return 0;
}
