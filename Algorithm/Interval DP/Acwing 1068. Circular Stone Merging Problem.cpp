#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 410, INF = 0x3f3f3f3f;

int n;
int s[N], w[N];
int f[N][N], g[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[i + n] = w[i];
    }

    // Preprocessed Prefix Sum Array.
    for (int i = 1; i <= n * 2; i++)
        s[i] = s[i - 1] + w[i];

    memset(g, 0x3f, sizeof g);

    for (int len = 1; len <= n; len++)
        for (int l = 1; l + len - 1 <= n * 2; l++)
        {
            int r = l + len - 1;
            if (len == 1)
                f[l][r] = g[l][r] = 0;
            else
                for (int k = l; k < r; k++)
                {
                    f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                    g[l][r] = min(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
                }
        }

    int minv = INF, maxv = -INF;
    for (int i = 1; i <= n; i++)
    {
        minv = min(minv, g[i][i + n - 1]);
        maxv = max(maxv, f[i][i + n - 1]);
    }

    cout << minv << endl;
    cout << maxv << endl;

    return 0;
}
