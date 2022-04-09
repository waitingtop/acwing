#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int q[N], hh, tt  = -1;

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        string str;
        cin >> str;
        int x;
        if(str == "push")
        {
            cin >> x;
            q[++tt] = x;
        }
        else if(str == "pop")
        {
            ++hh;
        }
        else if(str == "empty")
        {
            if(hh <= tt) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else
        {
            cout << q[hh] << endl;
        }
    }
    return 0;
}