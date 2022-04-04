#include <iostream>
#include <vector>
using namespace std;

vector<int> ADD(vector<int>& A, vector<int>& B)
{
    vector<int> result;
    int t = 0;
    for(int i = 0; i < A.size() || i < B.size(); ++i)
    {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        result.push_back(t % 10);
        t /= 10;
    }
    if(t) result.push_back(1);
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    // 最低位放在数组的0下标...
    for(int i = a.size() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    for(int i = b.size() - 1; i >= 0; --i) B.push_back(b[i] - '0');
    
    auto C = ADD(A, B);
    
    for(int i = C.size() - 1; i >= 0; --i)
    {
        printf("%d", C[i]);
    }
    return 0;
}