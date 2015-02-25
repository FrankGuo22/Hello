//state compressed+ DP
//dp[state][j][k]= dp[state][i][j]+val[j]*val[k]+(val[i]*val[j]*val[j] if map[i][k]);
#include <iostream>
#include <cstring>

using namespace std;
int mapp[15][15];
int value[100];
int n,m,i,j,k,x;
int temp;
int dp[1<<14][13][13];
long long num[1<<14][13][13];



void statecompressedDP()
{
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            if ((i!=j)&&(mapp[i][j]))
            {
                num[(1<<i)|(1<<j)][i][j]=1;
                dp[(1<<i)|(1<<j)][i][j]=value[i]*value[j]+value[i]+value[j];
            }
    for (i=0;i<(1<<n);i++)
        for (j=0;j<n;j++)
        {
            if ((i&(1<<j))!=0)
            {
                for (k=0;k<n;k++)
                {
                    if (mapp[j][k]&&(j!=k)&&((i&(1<<k))!=0)&&(dp[i][j][k]!=-1))
                    {
                        for (x=0;x<n;x++)
                        {
                            if (mapp[k][x]&&(x!=j)&&(x!=k)&&((i&(1<<x))==0))
                            {
                                temp=dp[i][j][k]+value[k]*value[x]+value[x];
                                if (mapp[j][x])
                                    temp+=value[j]*value[k]*value[x];
                                if (temp>dp[i|(1<<x)][k][x])
                                {
                                    dp[i|(1<<x)][k][x]=temp;
                                    num[i|(1<<x)][k][x]=num[i][j][k];
                                }
                                else if (temp==dp[i|(1<<x)][k][x])
                                {
                                    num[i|(1<<x)][k][x]+=num[i][j][k];
                                }
                            }
                        }
                    }
                }
            }
        }
    int maxvalue=0;
    long long maxnum=0;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            if ((i!=j)&&(mapp[i][j]))
            {
                if (dp[(1<<n)-1][i][j]>maxvalue)
                {
                    maxvalue=dp[(1<<n)-1][i][j];
                    maxnum=num[(1<<n)-1][i][j];
                }
                else if (dp[(1<<n)-1][i][j]==maxvalue)
                {
                    maxnum+=num[(1<<n)-1][i][j];
                }
            }
        }
    cout << maxvalue <<" " << maxnum/2 <<endl;
}


int main()
{
    int totalcase;
    cin >> totalcase;
    while (totalcase--)
    {
        memset(mapp,0,sizeof(mapp));
        memset(dp,-1,sizeof(dp));
        memset(num,0,sizeof(num));
        cin >> n >> m;
        for (i=0;i<n;i++)
            cin >>value[i];
        for (i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            mapp[x-1][y-1]=1;
            mapp[y-1][x-1]=1;
        }
        if(n==1){
            cout << value[0] <<" 1"<<endl;
            continue;
        }
        statecompressedDP();
    }
    return 0;
}
