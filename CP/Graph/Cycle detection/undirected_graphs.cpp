#include<bits/stdc++.h>

using namespace std;

const int N=1e4;
int n;
vector<int>g[N];
vector<bool>v;

bool dfs1(int u,int par)
{
	v[u]=true;
	for(int i=0;i<g[u].size();i++)
	{
		if(!v[g[u][i]])
		{
			if(dfs1(g[u][i],u))
				return true;
		}
		else if(g[u][i] != par)
			return true;
	}
	return false;
}

bool dfs()
{
  	for(int i=0;i<n;i++)
    {
		if(!v[i])
		{
			if(dfs1(i,-1))
				return true;
		}
    }
    return false;
}

int main()
{
	int m,a,b;
	bool f;
	cin>>n>>m;
	v.assign(n,false);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	f=dfs();
	if(f)
		cout<<"Graph has cycle !!!";
	else
		cout<<"No cycle ";

}