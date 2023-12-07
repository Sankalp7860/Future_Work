#include<iostream>
#include<utility>
#include<vector>
using namespace std;
pair<int,int>res1,res2;

bool CompareX(pair<int,int>&a,pair<int,int>&b){
    return a.first <b.first;
}

bool CompareY(pair<int,int>&a,pair<int,int>&b){
    return a.second <b.second;
}
int distance(pair<int,int>&a,pair<int,int>&b){
    int x= b.first-a.first;
    int y= b.second-a.second;
    return (x*x)+(y*y);
}
void PrintVector(vector<pair<int,int> >&v){
    for(auto i: v){
        cout<<"["<<i.first<<","<<i.second<<"]"<<endl;
    }
}
pair<pair<int,int>,pair<int,int> >getClosestPair(vector<pair<int,int> >&p,vector<pair<int,int> >&Px,vector<pair<int,int> >&Py,int l,int h){
    if (h-l<=3)
    {
        pair< pair<int,int>,pair<int,int> >localres;
        long int d=INT_MAX;
        for (int i = l; i <=h; ++i)
        {
            for (int j = i+1; j <= h; ++j)
            {
                if (distance(Px[i],Px[j])<d)
                {
                    d=distance(Px[i],Px[j]);
                    localres.first=Px[i];
                    localres.second=Px[j];
                }
                
            }
            
        }
        return localres;
        
    }
    int mid=l+((h-l)/2);
pair<pair<int,int>,pair<int,int> >a,b;
a=getClosestPair(p,Px,Py,l,mid);
b=getClosestPair(p,Px,Py,mid+1,h);
long int da=distance(a.first,a.second);
long int db=distance(b.first,b.second);
long int s=da>db?db:da;

vector<pair<int,int> > Sy;
    
    for(int i = l ; i<=h ; i++) if(abs(Py[i].first-Px[mid].first) < s) Sy.push_back(Py[i]);
    int count = 0;
    for(int i=0 ; i<Sy.size(); i++){
        for(int j= i+1; j<Sy.size()  && (Sy[j].second - Sy[i].second) < s && count++<14; j++) {
             long int dis = distance(Sy[i],Sy[j]);
            if(dis<s){
                s = dis;
                a.first =Sy[i];
                a.second=Sy[j];
            }
        }
    }
    

    return (da <= db) ? a : b;
    
}

void findClosestPair(vector<pair<int,int> >&p){
vector<pair<int,int> >Px=p;
vector<pair<int,int> >Py=p;
sort(Px.begin(), Px.end(),CompareX); 
sort(Py.begin(), Py.end(),CompareY);
pair<pair<int,int>,pair<int,int> >closestPair=getClosestPair(p,Px,Py,0,p.size()-1);
res1=closestPair.first;
res2=closestPair.second;

}
int main(){
    int n;
    cout<<"Enter the number of pairs: ";
    cin>>n;
    vector<pair<int,int> >arr(n);
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the "<<i+1<<" Pair: ";
        cin>>arr[i].first>>arr[i].second;
    }
    findClosestPair(arr);
    cout<<"The Closest pair is: ["<<res1.first<<","<<res1.second<<"] and ["<<res2.first<<","<<res2.second<<"]";
return 0;
}


