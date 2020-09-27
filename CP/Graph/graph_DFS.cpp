#include<bits/stdc++.h>

using namespace std;

vector<bool>v;
vector<vector<int>>g;

void edge(int a,int b)
{
	g[a].emplace_back(b);
}

void dfs(int u)                                                               //******* DFS *******
{
	v[u]=true;
	cout<<u<<' ';
	for(auto it=g[u].begin();it<g[u].end();it++)
	{
		if(!v[*it])
			dfs(*it);
	}
}

int main()
{
	int n,e,a,b;                                                        //Graph creation - START
	cout<<"Enter no. of vertices - ";
	cin>>n;
	cout<<"Enter no. of edges - ";
	cin>>e;
	v.assign(n,false);
	g.assign(n,vector<int>());
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		edge(a,b);
	}                                                                     //Graph creation - END

	for(int i=0;i<n;i++)                                                  //this loop used because .... what if some vertices are not connected and are independent
	{
		if(!v[i])
			dfs(i);                                                      //call function to do- "DFS"
	}
	return 0;
}
