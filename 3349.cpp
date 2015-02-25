#include <iostream>
#include <cstring>
using namespace std;

const int mod=999983;
int n,i,j,k,loop1,loop2;
typedef class Snow
{
public:
    int len[6];
} Snow;

typedef class HashTable
{
public:
    int len[6];
    HashTable* Next;

    HashTable()
    {
        Next=0;
    }
} HashTable;

HashTable hashh[mod+1];
Snow leaf[100001];

bool checknow(int lenn1[], int lenn2[])
{
    for (loop1=0;loop1<6;loop1++)
    {
        bool tempcheck=true;
        for (loop2=0;loop2<6;loop2++)
        {
            if (lenn1[loop2]!=lenn2[(loop1+loop2)%6])
            {
                tempcheck=false;
                break;
            }
        }
        if (tempcheck) return true;
    }
    for (loop1=0;loop1<6;loop1++)
    {
        bool tempcheck=true;
        for (loop2=0;loop2<6;loop2++)
        {
            if (lenn1[loop2]!=lenn2[(5-loop1-loop2+6)%6])
            {
                tempcheck=false;
                break;
            }
        }
        if (tempcheck) return true;
    }
    return false;
}

bool isTwin(int i)
{
    int sum=0;
    for (k=0;k<6;k++)
    {
        sum+=leaf[i].len[k];
    }
    sum=sum% mod;
    if ((hashh[sum].len[0]==0)&&(hashh[sum].len[1]==0)&&(hashh[sum].len[2]==0))
    {
        for (k=0;k<6;k++)
            hashh[sum].len[k]=leaf[i].len[k];
        hashh[sum].Next=0;
        return false;
    }
    else
    {
        HashTable *temp=&hashh[sum];
        if (temp->Next==0)
        {
             if (checknow(temp->len,leaf[i].len))
             {
                return true;
             }
        }
        else
        {
            while (temp->Next!=0)
            {

                if (checknow(temp->len,leaf[i].len))
                {
                    return true;
                }
                temp=temp->Next;
                if (temp->Next==0)
                {
                    if (checknow(temp->len,leaf[i].len))
                    {
                        return true;
                    }
                }
            }
        }
        HashTable* temp1=new HashTable();
        for (k=0;k<6;k++)
        {
            temp1->len[k]=leaf[i].len[k];
        }
        temp->Next=temp1;
        temp1->Next=0;
        return false;
    }
}

int main()
{
    cin >> n;
    bool isfind=false;
    memset(hashh,0,sizeof(hashh));
    for (i=0;i<n;i++)
    {
        for (j=0;j<6;j++)
        {
            cin >> leaf[i].len[j];
        }
        if (isTwin(i))
        {
            cout << "Twin snowflakes found." << endl;
            isfind=true;
            break;
        }
    }
    if (isfind==false)
        cout << "No two snowflakes are alike." << endl;
    return 0;
}
