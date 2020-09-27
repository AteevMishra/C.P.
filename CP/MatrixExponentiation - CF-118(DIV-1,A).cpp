#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

//#define mod 1000000007;

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const long long mod = 1e9+7;

void mul(long long arr[2][2], long long a[2][2])
{
    long long c[2][2];
    memset(c, 0, sizeof(c));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                c[i][j]+= arr[i][k]*a[k][j];
                c[i][j]%=mod;
            }
        }
    }
    
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            arr[i][j] = c[i][j];
    }
}

void matrixexpo(long long arr[2][2], long long y)
{
    long long ans[2][2] = { {1,0}, {0, 1} };
    while(y)
    {
        if(y&1)
           mul(ans, arr);
        y/=2;
        mul(arr, arr);
    }

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            arr[i][j] = ans[i][j];
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    long long n;
    cin>>n;
    long long spm[2][2] = { {3, 1}, {1, 3}};   // spm = special matrix :)
    matrixexpo(spm, n);  
    cout<<spm[0][0];             

    return 0;
}