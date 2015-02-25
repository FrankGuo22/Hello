#include <stdio.h>

int main()
{
	int n;
	char r[200];
	int i,j,k;
	int reversenow[200],total[200],temp[200];
	while (scanf("%s %d",&r,&n)!=EOF)
	{
		int tailac=0;
		for (i=1;i<200;i++)
		{
			total[i]=0;
			reversenow[i]=0;
			temp[i]=0;
		}
		for (i=0;i<=5;i++)
		{
			if (r[i]=='.')
			{
				tailac=5-i;
				for (j=i+1;j<=5;j++)
					r[j-1]=r[j];
				break;
			}
		}
		tailac *=n;
		for (j=1;j<=5;j++)
		{
			reversenow[j]=(int)((int)r[5-j]-48);
			total[j]=(int)((int)r[5-j]-48);
		}
	
		for (i=2;i<=n;i++)
		{
			for (j=1;j<=5;j++)
			{
				for (k=1;k<=(i-1)*5;k++)
				{
					temp[j+k-1] =total[k]*reversenow[j]+temp[j+k-1];
				}
			}
		
			for (j=1;j<=(5*i);j++)
			{
				if (temp[j]>=10)
				{
					temp[j+1]=temp[j+1]+(int)(temp[j]/10);
					temp[j]=temp[j] %10;
				}
				total[j]=temp[j];
			}
			for (j=1;j<=5*i;j++)
			{
				temp[j]=0;
			}
		}
		
		for (j=180;j>=1;j--)
		{
			if (total[j]!=0)
			{
				break;
			}
		}
		for (k=1;k<=j;k++)
		{
			if (total[k]==0) 
			{
				continue;
			}
			else
			{
				break;
			}
		}

		if (n==0) 
		{
			printf("1");
			continue;
		}
		if ((j<=k)&&(total[k]==0))
		{
			printf("0");
		}
		else
		{
			if (j-k+1<tailac)
			{
				j=tailac;
			}
			if (j!=k)
			{
				for (int l=j;l>=k;l--)
				{
					if (l==tailac) printf(".");
					printf("%d",total[l]);
				}
			}
		}
		printf("\n");
	}
}
