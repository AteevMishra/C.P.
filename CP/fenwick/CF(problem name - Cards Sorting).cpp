#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
 
const int N = 1e5+5;
long long n;
vector<long long>v(N), bit(N);
multiset<long long>s;
set<long long>g[N];
 
void update(long long ind, long long val)
{
    while(ind <=n)
    {
        bit[ind]+=val;
        ind+=ind&(-ind);
    }
}
 
long long preff(long long ind)
{
    long long ans = 0;
    while(ind>0)
    {
        ans+=bit[ind];
        ind-=ind&(-ind);
    }
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        s.insert(v[i]);
        g[v[i]].insert(i);
        update(i, 1);
    }
    long long ans = 0, c = 1;
    while(!s.empty())
    {
        long long val = *s.begin();
        auto er = s.begin();
        auto it = g[val].lower_bound(c);
        if(it == g[val].end())
            it = g[val].begin();
        long long ind = *it;
        if(ind >= c)
            ans+=preff(ind) - preff(c-1);
        else
            ans+=preff(ind) - preff(c-1)+preff(n);
        c = ind;
        update(ind, -1);    
        g[val].erase(ind);
        s.erase(er);
    }
 
    cout<<ans;
 
    return 0;
}