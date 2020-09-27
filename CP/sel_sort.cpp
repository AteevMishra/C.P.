#include<iostream>

using namespace std;

int main()
{
	int a[5],i,j,small,pos,temp,l;
	cout<<"\nEnter array- ";
	for(i=0;i<5;i++)
	cin>>a[i];
   //INSERTION SORT
    for(i=1;i<=4;i++)
    {
    	temp=a[i];
    	j=i-1;
    	while((j>=0)&&(a[j]>temp))
    	{
    		a[j+1]=a[j];
    		j--;
    	}
    	a[j+1]=temp;
    }
   
   /*BUBBLE SORT
  for(i=0;i<4;i++)
    {
    	for(j=0;j<4;j++)
    	{
    		temp=a[j+1];
            if(a[j+1]<a[j])
    		{
    			a[j+1]=a[j];
    			a[j]=temp;
    		}
    	}
    }
   
   //** SELECTION SORT
 /* cout<<"\nSorted array(ascending)-  ";
    for(i=0;i<5;i++)
    {
    	small=a[i];pos=i;
    	for(j=i+1;j<5;j++)
    	{
    		if(a[j]<small)
    		{
    			small=a[j];
    		    pos=j;
    		}
    	}
    	a[pos]=a[i];
    	a[i]=small;

    }
    for(i=0;i<5;i++)
    	cout<<a[i]<<'\t';
    
    cout<<"\nSorted array(descending)-  ";
    for(i=0;i<5;i++)
    {
    	l=a[i];pos=i;
    	for(j=i+1;j<5;j++)
    	{
    		if(a[j]>l)
    		{
    			l=a[j];
    		    pos=j;
    		}
    	}
    	a[pos]=a[i];
    	a[i]=l;

    } */

    for(i=0;i<5;i++)
    	cout<<a[i]<<'\t';
    return 0;
}