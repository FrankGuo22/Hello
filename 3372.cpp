#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n&(n-1)) cout <<"NO" <<endl;
        else cout << "YES" <<endl;
    }
    return 0;
}
