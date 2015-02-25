#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n;
	char choi[]="22233344455566677778889999";
	char total[10][1001];
	int sum[1001];
	char temp[30];
	scanf("%d",&n);
	int i,j,k;
	int zong=0;
	for (i = 1;i<=n ;i++)
	{
		char shortter[30];
		scanf("%s",&temp);
		sum[i]=0;
		int point_temp=0;
		for (j=0;j<strlen(temp);j++)
		{
			if (temp[j]=='-') continue;
			if (temp[j]<=57) 
			{
				shortter[point_temp]=temp[j];
				point_temp++;
			}
			else
			{
				shortter[point_temp]=choi[temp[j]-65];
				point_temp++;
			}
			shortter[point_temp]='\0';
		}
		bool check=false;
		for (j=1;j<=zong;j++)
		{
			if (strcmp(shortter,total[j])==0)
			{
				sum[j]++;
				check=true;
			}
		}
		if (check==false)
		{
			zong++;
			for (j=0;j<8;j++)
				total[zong][j]=shortter[j];
		}
	}

	for (i=1;i<=zong-1;i++)
		for (j=1;j<=i;j++)
		{
			if (strcmp(total[j],total[j+1])>0)
			{
				char ttt[20];
				strcpy(ttt,total[j]);
				strcpy(total[j],total[j+1]);
				strcpy(total[j+1],ttt);
				int tttt;
				tttt=sum[j];
				sum[j]=sum[j+1];
				sum[j+1]=tttt;
			}
		}
	bool checkis=false;

	for (i=1;i<=zong;i++)
	{
		if (sum[i]>0)
		{
			checkis=true;
			printf("%c%c%c-%c%c%c%c %d\n",total[i][0],total[i][1],total[i][2],total[i][3],total[i][4],total[i][5],total[i][6],sum[i]+1);
		}
	}
	if (checkis==false) printf("No duplicates.\n");
}