#include<bits/stdc++.h>

using namespace std;

vector<int>dist;
vector < vector < pair < int,int > > >g;

void edge(int a,int b,int w)
{
	g[a].emplace_back(make_pair(b,w));
}

void shortestP(int src)                                                                 //"Dijkstras" ...function to find shortest paths from source
{
	priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int> > >q;   
	q.push(make_pair(0,src));
	dist[src]=0;
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for(auto i=g[u].begin();i<g[u].end();i++)
		{
			int v=(*i).first;
			int weight=(*i).second;
			if(dist[u]+weight < dist[v])
			{
				dist[v]=dist[u]+weight;
				q.push(make_pair(dist[v],v));
			}
		}
	}
}

int main()
{
	int n,e,a,b,w,src;                                                   //Graph creation - START
	cout<<"Enter no. of vertices - ";
	cin>>n;
	cout<<"\nEnter no. of edges - ";
	cin>>e;
	dist.assign(n,INT_MAX);
	g.assign(n,vector< pair <int,int> >());
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		edge(a,b,w);                                                  // w= Weight of edge
	}                                                                 //Graph creation - END
	cout<<"\nEnter the source vertex - ";
	cin>>src;

	shortestP(src);                                                  //function call to find shortest distance from from source to all vertex

	cout<<"\nDistances from "<<src<<"to different vertices are - ";
		for(int i=0;i<n;i++)
			cout<<dist[i]<<' ';
	return 0;
}

