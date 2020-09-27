#include<bits/stdc++.h>

using namespace std;

vector<bool>v;
vector<vector<int>>g;

void edge(int a,int b)
{
	g[a].emplace_back(b);
}

void bfs(int i)                                                                //***** BFS ******
{
	queue<int>q;
	q.push(i);
	v[i]=true;
	while(!q.empty())
	{
		int vv=q.front();
		q.pop();
		cout<<vv<<' ';
		for(auto i=g[vv].begin();i<g[vv].end();i++)
			{
				if(!v[*i])
				{
					q.push(*i);
					v[*i]=true;
				}
			}
	}
}

int main()
{
	/*ios_base::sync_with_stdio(false);
	cin.tie(NULL);*/
	cout.precision(10);
	cout<<fixed;

	int n,e,a,b;                                                                    //GRAPH creation -START
	cout<<"\nEnter no. of vertices - ";
	cin>>n;
	cout<<"\nEnter no. of edges - ";
	cin>>e;
	v.assign(n,0);
	g.assign(n,vector<int>());
	cout<<"\nConnect vertices (a->b) -  ";
	for(int i=0;i<e;i++)
	{
		cin>>a>>b;
		edge(a,b);
	}                                                                         //GRAPH creation -END

	for(int i=0;i<n;i++)                                                      //this loop used because .... what if some vertices are not connected and are independent
	{
		if(!v[i])
			bfs(i);                                                          //call function to do - "BFS"
	}

	return 0;
}