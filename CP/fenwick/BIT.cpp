#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

vector<int>v{0,1, 90, 3, 4};
vector<int>BIT(5);

int pref(int i)
{
    int s = 0;
    while(i > 0 )
    {
        s+=BIT[i];
        i-=i&(-i);
    }
    return s;
}

void update(int i, int val)
{
    while(i<=4)
    {
        BIT[i]+=val;
        i+=i&(-i);
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cout<<"1.update  2.sum";
    for(int i=1;i<=4;i++)
        update(i, v[i]);
    cout<<pref(4);         //index 1....4
    cout<<'\n'<<pref(4)-pref(2); // index 3..4

    return 0;
}