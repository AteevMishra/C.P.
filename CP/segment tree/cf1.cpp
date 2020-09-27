//Xenia and Bit Operations ******************************************************

/*
useful stl
array<ll,size> ar;         //size(),front(),back(),fill(),empty()
deque<ll> d                //push_back(),push_front(),pop_front(),pop_back()
vector<ll> v(size,val);    //push_back(),*max_element(v.begin(),v.end()),accumulate(v.begin(),v.end(),0),pop_back()
stack<ll> g;               //push(),pop(),top(),size(),empty()         LIFO
queue<ll> q;               //push(),size(),front(),back(),empty()      FIFO
priority_queue<ll> pq
*/

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const long long N = (1LL<<17)+5;
vector<long long>v(N), seg(4*N);
long long n, m, nn;

void build(long long ind, long long l, long long r, long long parity)
{
    if(l == r)
    {
        seg[ind] = v[l];
        return;
    }
    long long mid = l + (r-l)/2LL;
    build(2*ind+1, l, mid, parity^1);
    build(2*ind+2, mid+1, r, parity^1);
    if(parity)
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
}

void query(long long p, long long b, long long ind, long long l, long long r, long long parity)
{
    if(l == r)
    {
        seg[ind] = b;
        return;
    }

    long long mid = l + (r-l)/2LL;
    if(p <= mid)
        query(p, b, 2*ind+1, l, mid, parity^1);
    else
        query(p, b, 2*ind+2, mid+1, r, parity^1);
    
    if(parity)
        seg[ind] = seg[2*ind+1] | seg[2*ind+2];
    else
        seg[ind] = seg[2*ind+1] ^ seg[2*ind+2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   

    cin>>n>>m;
    nn = 1LL<<n;
    for(long long i=0;i< nn; i++)
    {
        cin>>v[i];
    }
    build(0, 0, nn-1, n&1);

    while(m--)
    {
        long long p, b;
        cin>>p>>b;
        --p;
        query(p, b, 0, 0, nn-1, n&1);
        cout<<seg[0]<<'\n';
    }

    return 0;
}