#include <iostream>
#include <cstring>
using namespace std;

const string Haab[]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
const string Tzolkin[]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int main()
{
    int n,i,j,k,day,year;
    char c;
    string month;
    cin >> n;
    cout << n <<"\n";
    for (i=1;i<=n;i++)
    {
        cin >> day >> c >> month >> year;
        int totalday=0;
        for (j=0;j<=18;j++)
        {
            if (month==Haab[j])
            {
                    totalday=365*year+j*20+day;
            }
        }
        int newyear=totalday/260;
        totalday=totalday%260;
        int newmonth= (totalday % 13)+1;
        int newday= totalday%20;
        cout << newmonth << " "<<Tzolkin[newday]<<" "<<newyear<<"\n";

    }
    return 0;
}
