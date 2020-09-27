#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
//1.
/*
int fact(int);
int main()
{
    int a,b;
    cout<<"\nEnter a no. - ";
    cin>>a;
    b=fact(a);
    cout<<b;
    return 0;
}

int fact(int a)
{
    if(a==0)
        return 1;
    else8
        return a*fact(a-1);
}
*/
//STL
//1.vectors
bool func(int a,int b)
{
    return(a>b);
}
int main()
{
    vector<int>a={34,8,65,0,1};
    a.push_back(12);
    a.push_back(23);
    a.push_back(44);
    sort(a.begin(),a.end(),func);
    for(int x:a)
    {
        cout<<x<<" ";
    }
    auto it=lower_bound(a.begin(),a.end(),12);
    vector<int>::iterator it2;
    it2=upper_bound(a.begin(),a.end(),34);
    cout<<endl<<it2-it;
    return 0;
}
/*
//2.sets
int main()
{
    set<int>s;
    s.insert(89);
    s.insert(22);
    s.insert(4);
    s.insert(198);
    s.insert(3449);
    for(int x:s)
        cout<<x<<" ";
    auto it=s.upper_bound(3449);
    cout<<endl<<*it;
    return 0;
}

*/
