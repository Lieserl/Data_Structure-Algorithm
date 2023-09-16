#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e4 + 10;

int n, m, k;
int v[N], w[N];
int p[N];
int f[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
        p[i] = i;
    }

    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            v[b] += v[a];
            w[b] += w[a];
        }
    }

    for (int i = 1; i <= n; i++)
        if (i == p[i])
            for (int j = m; j >= v[i]; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;

    return 0;
}
