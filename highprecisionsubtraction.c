#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int>& A, vector<int>& B)    // 判断是否有 A >= B
{
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; --i)
    {
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
    vector<int> result;
    int t = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        result.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    
    while(result.size() > 1 && result.back() == 0) result.pop_back();   // 去掉前导0
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for(int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');
    
    vector<int> result;
    if(cmp(A, B))
    {
        result = sub(A, B);
        for(int i = result.size() - 1; i >= 0; --i) printf("%d", result[i]);
    }
    else
    {
        result = sub(B, A);
        printf("-");
        for(int i = result.size() - 1; i >= 0; --i) printf("%d", result[i]);
    }
    
    return 0;
}