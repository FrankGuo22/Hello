//statecompressed + DP
// dp[s][i] = Lei(dp[s'][i-1])(match 1.infertile 2.available)
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define mod 100000000
int m,n,i,j,k;
int dp[1<<13][13];
int check[13];

void DP()
{
    memset(dp,0,sizeof(dp));
    for (i=0;i<(1<<m);i++){
        if (((check[0]|i)==check[0])&&((i&(i<<1))==0))
        {
            dp[i][0]=1;
        }
    }

    for (i=1;i<n;i++)
        for (j=0;j<(1<<m);j++)
        {
            if (((check[i]|j)==check[i])&&((j&(j<<1))==0))
            {
                for (k=0;k<(1<<m);k++)
                {
                    if (((check[i-1]|k)==check[i-1])&&((k&(k<<1))==0)&&((j&k)==0))
                    {

                        dp[j][i]+=dp[k][i-1] % mod;
                    }
                }
            }
        }
    int sum=0;
    for (i=0;i<(1<<m);i++)
        if (((check[n-1]|i)==check[n-1])&&((i&(i<<1))==0))
        {
            sum+=dp[i][n-1] % mod;
        }
    cout << (sum % mod)<< endl;
}

int main()
{
    cin >> n >>m;
    memset(check,0,sizeof(check));
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        {
            cin >> k;
            if (k==1)
                check[i]=1<<(m-j-1)|check[i];
        }
    DP();
    return 0;
}
