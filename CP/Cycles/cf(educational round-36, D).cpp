//Almost Acyclic Graph
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const int N = 505;
int n, m;
vector<int>g[N];

bool topo(int u)
{
    vector<int>indeg(N), ans;
    for(int i=1;i<=n;i++)
    {
        for(auto it:g[i])
            indeg[it]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(indeg[i] == 0)
            q.push(i);

    while(!q.empty())
    {
        int f = q.front();
        ans.emplace_back(f);
        q.pop();
        for(auto i:g[f])
        {
            indeg[i]--;
            if(indeg[i] == 0)
                q.push(i);
        }
    }

    if(indeg[u] == 1)
    {
        indeg[u]--;
        q.push(u);
    }

    while(!q.empty())
    {
        int f = q.front();
        ans.emplace_back(f);
        q.pop();
        for(auto i:g[f])
        {
            indeg[i]--;
            if(indeg[i] == 0)
                q.push(i);
        }
    }

    return (ans.size() == n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
 
    cin>>n>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        g[a].emplace_back(b);
    }

    for(int i=1;i<=n;i++)
    {
        if(topo(i))
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
 
    return 0;
}