#include <iostream>
using namespace std;
int edge[120][120];

#define MaxInt 0x3f3f3f3f
int prim(int n)
{
    bool isTree[120];
    int sum=0;
    int i,j,k;
    int temp,minlength[120];
    int ji=0;

    for (i=1;i<=n;i++)
        isTree[i]=false;

    for (i=1;i<=n;i++)
        minlength[i]=edge[1][i];

    isTree[1]=true;

    for (i=2;i<=n;i++)
    {
        int minnow=MaxInt;
        for (j=1;j<=n;j++)
            if ((!isTree[j])&&(minlength[j]<minnow))
            {
                k=j;
                minnow=minlength[j];
            }
        isTree[k]=true;
        sum+=minnow;
        for (j=1;j<=n;j++)
        {
            if ((!isTree[j])&&(edge[k][j]<minlength[j]))
                minlength[j]=edge[k][j];
        }
    }
    return sum;
}

int main()
{
    int n,i,j;
    while (cin >> n)
    {
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            {
                edge[i][j]=MaxInt;
                cin >> edge[i][j];
            }
        cout << prim(n)<< endl;
    }
    return 0;
}
