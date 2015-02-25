#include <iostream>
using namespace std;

int main()
{
    double sum=0;
    for (int i=1;i<=12;i++)
    {
        double thismonth;
        cin >> thismonth;
        sum += thismonth;
    }
    cout << "$"<<sum/12 <<"\n";
    return 0;
}
