#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int i,j,k,n;
Unit wood[100000];
typedef class Unit
{
    string s;
    int sta;
}Unit;

int main()
{
    i=1;
    while (scanf("%s",&wood[i].s))
    {
        i++;
    }
    i--;
    n=i;
    qsort(wood,n,sizeof(Unit),compare);
}
