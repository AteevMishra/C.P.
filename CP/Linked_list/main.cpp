/*
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stddef.h>

using namespace std;

struct node
{
    int data;
    node*next;
};
node*h,*n,*t,*p;

void addn();
void deln();
void listn();
void addbeg();
void adde();
void addm();
void adda();
void addb();

int main()
{
    int opt;char choice;
    do{
        cout<<"\n*-*-*-*-*-*-*-*-*-*-*-*-*-*MENU*-*-*-*-*-*-*-*-*-*-***--*-*-**-*-*-*";
        cout<<"\n1.Add \n2.List \n3.Delete ";
        cout<<"\nEnter your choice - ";
        cin>>opt;
        switch(opt)
        {
            case 1: addn();
                    break;
            case 2: listn();
                    break;
            default: cout<<"\nWrong choice !!!";
                     break;
        }
        cout<<"Do you want to continue ?";
        cin>>choice;
    }
    while(choice=='y'||choice=='Y');
        return 0;
}

void addn()
{
    int op1;
    if(h==NULL){
    n=new node;
    if(n==NULL)
    {
        cerr<<"Not enough memory !!!";
        getch();
        exit(1);
    }
    cout<<"\nEnter info - ";
    cin>>n->data;
    n->next=NULL;
    h=n;
    t=n;
    }
    else
    {
        cout<<"\nChoose an option - \n1.Add mid \n2.Add at the beginning \n3.Add at the end";
        cin>>op1;
        switch(op1)
        {
            case 1: addm();
                    break;
            case 2: addbeg();
                    break;
            case 3: adde();
                    break;
            default:cout<<"\nWrong choice !!!";
                    break;
        }
    }
}

void addbeg()
{
    n=new node;
    if(n==NULL)
    {
        cerr<<"\nNot enough memory !!!";
        getch();
        exit(1);
    }
    cout<<"\nEnter info - ";
    cin>>n->data;
    n->next=h;
    h=n;
}

void adde()
{
    n=new node;
    if(n==NULL)
    {
        cerr<<"\nNot enough memory !!!";
        getch();
        exit(1);
    }
    cout<<"\nEnter info - ";
    cin>>n->data;
    n->next=NULL;
    t->next=n;
    t=n;
}

void addm()
{
    int opp;
    cout<<"\n1.Add after a given node \n2.Add before a given node ";
    cin>>opp;
    switch(opp)
    {
        case 1:adda();
               break;
        case 2:addb();
               break;
        default:cout<<"\nWrong choice !!!";
                break;
    }
}

void adda()
{
    int var,flag=0;
    n=h;
    cout<<"\nEnter value after which you want to add ";
    cin>>var;
    while(n!=NULL)
    {
        if(n->data==var)
        { p=new node;
          if(p==NULL)
          {
            cout<<"\nNot enough memory !!!";
            getch();
            exit(1);
          }
          flag=1;
          cout<<"\nEnter information - ";
          cin>>p->data;
          p->next=n->next;
          n->next=p;
          break;
        }
        n=n->next;
    }
    if(flag==0)
    {
        cout<<"\nNode not found";
        getch();
        exit(1);
    }
}

void addb()
{
    int var,flag=0;
    n=h;
    cout<<"\nEnter value before which you want to add ";
    cin>>var;
    while(n!=NULL)
    {
        if(n->next->data==var)
        { p=new node;
          if(p==NULL)
          {
            cout<<"\nNot enough memory !!!";
            getch();
            exit(1);
          }
          flag=1;
          cout<<"\nEnter information - ";
          cin>>p->data;
          p->next=n->next;
          n->next=p;
          break;
        }
        n=n->next;
    }
    if(flag==0)
    {
        cout<<"\nNode not found";
        getch();
        exit(1);
    }
}

void listn()
{
    n=h;
    if(n==NULL)
    {
        cerr<<"\nThe list is empty !!!";
        getch();
        exit(1);
    }
    else
    {
        while(n!=NULL)
        {
            cout<<n->data<<"\t";
            n=n->next;
        }
    }
}
/*
void deln()
{
    int var;
    cout<<"\nEnter the the node you want to delete ?";
    cin>>var;
    n=h;
    while(n!=NULL)
    {

    }
}
*/
