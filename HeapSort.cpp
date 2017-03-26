#include <iostream>
using namespace std;

void RestoreHeap (int tab[], int x, int n) //x=index, n=size
{
    int m; //max
    if (2*x+1<n && tab[2*x+1]>tab[x]) m=2*x+1;
        else m=x;

    if (2*x+2<n && tab[2*x+2]>tab[m]) m=2*x+2;

    if (m!=x)
    {
        swap (tab[x], tab[m]);
        RestoreHeap(tab, m, n);
    }
    return;
}

void CreateHeap (int tab[], int n)
{ for (int i=(n/2); i>=0; i--) RestoreHeap(tab, i, n); }

void HeapSort(int tab[], int n)
{
    for(int i=n-1; i>0; i--)
    {
        CreateHeap(tab, i);
        swap(tab[i], tab[0]);
        RestoreHeap(tab, 0,i);
    }
}

int main()
{
    int Heap[]={2, 8, 9, 11, 16, 88, 5, 17, 12, 3, 18, 1};
    HeapSort(Heap, 12);
    cout<<"sorted: "<<endl;
    for (int i=0; i<12; i++)
    {
        cout<<Heap[i]<<endl;
    }
}
