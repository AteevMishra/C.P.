#include<iostream>
#include<stdlib.h>
#include<stddef.h>
#include<conio.h>

using namespace std;
/*
//1.static imp
class stack
{
    int stk[5],top;
    public:
        stack()
        {
            top=-1;
        }
        void push(int);
        void pop();
        void lists();
};

void stack::push(int item)
{
    if(top==4)
    {
        cout<<"\nOverflow in stack !!!";
        getch();
        return;
    }
    else
    {
        top++;
        stk[top]=item;
        cout<<"\nItem pushed !!!";
    }
}

void stack::pop()
{
    if(top==-1)
    {
        cout<<"\nUnderflow in stack !!!";
        getch();
        return;
    }
    else
    {
        cout<<"The item popped is - "<<stk[top];
        top--;
    }
}

void stack::lists()
{
    int i;
    if(top==-1)
    {
        cout<<"\nUnderflow in stack....hence no list !!!";
        getch();
        return;
    }
    cout<<"\nThe list is - ";
    for(i=top;i>=0;i--)
    {
        cout<<stk[i]<<"\t";
    }
}

int main()
{
    int item,n;
    stack s;
    char choice;
    do
    {
        cout<<"*-*--*-*-*-***-*-*-*-*-*-*-MENU--*-****-*-*****-**-*-**-*--*-*-*-*-";
        cout<<"\n1.Push \n2.Pop \n3.List ";
        cout<<"\nEnter your choice - ";
        cin>>n;
        switch(n)
        {
            case 1: cout<<"\nEnter the data - ";
                    cin>>item;
                    s.push(item);
                    break;
            case 2: s.pop();
                    break;
            case 3: s.lists();
                    break;
            default:cout<<"\nWrong choice !!!";
                    break;
        }
        cout<<"\nDo you want to continue ? ";
        cin>>choice;
    }
    while(choice=='y'||choice=='Y');
    return 0;
}
*/

//2.dynamic implementation

struct node
{
    node*next;
    int data;
};
node*n;

class stack
{
    node*top;
    public:
        stack()
        {
            top=NULL;
        }
        void push(int);
        void pop();
        void lists();
};

int main()
{
    stack s;int opt,item;char ch;
    do{
        cout<<"*-*--*--*-*-*-*--*MENU*-*-*-*-*-*-*-*--*--*--*-*-*-";
        cout<<"\n1.PUSH \n2.POP \n3.LIST\n Enter your choice - ";
        cin>>opt;
        switch(opt)
        {
        case 1: cout<<"\nenter the item to be pushed ";
                cin>>item;
                s.push(item);
                break;
        case 2: s.pop();
                break;
        case 3: s.lists();
                break;
        default:cout<<"\nwrong choice ";
                break;
        }
        cout<<"\nDo you want to continue ? ";
        cin>>ch;
    }while(ch=='Y'||ch=='y');
    return 0;
}

void stack::push(int item)
{
    n=new node;
    if(n==NULL)
    {
        cout<<"\nmemory not available !!!";
        getch();
        return;
    }
    n->data=item;
    if(top==NULL)
    {
        n->next=NULL;
        top=n;
    }
    else
    {
        n->next=top;
        top=n;
    }
    cout<<"\nItem pushed !!! ";
}

void stack::pop()
{
    if(top==NULL)
    {
        cout<<"\nUnderflow in stack ";
        getch();
        return;
    }
    else
    {
        n=top;
        top=top->next;
        cout<<"\n Item popped is - "<<n->data;
        n->next=NULL;
    }
}

void stack::lists()
{   n=top;
    if(n==NULL)
    {
        cout<<"\nUnderflow in stack !!! ";
    }
    while(n!=NULL)
    {
        cout<<n->data<<"\t";
        n=n->next;
    }
}
