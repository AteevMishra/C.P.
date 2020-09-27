#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

//https://codeforces.com/contest/1395/problem/C
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
const int N = 1e5;
int cache[205][N];
vector<int>a(205), b(205);
int n, m;
 
int dp(int i, int val)
{
    if(i == n)
        return val;
    if(cache[i][val] != -1)
        return cache[i][val];
    int &ans = cache[i][val];
    ans = 1e9;
    int mi = 1e9;
    for(int j=0; j<m; j++)
    {
        ans = min(ans, dp(i+1, a[i]&b[j]|val));
    }
    return ans;
}
 
int main()
{  
   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
 
    memset(cache, -1, sizeof(cache));
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
 
    cout<<dp(0, 0);
 
    return 0;
}