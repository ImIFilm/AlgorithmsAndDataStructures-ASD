#include <iostream>
using namespace std;
const int N=15;

struct node
{
    int val;
    node *next;
};

void CreateList(node *&f, int tab[N])
{
    f=new node;
    node *l=f;
    l->val=tab[0];
    l->next=NULL;
    node *k;
    for (int i=1; i<N; i++)
    {
        k=new node;
        l->next=k;
        k->val=tab[i];
        l=k;
    }
    l->next=NULL;
}

void ShowlList (node *f)
{
    while (f!=NULL)
    {
        cout<<f->val<<endl;
        f=f->next;
    }
}

/*Splits list to two lists - with even and odd numbers*/
void TwoListSplit (node *&f, node *&p, node *&n)
{
    if (f==NULL) return;
    //warder
    node *k=new node;
    k->next=f;
    f=k;
    //create warders to odd & even lists
    node *w1=new node;
    w1->next=NULL;
    p=w1;
    node *w2=new node;
    w2->next=NULL;
    n=w2;
    //create extra pointers to odd & even lists
    node *parz=p;
    node *niep=n;
    //pointeres to basic table
    node *q;
    node *r;
    q=f;
    r=f->next;
    while (r!=NULL)
    {
        q->next=r->next;
        //even
        if ((r->val)%2==0)
        {
            parz->next=r;
            r->next=NULL;
            parz=r;
        }
        /odd
        else
        {
            niep->next=r;
            r->next=NULL;
            niep=r;
        }
        r=q->next;
    }
    //deleting warders
    k=p;
    p=p->next;
    delete k;
    k=n;
    n=n->next;
    delete k;
    cout<<"even"<<endl;
    ShowList(p);
    cout<<"odd"<<endl;
    ShowList(n);
}


int main()
{
    node *f;
    node *p; //even
    node *n;  //odd
    int tab[N]= {2, 3, 4, 8, 9, 11, 13, 22, 17, 20, 21, 22, 23, 28, 29};
    CreateList(f, tab);
    cout<<"at the beginning:"<<endl;
    ShowList (f);

    TwoListSplit (f, p, n);
}

