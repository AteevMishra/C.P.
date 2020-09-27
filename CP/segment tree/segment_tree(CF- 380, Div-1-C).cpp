#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const int N = 1e6+5;
int n;
string s;

struct data
{
    int open = 0, close = 0, len = 0;

    void merge(data a, data b)
    {
        int tot = min(a.open, b.close);
        open = a.open + b.open - tot;
        close = a.close + b.close - tot;
        len = 2*tot + a.len + b.len;
    }
};

data seg[4*N], zero;

void build(int ind, int l, int r)
{
    if(l == r)
    {
        if(s[l] == '(')
            seg[ind].open = 1;
        else
            seg[ind].close = 1;
        return;
    }
    int mid = (l+r)>>1;
    build(2*ind+1, l, mid);
    build(2*ind+2, mid+1, r);
    seg[ind].merge(seg[2*ind+1], seg[2*ind+2]);
}

data query(int ind, int low, int high, int l, int r)
{
    if(low > r || high <l)
    {
        return zero;
    }
    else if(low >= l && high<=r)
        return seg[ind];

    int mid = (low + high)>>1;
    data a = query(2*ind+1, low, mid, l, r);
    data b = query(2*ind+2, mid+1, high, l, r);
    data ans;
    ans.merge(a, b);
    return ans;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    n = s.size();
    int m;
    cin>>m;
    build(0, 0, n-1);
    while(m--)
    {
        int l, r;
        cin>>l>>r;
        l--, r--;
        data ans = query(0, 0, n-1, l, r);
        cout<<ans.len<<'\n';
    }

    return 0;
}