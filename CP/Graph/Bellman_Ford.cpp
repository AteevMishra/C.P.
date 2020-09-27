#include<bits/stdc++.h>

using namespace std;

vector<int>dis;
vector< vector < pair <int,int> > > g;

void edge(int a,int b,int w)
{
	g[a].emplace_back(make_pair(b,w));
}

void BM(int src,int n,int e)
{
	dis[src]=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			if(dis)
		}
	}
}
int main()
{
	int n,e,a,b,w,src;
	cout<<"Enter no. of vertices - ";
	cin>>n;
	cout<<"\nEnter no. of edges - ";
	cin>>e;
	dis.assign(n,INT_MAX);
	g.assign(n , vector<pair<int,int> >());
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>w;
		edge(a,b,w);
	}
	cout<<"\nEnter source  - ";
	cin>>src;
	BM(src,n,e);
}