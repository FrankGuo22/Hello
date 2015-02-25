#include <iostream>
using namespace std;

const double pi=3.1415926;

int main()
{
    int n;
    double x,y;
    double r, area;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> x >> y;
        area = (pi*(x*x+y*y))/2;
        cout << "Property "<< i <<": This property will begin eroding in year "<<int(area/50)+1<<".\n";
    }
    cout << "END OF OUTPUT.\n";
    return 0;
}
