#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const int N = 1e5+5;
int lg = 20, n;
vector<int>v(N), p(N);

vector< vector<int> > spt(20, vector<int>(N, 0));

void build()                                        //O(NlogN)
{
    for(int i=0; i<n; i++)
        spt[0][i] = v[i];

    p[0] = p[1] = 0;
    for(int i=2;i<N;i++)
        p[i] = 1 + p[i/2];

    for(int i = 1; i<lg; i++)
    {
        for(int j = 0; j<= n - (1<<i) + 1; j++)
        {
            spt[i][j] = min(spt[i-1][j], spt[i-1][ j + (1<<(i-1))]);
        }
    }
}

int getmin(int l, int r)                             //O(1)
{
   int k = p[r-l+1];
   return min(spt[k][l], spt[k][r - (1<<k)+1]); 
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);  

    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];

    build();
    int l, r;
    cout<<"\nEnter range - ";
    cin>>l>>r;
    cout<<getmin(l, r);
 
    return 0;
}