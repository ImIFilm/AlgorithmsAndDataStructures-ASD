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

void ShowList (node *f)
{
    while (f!=NULL)
    {
        cout<<f->val<<endl;
        f=f->next;
    }
}

node *RepairSortList (node *f)
{
    node *p=f;
    node *q=f->next;
    //if there is a problem with first element
    if (f->val > f->next->val)
    {
        f=f->next;
        q=p;
    }

    //other
    else
    {
        while (q->next!=NULL && q->val>p->val && q->next->val > q->val)
        {
            p=q;
            q=q->next;
        }
        //in case of correct list
        if (q->next==NULL)
        {
            if (q->val > p->val) return f;
        }

        //if there is a bigger element - q is on right element, if there is a smaller - we have to move q one element further
        if (p->val > q->next->val)
        {
            q=q->next;
        }
        //we have to take out our bad element
        p->next=q->next;
    }
    //extra element on the beginning
    node *k=new node;
    k->next=f;
    f=k;
    //we put element in correct place
    p=f;
    while (p->next!=NULL && p->next->val < q->val)
    {
        p=p->next;
    }
    q->next=p->next;
    p->next=q;
    f=f->next;
    delete k;
    return f;
}

int main()
{
    node *f;
    int tab[N]= {1, 3, 4, 8, 9, 11, 1344, 15, 17, 20, 21, 22, 23, 28, 29};
    CreateList(f, tab);
    
    cout<<"Tak poczatkowo wyglada nasza lista:"<<endl;
    ShowList (f);

    cout<<"Tak wyglada popraiwiona lista:"<<endl;
    f=RepairSortList(f);
    ShowList (f);
}

