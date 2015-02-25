#include <iostream>
using namespace std;

const int phy = 23;
const int emo = 28;
const int intel = 33;

int main()
{
    int ph,em,in,nowday;
    int sta=0;
    while (cin>> ph >> em >> in >> nowday)
    {
        sta++;
        int totalday = 0;
        if (ph==-1) break;

        ph = (phy*phy-ph+nowday) % phy;
        em = (emo*emo-em+nowday) % emo;
        in = (intel*intel-in+nowday) % intel;
        totalday=nowday;
        while (((ph %phy)!=0)||(((em % emo)!=0))||(((in % intel)!=0))||(totalday<=nowday))
        {
            ph = (ph+1) % phy;
            em = (em+1) % emo;
            in = (in+1) % intel;
            totalday++;
        }
        cout << "Case "<<sta<<": the next triple peak occurs in " << totalday-nowday <<" days.\n";
    }
    return 0;
}
