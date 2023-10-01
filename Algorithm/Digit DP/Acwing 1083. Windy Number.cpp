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
            for (int k = 0; k <= 9; k ++ )
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    if (!n) return 0;
    
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;
    
    int res = 0;
    int last = -2;
    
    for (int i = nums.size() - 1; i >= 0; i -- )
    {
        int x = nums[i];
        
        // Because we need to handle the case of leading zeros separately, the first digit cannot be filled with 0.
        for (int j = (i == nums.size() - 1); j < x; j ++ )
            if (abs(last - j) >= 2)
                res += f[i + 1][j];
                
        if (abs(last - x) < 2) break;
        last = x;
        
        if (!i) res ++ ;
    }
    
    for (int i = 1; i <= nums.size() - 1; i ++ )
        for (int j = 1; j <= 9; j ++ )
            res += f[i][j];
            
    return res;
}

int main()
{
    int l, r;
    cin >> l >> r;
    
    init();
    
    cout << dp(r) - dp(l - 1) << endl;
    
    return 0;
}