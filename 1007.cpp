#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    int i,j,k;
    cin >> n >> m;
    string listnow[101];
    int order[101];
    for (i=1;i<=m;i++)
    {
        order[i]=0;
        cin >> listnow[i];
        for (j=0;j<n-1;j++)
        {
            for (k=j+1;k<n;k++)
            {
                if (listnow[i][j]>listnow[i][k])
                {
                    order[i]++;
                }
            }
        }
    }
    for (i=1; i<m;i++)
    {
        for (j=1;j<m;j++)
        {
            if (order[j]>order[j+1])
            {
                string temp;
                temp=listnow[j];
                listnow[j]=listnow[j+1];
                listnow[j+1]=temp;
                int p;
                p=order[j];
                order[j]=order[j+1];
                order[j+1]=p;
            }
        }
    }
    for (i=1;i<=m;i++)
        cout << listnow[i] << "\n";
    return 0;
}
