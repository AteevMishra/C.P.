#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<stddef.h>

using namespace std;

//static implementation
/*
class queue
{
    int qu[5],f,r;
public:
    queue()
    {
        f=r=-1;
    }
    void ins(int);
    void rem();
    void lists();
};

int main()
{
    int item,opt;char ch;queue q;
    do
    {
        cout<<"**-*--------*MENU*----------*-**";
        cout<<"\n1.Insert\n2.Delete\n3.List\nEnter your choice - ";
        cin>>opt;
        switch(opt)
        {
            case 1: cout<<"\nEnter item to be inserted - ";
                    cin>>item;
                    q.ins(item);
                    break;
            case 2: q.rem();
                    break;
            case 3: q.lists();
                    break;
            default:cout<<"\nWrong choice !!!";
                    break;
        }
        cout<<"Do you want to continue ? ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}

void queue::ins(int item)
{
    if(r==4)
    {
        cout<<"\nOverflow in queue !!! ";
        getch();
        return;
    }
    else
    {
        r++;
        qu[r]=item;
        cout<<"\nItem inserted ! ";
    }
    f=0;
}

void queue::rem()
{
    if(r==-1)
    {
        cout<<"\nUnderflow in queue !!! ";
        getch();
        return;
    }
    cout<<"\nItem deleted is - "<<qu[f];
    f++;
    if(f>r)
        f=r=-1;
}

void queue::lists()
{
    int i;
    if(r==-1)
    {
        cout<<"\nUnderflow in Queue !!! ";
        getch();
        return;
    }
    for(i=f;i<=r;i++)
    {
        cout<<qu[i]<<"\t";
    }
}
*/
//dynamic imp
struct node
{
    node*next;
    int data;
};
node*n;

class queue
{
    node*f,*r;
public:
    queue()
    {
        f=r=NULL;
    }
    void ins(int);
    void rem();
    void lists();
};

int main()
{
    int item,opt;char ch;queue q;
    do
    {
        cout<<"**-*--------*MENU*----------*-**";
        cout<<"\n1.Insert\n2.Remove\n3.List\nEnter your choice - ";
        cin>>opt;
        switch(opt)
        {
            case 1: cout<<"\nEnter item to be inserted - ";
                    cin>>item;
                    q.ins(item);
                    break;
            case 2: q.rem();
                    break;
            case 3: q.lists();
                    break;
            default:cout<<"\nWrong choice !!!";
                    break;
        }
        cout<<"Do you want to continue ? ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}

void queue::ins(int it)
{
    n=new node;
    n->data=it;
    n->next=NULL;
    if(f==NULL)
    {
        f=n;
        r=n;
    }
    else
    {
        r->next=n;
        r=n;
    }
    cout<<"\nItem pushed ! ";
}

void queue::rem()
{
    if(r==NULL)
    {
        cout<<"\nunderflow in queue !!! ";
        getch();
        return;
    }
    cout<<"\nThe item removed is - "<<f->data;
    n=f->next;
    f->next=NULL;
    delete f;
    f=n;
}

void queue::lists()
{
    if(r==NULL)
    {
        cout<<"\nunderflow in queue !!! ";
        getch();
        return;
    }
    n=f;
    while(n!=NULL)
    {
        cout<<n->data<<"\t";
        n=n->next;
    }
}

