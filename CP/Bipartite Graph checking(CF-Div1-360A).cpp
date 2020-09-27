#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

//#define mod 1000000007;

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const int N = 1e5+5;
vector<int>g[N], v(N), color(N), ans[2];

void dfs(int u, int c)                 //if graph is "BIPARTITE" then we divide the graph into 2 sets, else, if we find out that the graph is not bipartite we print '-1' and exit 
{
    if(v[u] == 1)
    {
        if(color[u] != c)
        {
            cout<<-1;
            exit(0);
        }
        return;
    }
    v[u] = 1;
    color[u] = c;
    ans[c].emplace_back(u);
    for(auto i:g[u])
        dfs(i, c^1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    while(m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        if(v[i] == 0)
            dfs(i, 0);
    }
    for(int i=0;i<2;i++)
    {
        cout<<ans[i].size()<<'\n';
        for(auto it:ans[i])
            cout<<it<<' ';
        cout<<'\n';
    }

    return 0;
}