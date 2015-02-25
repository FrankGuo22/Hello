#include <iostream>
#include <cstring>
using namespace std;
int m,n,i,j,k,dp[101][1<<10][1<<10];
int check[101];
char ch;

void DP()
{

}

int main()
{
    memset(dp,0,sizeof(dp));
    memset(check,0,sizeof(check));
    cin >>n >>m;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        {
            cin >>ch;
            if (ch=='P')
            {
                check[i]|=(1<<(m-j-1));
            }
        }
    DP();
    return 0;
}
