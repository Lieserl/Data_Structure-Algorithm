#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 220;

int n;
int w[N];
int f[N][N];

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i ++ )
    {
        int t;
        cin >> t;
        w[i] = w[i + n] = t;
    }

    for (int len = 1; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= 2 * n; l ++ )
        {
            int r = l + len - 1;
            if (len == 1) f[l][r] = 0;
            for (int k = l; k < r; k ++)
                    f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + w[l] * w[k + 1] * w[r + 1]);
        }

    int res = 0;
    for (int i = 1; i <= n; i ++ ) 
        res = max(res, f[i][i + n - 1]);

    cout << res << endl;

    return 0;
}