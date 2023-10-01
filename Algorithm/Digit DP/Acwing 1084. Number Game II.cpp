#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int N = 15, M = 110;

int P;
int f[N][10][M]; 

int mod(int n)
{
    return (n % P + P) % P;
}

void init()
{
    memset(f, 0, sizeof f);
    for (int i = 0; i <= 9; i ++ )
        f[1][i][i % P] = 1 ;
    
    for (int i = 2; i < N; i ++ )
        for (int j = 0; j <= 9; j ++ )
            for (int k = 0; k < P; k ++ )
                for (int u = 0; u <= 9; u ++ )
                    f[i][j][k] += f[i - 1][u][mod(k - j)];
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
        
        // When dealing with the right branch, since the sum of the digits filled before i + 1 is 'last,' in order to ensure that the overall result is divisible by P (mod P == 0), 'res' should be incremented by the value when (last + sum) % mod == 0, which means sum should be set to mod(-last).
        for (int j = 0; j < x; j ++ )
            res += f[i + 1][j][mod(-last)];
        
        last += x;
        
        if (!i && last % P == 0) res ++ ;
    }
    
    return res;
}

int main()
{
    int l, r;
    while (cin >> l >> r >> P)
    {
        init();
        cout << dp(r) - dp(l - 1) << endl;
    }
    
    return 0;
}
