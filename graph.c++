#include<bits/stdc++.h>
using namespace std;

void prims()
{
    int N=5;
    vector<pair<int,int> > adj[N]; 
	adj[0].push_back({1,2});
	adj[0].push_back({3,6});
	adj[1].push_back({0,2});
	adj[1].push_back({2,3});
	adj[1].push_back({3,8});
	adj[1].push_back({4,5});
	adj[2].push_back({1,3});
	adj[2].push_back({4,7});
	adj[3].push_back({0,6});
	adj[3].push_back({1,8});
	adj[4].push_back({1,5});
	adj[4].push_back({2,7});
    vector<int>parent(N,-1);
    vector<bool>mst(N,false);
    vector<int>key(N,INT_MAX);
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > q;
    q.push({0,0});
    parent[0]=0;
    key[0]=0;
    mst[0]=true;
    while(!q.empty())
    {
        auto node=q.top().first;
        auto wt=q.top().second;
        q.pop();
        mst[node]=true;
        for(auto it:adj[node])
        {
            int temp_node=it.first;
            int temp_wt=it.second;
            if(mst[temp_node]==false and temp_wt<key[temp_node])
            {
                parent[temp_node]=node;
                key[temp_node]=temp_wt;
                q.push({temp_node,temp_wt});
            }
        }
    }
    for(int i=1;i<N;i++)
    {
        cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
    }
}
void cheapest_flight()
{
    vector<vector<int>>flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src=0;
    int dest=3;
    int k=1;
    queue<pair<int,int>>q;
    vector<int>disti(4,INT_MAX);
    vector<vector<int>>adj[4];
    for(auto it:flights)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }


    q.push({0,src});
    k+=1;
    disti[src]=0;
    while(!q.empty() and k--)
    {
        int n=q.size();
        while(n--)
    {   int dist=q.front().first;
        int node=q.front().second; 
        q.pop();
        
        
            for(auto it:adj[node])
            {
                int temp_node=it[0];
                int temp_dist=it[1];
                if(disti[temp_node]>dist+temp_dist)
                {
                    disti[temp_node]=dist+temp_dist;
                    q.push({dist+temp_dist,temp_node});
                }
            }
        
    }
    }
   for(auto it:disti)
   {
         cout<<it<<" ";
   }
}
void dj()
{
    int n=5;
    vector<pair<int,int>> g[n+1];
    	g[1].push_back({2,2});
	g[1].push_back({4,1});
	g[2].push_back({1,2});
	g[2].push_back({5,5});
	g[2].push_back({3,4});
	g[3].push_back({2,4});
	g[3].push_back({4,3});
	g[3].push_back({5,1});
	g[4].push_back({1,1});
	g[4].push_back({3,3});
	g[5].push_back({2,5});
	g[5].push_back({3,1});
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> q;
    q.push({0,1});

    vector<int>d(n+1,INT_MAX);
    d[1]=0;
    while(!q.empty())
    {
        auto node=q.top().second;
        auto dist=q.top().first;
        q.pop();
        for(auto it:g[node])
        {
            int temp_node=it.first;
            int temp_wt=it.second;
            if(dist+temp_wt<d[temp_node])
            {
                d[temp_node]=dist+temp_wt;
                q.push({d[temp_node],temp_node});
            }
        }
    }
    for(auto it:d)
    {
        cout<<it<<" ";
    }	
}
int main()
{
    dj();
}