#include<bits/stdc++.h>
using namespace std;


void implement_dijkstra(int s, vector<int> & dis,vector<pair<int,int>>adj[],int n,vector<int> & pre) {

   int INFINITE = 1000000000;
   pre.assign(n,-1);
   dis.assign(n, INFINITE);
   vector<bool> u(n, false);

   dis[s] = 0;
   for (int i = 0; i < n; i++) {
       int v = -1;
       for (int j = 0; j < n; j++) {
           if (!u[j] && (v == -1 || dis[j] < dis[v]))
               v = j;
       }

       if (dis[v] == INFINITE)
           break;

       u[v] = true;
       for (auto curr_edge : adj[v]) {
           int to = curr_edge.first;
           int len = curr_edge.second;

           if (dis[v] + len < dis[to]) {
               dis[to] = dis[v] + len;
               pre[to] = v;
           }
       }
   }
}

void display(vector<pair<int,int>> adj[],int e){

   cout<<"\n Adjacency list : \n";
   for(int i=0;i<e;i++){
       cout<<i<<" --> ";
       for(int j=0;j<adj[i].size();j++){
           cout<<adj[i][j].first<<" "<<adj[i][j].second<<" ";
       }
       cout<<"\n";

   }
}

vector<int> find_path(int s, int t, vector<int> const& pre) {
   vector<int> res;

   for (int v = t; v != s; v = pre[v])
       res.push_back(v);
   res.push_back(s);

   reverse(res.begin(), res.end());
   return res;
}

 

int main(){
   int e,v;
   cin>>e>>v;
   vector<pair<int, int>> adj[v];
   for(int i=0;i<e;i++){
       int a,b,w;
       cin>>a>>b>>w;
       adj[a].push_back({b,w});
   }
   int source,destination;
   cin>>source>>destination;
   display(adj,v);
   vector<int> dis;
   vector<int> predecessor;
   implement_dijkstra(source,dis,adj,v,predecessor);

   cout<<"\n Shortest path distance from "<<source<<" to "<<destination<<" is : "<<dis[destination];

   vector<int> path;
   path=find_path(source,destination,predecessor);
   cout<<"\n Shortest path from "<<source<<" to "<<destination<<" is : ";
   for(int i=0;i<path.size();i++){
       cout<<path[i]<<" ";
   }

   return 0;
}