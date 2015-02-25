#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int i,j,k,m,n,dis[201][201],pre[201],s,e,c;
bool check[201];

bool BFS(int s,int t)
{
    memset(pre,-1,sizeof(pre));
    memset(check,true,sizeof(check));
    queue <int> quee;

    check[s]=false;
    pre[s]=s;

    quee.push(s);
    int p;
    while (!quee.empty())
    {
        p=quee.front();
        quee.pop();
        for (i=1;i<=m;i++)
        {
            if ((dis[p][i]>0)&&(check[i]))
            {
                check[i]=false;
                pre[i]=p;
                if (i==t) return true;
                quee.push(i);
            }
        }
    }
    return false;
}

int EK(int s, int t)
{
    int sum=0;
    while (BFS(s,t))
    {
        int min=100000000;
        for (i=t;i!=s;i=pre[i])
            min = min>dis[pre[i]][i]?dis[pre[i]][i]:min;
        for (i=t;i!=s;i=pre[i])
        {
            dis[pre[i]][i]-=min;
            dis[i][pre[i]]+=min;
        }
        sum+=min;
    }
    return sum;
}

int main()
{
    while (cin >> n >> m)
    {
        memset(dis,0,sizeof(dis));
        for (i=1;i<=n;i++)
        {
            cin >> s >> e >> c;
            dis[s][e]+=c;
        }
        cout << EK(1,m)<< endl;
    }
    return 0;
}
