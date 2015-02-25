#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int main()
{
    stack <int> stack_now;
    int i,j,x,y,k,x1,x2,y1,y2,px,py=200000;
    double jiao[1000];
    bool check[1000];
    int tempx[1000],tempy[1000];
    int p0;
    cin>> n;
    for (i=1;i<=n;i++)
    {
        check[i]=true;
        cin >> tempx[i] >> tempy[i];
        if (tempy[i]<py)
        {
            py=tempy[i];
            px=tempx[i];
            p0=i;
        }
        else
        {
            if ((tempy[i]==py)&&(tempx[i]<px))
            {
                py=tempy[i];
                px=tempx[i];
                p0=i;
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        jiao[i]=(tempx[i]-tempx[p0])/sqrt((tempx[i]-tempx[p0])*(tempx[i]-tempx[p0])+(tempy[i]-tempy[p0])*(tempy[i]-tempy[p0]));
    }
    for
}
