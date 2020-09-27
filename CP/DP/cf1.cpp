#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

//https://codeforces.com/contest/1398/problem/D


 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
 
const int N = 205;
 
long long r[N], b[N], g[N];
long long cache[N][N][N];
long long rr, gg, bb;
 
long long dp(long long ri, long long bi, long long gi)
{
    if( (ri == 0 && bi == 0) || (ri == 0 && gi == 0) || (bi == 0 && gi == 0))
        return 0;
 
    long long &ans = cache[ri][bi][gi];
    if(ans != -1)
        return ans;
 
    if(ri > 0 && bi > 0)
        ans = max(ans, r[ri] * b[bi] + dp(ri-1, bi-1, gi));
    if(ri > 0 && gi > 0)
        ans = max(ans, r[ri] * g[gi] + dp(ri-1, bi, gi-1));
    if(bi > 0 && gi > 0)
        ans = max(ans, b[bi] * g[gi] + dp(ri, bi-1, gi-1));
 
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
 
    memset(cache, -1, sizeof(cache));
    cin>>rr>>gg>>bb;
    for(int i=0;i<rr;i++)
    {
        cin>>r[i];
    }
    for(int i=0;i<gg;i++)
    {
        cin>>g[i];
    }
    for(int i=0;i<bb;i++)
    {
        cin>>b[i];
    }
    sort(r, r + rr + 1);
    sort(b, b + bb + 1);
    sort(g, g + gg + 1);
 
    long long ans = dp(rr, bb, gg);
    cout<<ans;
 
    return 0;
}