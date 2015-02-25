#include <iostream>
using namespace std;

int main()
{
    double collec[400];
    int now=1;
    int di=2;
    double sum=0.00;
    while (sum < 5.20)
    {
        sum = sum+ (double)(1.0/(di));
        collec[now]=sum;
        di++;
        now++;
    }
    now--;
    int i,j,k;
    double temp;
    while (cin >> temp)
    {
        if (temp<0.00000001) break;
        for (i=1;i<=now;i++)
        {
            if (collec[i]>temp)
            {
                cout<< i << " card(s)\n";
                break;
            }
        }
    }
    return 0;
}
