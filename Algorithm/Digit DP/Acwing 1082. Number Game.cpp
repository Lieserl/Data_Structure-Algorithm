#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 11;

int f[N][10];

void init()
{   
    for (int i = 0; i <= 9; i ++ ) f[1][i] ++ ;
    
    for (int i = 2; i < N; i ++ )
        for (int j = 0; j <= 9; j ++ )
            for (int k = j; k <= 9; k ++ )
                f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    if (!n) return 1;
    
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;
    
    int res = 0;
    int last = 0;
    
    for (int i = nums.size() - 1; i >= 0; i -- )
    {
        int x = nums[i];
        
        for (int j = 0; j < x; j ++ )
            if (last <= j)
                res += f[i + 1][j];
        
        if (x < last) break;
        last = x;
        
        if (!i) res ++ ;
    }
    
    return res;
}

int main()
{
    int l, r;
    init();
    
    while (cin >> l >> r)
        cout << dp(r) - dp(l - 1) << endl;

    return 0;
}