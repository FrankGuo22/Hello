#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int i,j,k,n;

bool prime(int to)
{
    for (j=2;j<=sqrt(to);j++)
    {
        if ((to%j)==0) return false;
    }
    return true;
}

int main()
{
    while (cin >>n)
    {
        for (i=3;i<=n;i++)
        {
            if ((prime(i))&&(prime(n-i)))
            {
                cout << n <<" = " << i << " + " <<n-i <<endl;
                break;
            }
        }

    }
    return 0;
}
