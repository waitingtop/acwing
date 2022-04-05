#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> path;

void dfs(vector<int>& a, vector<bool>& used)
{
    if(path.size() == n)
    {
        for(int i = 0; i < n; ++i) printf("%d ", path[i]);
        printf("\n");
        return;
    }
    for(int i = 0; i < a.size(); ++i)
    {
        if(used[i] == false)
        {
            used[i] = true;
            path.push_back(a[i]);
            dfs(a, used);
            path.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) a[i] = i + 1;
    vector<bool> used(n, false);
    dfs(a, used);
    return 0;
}