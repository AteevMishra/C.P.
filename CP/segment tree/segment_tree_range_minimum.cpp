#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cout<<"Enter size of array - ";
	cin>>n;
	cout<<"Enter array - ";
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<int>sgt(2*n);  

	for(int i=0;i<n;i++)                 //Build START 
		sgt[i+n] = a[i];
	cout<<'\n';
	for(auto x:sgt)
		cout<<x<<' ';

	for(int i=n-1;i>0;i--)
	{
		sgt[i]=min(sgt[2*i],sgt[2*i+1]);
	}                                   //Build END

	cout<<'\n';
	for(auto x:sgt)
		cout<<x<<' ';

	return 0;
}