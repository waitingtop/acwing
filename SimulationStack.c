#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int stk[N], tt = -1;    // 栈 栈顶指针

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        string str;
        cin >> str;
        int x;
        if(str == "push")   // 入栈
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if(str == "pop")   // 出栈
        {
            --tt;
        }
        else if(str == "empty")     // 判空
        {
            if(tt > -1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else                    // 取栈顶元素
        {
            cout << stk[tt] << endl;
        }
    }
    return 0;
}