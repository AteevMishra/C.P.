#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const int N = 1e5+5;
set<int>g[N];
vector<int>subtree(N);
vector<char>ans(N);
int nodes;

void dfs(int u, int par)
{
    nodes++;
    subtree[u] = 1;
    for(auto i:g[u])
    {
        if(i == par)
            continue;
        dfs(i, u);
        subtree[u]+=subtree[i];
    }
}

int centroid(int u, int par)
{
    for(auto i:g[u])
    {
        if(i == par)
            continue;
        if(subtree[i] > (nodes>>1))
            return centroid(i, u);
    }
    return u;
}

void decomposition(int u, char ch)
{
    nodes = 0;
    dfs(u, u);
    int node = centroid(u, u);
    ans[node] = ch;
    for(auto i:g[node])
    {
        g[i].erase(node);
        decomposition(i, ch+1);
    }
}

int main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n;
    m = n-1;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].insert(b);
        g[b].insert(a);
    }

    decomposition(1, 'A');
    cout<<'\n';
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    return 0;
}