//https://codeforces.com/contest/25/problem/dsu
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const int N = 1005;
int n; 

struct dsu
{
    int link[N], sz[N];

    dsu()
    {
        for(int i=1;i<=n;i++)
        {
            link[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x)
    {
        while(x != link[x])
        {
            x = link[x];
        }
        return x;
    }   

    void unite(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);

        if(pa == pb)
            return;

        if(sz[pa] < sz[pb])
            swap(pa, pb);
        sz[pa]+=sz[pb];
        sz[pb] = 0;
        link[pb] = link[pa];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    dsu uf;
    vector< pair<int, int> >rem;
    vector<int>place;
    for(int i=0;i<n-1;i++)
    {
        int a, b;
        cin>>a>>b;
        if(uf.find(a) == uf.find(b))
            rem.push_back({a, b});
        else
            uf.unite(a, b);
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(i == uf.find(i))
        {
            ans++;
            place.emplace_back(i);
        }
    }
        cout<<ans-1<<'\n';

    for(int i=0;i<ans-1;i++)
        cout<<rem[i].first<<' '<<rem[i].second<<' '<<place[i]<<' '<<place[i+1]<<'\n';

    return 0;
}