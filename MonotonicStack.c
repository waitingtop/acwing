#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int stk[N], tt = -1;


int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int x;
        scanf("%d", &x);
        while(tt > -1 && stk[tt] >= x) --tt;
        if(tt > -1) printf("%d ", stk[tt]);
        else printf("-1 ");
        stk[++tt] = x;
    }
    return 0;
}