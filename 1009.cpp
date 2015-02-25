#include <iostream>
#inlcude <cmath>
using namespace std;

int main()
{
    int width;
    int i,j,k;
    int valuearray[2000],numarray[2000];
    int outputvalue[2000],outputnum[2000];
    int value, num;
    while (cin >> width)
    {
        int totalnum=0;
        int count=0;
        numarray[0]=0;
        while (true)
        {
            cin >> value >> num;
            if ((value==0)&&(num==0)) break;
            count++;
            totalnum+=num;
            valuearray[count]=value;
            numarray[count]=totalnum;
        }
        for (i=0;i<=count;i++)
        {
            int heng,zong;
            heng=numarray[i]/width+1;
            zong=numarray[i]%width;
            for (j=heng-1;j<=heng+1;j++)
                for (k=zong-1;k<=zong+1;k++)
                {
                    if (isinside(j,k))
                    {

                    }
                }
        }
    }
}
