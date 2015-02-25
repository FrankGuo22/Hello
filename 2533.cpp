#include <iostream>
using namespace std;

int main()
{
    int n,i,j;
    int sequence[10002],f[10002];
    cin >> n;
    for (i=1;i<=n;i++)
    {
        cin >>sequence[i];
        f[i]=1;
    }
    int totalmax=0;
    for (i=1;i<=n;i++)
    {
        int max=0;
        for (j=1;j<i;j++)
        {
            if ((sequence[j]<sequence[i])&&(max<f[j]))
                max=f[j];
        }
        if (max!=0)
            f[i]=max+1;
        else
            f[i]=1;
        if (totalmax<f[i]) totalmax=f[i];
    }
    cout << totalmax ;
    return 0;
}
