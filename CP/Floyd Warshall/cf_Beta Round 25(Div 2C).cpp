
//Roads in Berland.............................

#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

const int N= 305;
long long a, b, c;
vector< vector<long long> >dis(N, vector<long long>(N, 0));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>dis[i][j];
    }

    cin>>k;
    while(k--)
    {
        cin>>a>>b>>c;
        long long ans = 0;
        if(c >= dis[a][b])
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][a] + dis[b][j] + c);
                dis[i][j] = min(dis[i][j], dis[i][b] + dis[a][j] + c);
                ans+=dis[i][j];
            }
        }
        cout<<ans/2<<' ';
    }

    return 0;
}