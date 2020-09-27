#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const int N = 1e5+5;
int lg = 19, n, m;;
vector<int>g[N];
vector<int>level(N);
vector< vector<int> >p(19, vector<int>(N, 0));

void dfs(int u, int par, int lvl)
{
    p[0][u] = par;
    level[u] = lvl;
    for(auto i:g[u])
    {
        if(i == par)
            continue;
        dfs(i, u, lvl+1);
    };
}

void precompute()
{
    for(int i=1;i<=lg;i++)
    {
        for(int j=1;j<=n;j++)
            if(p[i-1][j])
                p[i][j] = p[i-1][p[i-1][j]];
    }
}

int lca(int a, int b)
{
    if(level[a] < level[b])
        swap(a, b);

    int diff = level[a] - level[b];
    for(int i=lg-1; i>=0;i--)
        if(diff & (1<<i))
        {
            a = p[i][a];
            cout<<a<<' ';
        }
    cout<<'t';
    if(a == b)
        return a;
    for(int i = lg-1;i>=0;i--)
    {
        if(p[i][a] && p[i][a] != p[i][b])
        {
            a = p[i][a];
            cout<<a<<' ';
            b = p[i][b];
        }
    }
    return p[0][a];
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1, 0, 0);
    precompute();
    int a, b;
    cin>>a>>b;
    int ans = lca(a, b);
    cout<<ans;
    
    return 0; 
} 