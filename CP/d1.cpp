#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<windows.h>
#include<stdio.h>

using namespace std;
/*
int pass(char*p[])
{
	char s[10];
	cout<<"Enter Password- ";
	for(i=0;i<7;i++)
	{
		s=getch();
		cout<<'*';
	}
	if(!strcmp(s,p))
		return 0;
	else
		return 1;
}
*/
char checkh(char a[][3])                                     //FUNCTION to chech rows*******
{
	int f,i,j,k;char t;
	for(i=0;i<3;i++)
	{
            t=a[i][0];
            f=0;
			for(k=0;k<3;k++)
			{
				if(t==a[i][k])
				{
					f++;
				}
				else
					break;
			}
			if(f==3)
				break;
	}
    if(f==3)
    	return t;
    else
    	return 'w';
}


char checkd1(char a[][3])
{
	int i,j,k,f=0;char t=a[0][0];
	for(i=0;i<3;i++)
	{
		if(t==a[i][i])
			f++;
	}
	if(f==3)
		return t;
	else
		return 'w';
}


char checkd2(char a[][3])
{
	int i,j,f=0;char t=a[0][2];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i+j==2)
			{
				if(t==a[i][j])
					f++;
			}
		}
	}
	if(f==3)
		return t;
	else
		return 'w';

}

char checkv(char a[][3])
{
	int f,i,j,k;char t;
	for(i=0;i<3;i++)
	{
            t=a[0][i];
            f=0;
			for(k=0;k<3;k++)
			{
				if(t==a[k][i])
				{
					f++;
				}
				else
					break;
			}
			if(f==3)
				break;
	}
    if(f==3)
    	return t;
    else
    	return 'w';
}


void game()
{
	int pos,pn,ps,i,j,k,num,flag=0;char np1[30],np2[30], a[3][3],c1,c2,c3,c4,opt1;                                 //pn='player no.'   &    ps='player symbol'    &     pos='position at which you want to place'
    cout<<"Enter names- ";
    cout<<"\nPLAYER 1('X') : ";
    cin.getline(np1,30,'.');
    cout<<"\nPLAYER 2('O') : ";
    cin.getline(np2,30,'.');
 do{for(i=0;i<3;i++)
    {
        cout<<setw(50);
      	for(j=0;j<3;j++)
       	{
        	a[i][j]='_';
       		cout<<a[i][j]<<'\t';
       	}
      	cout<<endl;
    }
    for(k=0;k<9;k++)
    {
    	num=0;
    	if(k%2==0)
    	{
    		pn=1;
    		ps='X';
    	}
    	else
    	{
    		pn=2;
    		ps='O';
    	}
    	cout<<"\nPlayer "<<pn<<" enter the position at which you want to enter - ";
     	cin>>pos;
        for(i=0;i<3;i++)
        {
          cout<<setw(50);
      	  for(j=0;j<3;j++)
       	  {
        	num++;
        	if(num==pos)
        		a[i][j]=ps;
       		cout<<a[i][j]<<'\t';
       	  }
      	  cout<<endl;
        }
        c1=checkh(a);
        c2=checkv(a);
        c3=checkd1(a);
        c4=checkd2(a);
       	if(c1!='w'||c2!='w'||c3!='w'||c4!='w')
       	{
       		if(c1=='X'||c2=='X'||c3=='X'||c4=='X')
       		{
       			flag=1;
       			cout<<"\nPlayer 1 "<<np1<<" WINS !!!";
       			break;
       		}
       		else if(c1=='O'||c2=='O'||c3=='O'||c4=='O')
       		{
       			flag=1;
       			cout<<"\nPlayer 2 "<<np2<<" WINS !!!";
       			break;
       		}
       	}
       	
    }  
    if(flag==0)
    	cout<<"\nIt's a TIE !!!!";	
    cout<<setw(50)<<"Do you want to CONTINUE ?";
    cin>>opt1;
    }while(opt1=='Y'||opt1=='y');
}


int main()
{
	int i,j,opt;char ch,w;   //p="@gameon"
 /*	v=pass(p);
	if(v==0)
	{
		cout<<"Access Denied !!!.....Press 'T' to try again or press any key to exit ";
        cin>>w;
		if(w=='T')
		{
			cout<<"\nTry after 10 seconds ";
            Sleep(10000);
            main();
		}
		else
		{
			getch();
			exit(1);
		}

             
	}
	else{*/
		do{ 
	    cout<<"\n``````````````````````````** TIC TAC-TOE **````````````````````````````";
        cout<<"\n1.START\n2.INSTRUCTIONS\n3.EXIT";
        cin>>opt;
        switch(opt)
        {
        	case 1: game();
        	        break;
        	case 3: getch();
        	        exit(0);
        	        break;
        	default:cout<<"\n Wrong Choice !!! ";
        }
        cout<<"\nGo back to main menu ? ";
        cin>>ch;
        }while(ch=='Y'||ch=='y');
//	}
	   
       return 0;
}