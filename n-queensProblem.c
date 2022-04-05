#include<iostream>
using namespace std;

const int N = 20;
int n;
char g[N][N];   // 棋盘
bool row[N], col[N], dg[N], udg[N];     // 行、列、正反对角线

void dfs(int x, int y, int s)
{
    if(y == n)
    {
        y = 0;
        ++x;
    }
    if(x == n)
    {
        if(s == n)
        {
            for(int i = 0; i < n; ++i) puts(g[i]);
            puts("");
        }
        return;
    }
    
    // 不放皇后
    dfs(x, y + 1, s);
    
    // 放皇后
    if(!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true;
        dfs(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
        g[x][y] = '.';
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            g[i][j] = '.';
    dfs(0, 0, 0);
    return 0;
}