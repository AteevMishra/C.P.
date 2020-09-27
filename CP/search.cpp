#include<iostream>

using namespace std;

void merge(int a[],int left,int mid,int right)                                //using MERGE SORT
{
    int n1,n2,i,j,k;
    n1=mid-left+1;
    n2=right-mid;
    int A[n1],B[n2];
    for(i=0;i<n1;i++)
    	A[i]=a[left+i];
    for(j=0;j<n2;j++)
    	B[i]=a[mid+i+1];
    i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
    	if(A[i]<B[j])
    	{
            a[k]=A[i];
            k++;
            i++;
    	}
    	else
    	{
    		a[k]=B[j];
    		k++;
    		j++;
    	}
    }
    if(i==n1)
    {
        while(j<n2)
        {
        	a[k]=B[j];
        	j++;
        	k++;
        }
    }
    else if(j==n2)
    {
    	while(i<n1)
    	{
    		a[k]=A[i];
    		i++;
    		k++;
    	}
    }
}

void merge_sort(int a[],int left,int right)
{
	int mid=(left+right)/2;
	if(right>left)
	{
		merge_sort(a,left,mid);
		merge_sort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}


void bubble_sort(int*,int);

int bin_search(int a[],int n,int num)
{
	int mid,lb=0,ub=n-1;
	while(lb<=ub)
	{
		mid=(lb+ub)/2;
		if(a[mid]==num)
		{
           return mid+1;
		}
		else if(num>a[mid])
		{
			lb=mid+1;
		}
		else
		{
			ub=mid-1;
		}
	}
	return -1;
}

int main()
{
	int a[10],num,n,pos,i,left=0,right;
	cout<<"\nEnter size of array - ";
	cin>>n;
	right=n;
	cout<<"\nEnter array - ";
	for(i=0;i<n;i++)
	cin>>a[i];
    cout<<"\nSorted in ASCENDING - ";
    //bubble_sort(a,n);
    merge_sort(a,left,right);
    for(i=0;i<n;i++)
    	cout<<a[i]<<"\t";
    cout<<"\nEnter the no. you want to search - ";
    cin>>num;
	pos=bin_search(a,n,num);
	if(pos==-1)
		cout<<"\nElement not present !!! ";
	else
		cout<<"\nElement found at position - "<<pos;
}

/*
void bubble_sort(int a[],int n)                        //using BUBBLE
{
	int small,j,i;
	for(i=0;i<n;i++)
	{
		for (int j=0;j<n-1;j++)
		{
			small=a[j];
			if(a[j]>a[j+1])
			{
                 a[j]=a[j+1];
                 a[j+1]=small;
			}
		}
	}
}
*/







