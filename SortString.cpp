#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void SortString (string A[], int n)
{

}

void SortByLen(string A[], int n)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (strlen(A[i])>strlen(A[j]))
            {
                swap (A[i], A[j]);
            }
        }
    }
}

void SortByPos (string A[], int pos, int from, int to)
{

}


int main()
{

    string A[10]={"propan", "butan", "ala", "jordanapark", "alanina", "betaalanina", "propanbutan", "bcaa", "bcaal", "koks"};
    cout<<"Nasza tablica na poczatku: "<<endl;
    for (int i=0; i<10; i++) cout<<A[i]<<endl;
    SortByLen(A, 10);
    cout<<"Nasza tablica po posortowaniu na dlugosc: "<<endl;
    for (int i=0; i<10; i++) cout<<A[i]<<endl;
}
