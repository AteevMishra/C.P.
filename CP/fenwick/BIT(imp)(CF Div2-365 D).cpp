#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const long long N = 1e6+6;
vector<long long>v(N), pref(N), ans(N), bit(N), l(N), r(N), q[N];

long long prefsum(long long ind)
{
    long long ans = 0;
    while(ind>0)
    {
        ans ^=bit[ind];
        ind -=ind&(-ind);
    }
    return ans;
}

void update(long long ind, long long val)
{
    while(ind<N)
    {
        bit[ind] ^= val;
        ind += ind&(-ind);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        pref[i] = v[i]^pref[i-1];
    }

    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>l[i]>>r[i];
        q[r[i]].emplace_back(i);
        ans[i] = pref[r[i]] ^ pref[l[i]-1];
    }
    map<long long, long long>mp;
    for(int i=1;i<=n;i++)
    {
        if(mp[v[i]]!= 0)
        {
            update(mp[v[i]], v[i]);
        }
        mp[v[i]] = i;
        update(i, v[i]);
        for(auto it:q[i])
        {
            ans[it]^=prefsum(i) ^ prefsum(l[it]-1);
        }
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<'\n';
    
    return 0;
}