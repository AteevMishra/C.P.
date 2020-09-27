#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
//#define mod 1000000007;
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
const int N = 2e5+5;
int lg = 19, n;
vector< pair<int, int> >g[N], mst[N];
 
vector<long long>uu(N), vv(N), uvw(N), dist(N, 1e18), parent(N), level(N);
vector<bool>vis(N);
vector< vector<long long> >p(19, vector<long long>(N, 0)), mw(19, vector<long long>(N, 0));
 
 
long long prims(int src)                     //Creation of MST
{
    //priority_queue<pair<long long,long long> , vector<pair<long long, long long> >, greater<pair<long long, long long> > >q;
    //q.push({0, src});
    set< pair<long long, long long> >s;
    s.insert({0, src});
    dist[src] = 0;
    long long cost = 0;
    while(!s.empty())
    {
        //auto u = q.top();
        //q.pop();
        auto u = *(s.begin());
        s.erase(u);
        vis[u.second] = 1;
        cost+= u.first;
        mst[u.second].push_back({parent[u.second], u.first});
        mst[parent[u.second]].push_back({u.second, u.first});
        for(auto i:g[u.second])
        {
            if(vis[i.first])
                continue;
            if(dist[i.first] > i.second)
            {
                s.erase({dist[i.first], i.first});
                dist[i.first] = i.second;
                parent[i.first] = u.second;
                //q.push({dist[i.first], i.first});
                s.insert({dist[i.first], i.first});
            }
        }
    }
    return cost;
}
 
void dfs(int u, int par, int lvl, int w)
{
    level[u] = lvl;
    p[0][u] = par;
    mw[0][u] = w;
    for(auto i:mst[u])
    {
        if(i.first == par)
            continue;
        dfs(i.first, u, lvl + 1, i.second);
    }
}
 
void precompute()
{
    for(int i=1;i<lg;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[i][j] = p[i-1][p[i-1][j]];
            mw[i][j] = max(mw[i-1][p[i-1][j]], mw[i-1][j]);
        }
    }
}
 
long long lca(int a, int b)
{
    if(level[a] < level[b])
        swap(a, b);
 
    long long diff = level[a] - level[b], ans = 0;
    for(int i=lg-1;i>=0;i--)
    {
        if(diff & (1<<i))
        {
            ans = max(ans, mw[i][a]);
            a = p[i][a];
        }
    }
 
    if(a == b)
        return ans;
 
    for(int i = lg-1;i>=0;i--)
    {
        if(p[i][a] && p[i][a] != p[i][b])
        {
            ans = max(ans, mw[i][a]);
            ans = max(ans, mw[i][b]);
            a = p[i][a];
            b = p[i][b];
        }
    }
    return max({ ans, mw[0][a], mw[0][b]});
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        uu[i] = a, vv[i] = b, uvw[i] = w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
 
    long long ans = prims(1);
    
    dfs(1, 0, 0, 0);
    precompute();
 
    for(int i=1;i<=m;i++)
    {
        long long rem = lca(uu[i], vv[i]);
        cout<<ans - rem + uvw[i]<<'\n';
    }
 
    return 0;
}