
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stddef.h>

using namespace std;
/*
struct node
{
    int data;
    node*next,*pre;
};
node*h,*n,*t,*p;

void addn();
void del();
void lis();
void lisr();
void lisf();
void addbeg();
void adde();
void adda();
void addb();

int main()
{
    int opt;char choice;
    do
    {
        cout<<"*-*-*-*-*-*-*-***MENU***-*-*-*-*-*-*-*-*";
        cout<<"\n1.Add\n2.Delete\n3.List\nEnter option- ";
        cin>>opt;
        switch(opt)
        {
            case 1: addn();
                    break;
            case 2: del();
                    break;
            case 3: lis();
                    break;
            default:cout<<"you gave wrong choice !!!";
                    break;
        }
        cout<<"\nDo you want to continue ?";
        cin>>choice;
    }while(choice=='Y'||choice=='y');
    return 0;
}

void addn()
{
    int opt1;
    if(h==NULL)
    {
        n=new node;
        if(n==NULL)
        {
          cerr<<"No memory !!!";
          getch();
          exit(1);
        }
        cout<<"Enter info- ";
        cin>>n->data;
        n->next=NULL;
        n->pre=NULL;
        h=n;
        t=n;
    }
    else
    {
        cout<<"1.Add at the beginning\n2.Add at the end\n3.Add after \n4.Add before";
        cin>>opt1;
        switch(opt1)
        {
            case 1:addbeg();
                   break;
            case 2:adde();
                   break;
            case 3:adda();
                   break;
            case 4:addb();
                   break;
            default:cout<<"Wrong choice !!!";
                    break;
        }
    }
}

void addbeg()
{
    n=new node;
    cout<<"Enter info- ";
    cin>>n->data;
    n->next=h;
    n->pre=NULL;
    h->pre=n;
    h=n;
}

void adde()
{
    n=new node;
    cout<<"Enter info- ";
    cin>>n->data;
    t->next=n;
    n->next=NULL;
    n->pre=t;
    t=n;
}

void adda()
{
    int var;
    cout<<"Enter value after which you want to add node- ";
    cin>>var;
    n=h;
    while(n!=NULL)
    {
        if(n->data==var)
        {
            p=new node;
            cout<<"Enter info- ";
            cin>>p->data;
            p->next=n->next;
            n->next->pre=p;
            p->pre=n;
            n->next=p;
            break;
        }
        n=n->next;
    }
}

void addb()
{
    int var;
    cout<<"Enter value before which you want to add node- ";
    cin>>var;
    n=h;
    while(n!=NULL)
    {
        if(n->next->data==var)
        {
            p=new node;
            cout<<"Enter info - ";
            cin>>p->data;
            p->next=n->next;
            n->next->pre=p;
            p->pre=n;
            n->next=p;
            break;
        }
        n=n->next;
    }
}

void lis()
{
    int opt2;
    cout<<"1.List to right\n2.List to left\nEnter option- ";
    cin>>opt2;
    switch(opt2)
    {
        case 1: lisr();
                break;
        case 2: lisf();
                break;
        default:cout<<"Wrong choice !!!";
                break;
    }
}
void lisr()
{
    n=h;
    if(h==NULL)
    {
        cerr<<"The list is empty !!! ";
        getch();
        exit(1);
    }
    while(n!=NULL)
    {
        cout<<n->data<<"\t";
        n=n->next;
    }
}

void lisf()
{
    n=t;
    if(h==NULL)
    {
        cerr<<"The list is empty !!! ";
        getch();
        exit(1);
    }
    while(n!=NULL)
    {
        cout<<n->data<<"\t";
        n=n->pre;
    }
}
void del()
{
    int opt2;
    cout<<"\n1.Delete at the beginning\n2.Delete at the end\n3.Delete after a node\n4.Delete before a node ";
    cout<<"Enter your choice - ";
    cin>>opt2;
    switch(opt2)
    {
        case 1:delbeg();
               break;
        case 1:dele();
               break;
        case 1:dela();
               break;
        case 1:delb();
               break;
        default:cout<<"\nWrong choice !!! ";
                break;
    }
}
void delbeg()
{
    if (h==NULL)
    {
        cerr<<"list is empty !!! ";
        getch();
        exit(1);
    }
}
*/
int main()
{
    int n1=1,i,n2=0,t,n;
    cout<<"\nEnter no. of terms - ";
    cin>>n;
    cout<<n2<<' ';
    for(i=0;i<n-1;i++)
    {
        cout<<n1<<' ';
        n2=n1+n2;
        t=n1;
        n1=n2;
        n2=t;

    }
    return 0;
}
