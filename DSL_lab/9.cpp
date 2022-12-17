/*In any language program mostly syntax error occurs due to unbalancing delimiter such as (), {}, [].
 Write C++ program using stack to check whether given expression is well parenthesized or not. */
#include <iostream>
#include<string>
using namespace std;
class Node
{
    public:
    char data;
    Node* next;
    Node* prev;
};
Node* last; 
void pop(Node *n)
{
    n->prev->next=NULL;
    last=n->prev;
    delete n;
}
void push(Node *n,char push_char)
{
    Node *top=new Node();
    top->next=NULL;
    top->prev=n;
    cout<<push_char<<" pushed"<<endl;
    top->data=push_char;        
    last=top;
}
int isempty( Node *n)
{
    if(n->next==NULL and n->prev==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    string num;
    cout<<"Enter String"<<endl;
    getline(cin,num);
    int leng=num.length();
    Node *p,*q;
    p=new Node();
    p->next=p->prev=NULL;
    last=p;
    for(int i=0;i<leng;i++)
    {
        if(num[i]=='{' or num[i]=='(' or num[i]=='[')
        {
            push(last,num[i]);
        }
        else if(num[i]=='}' or num[i]==')' or num[i]==']')
        {
            int emp=isempty(last);
            if(emp==1)
            {
                cout<<"Wrong"<<endl;
                return 0;
            }
            else
            {
            pop(last);
            cout<<num[i]<<" popped"<<endl;
            }
        }
    }
    int empty=isempty(last);
    if(empty==1)
    {
        cout<<"Perfect"<<endl;
    }
    else
    {
        cout<<"Wrong"<<endl;
    }
    return 0;
}

