#include<bits/stdc++.h>

using namespace std;

void sum(int a,int b,int n,vector<int>&sgt)
{
	int s=0;
	for(a+=n,b+=n;a<b;a>>=1,b>>=1)
	{
		if(a&1)
			s+=sgt[a++];
		if(b&1)
			s+=sgt[--b];
	}
	cout<<s<<'\n';
}

/*
void update(int p, int value)  
{  
    // set value at position p 
    tree[p+n] = value; 
    p = p+n; 
      
    // move upward and update parents 
    for (int i=p; i > 1; i >>= 1) 
        tree[i>>1] = tree[i] + tree[i^1]; 
} 
*/
int main()
{
	int n,a,b;
	cout<<"\nEnter size of array - ";
	cin>>n;
	vector<int>v(n),sgt(2*n);
	for(int i=0;i<n;i++)
		cin>>v[i];

	for(int i=0;i<n;i++)
		sgt[n+i] = v[i];
	for(int i=n-1;i>0;i--)
		sgt[i] = sgt[2*i] + sgt[2*i+1];

	cout<<"\nGive the positions - ";	
	cin>>a>>b;
	sum(a-1,b,n,sgt);
}