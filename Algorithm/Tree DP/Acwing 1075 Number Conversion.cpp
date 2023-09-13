#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5e4 + 10, M = 1 << N;

int n;
int h[N], e[M], ne[M], idx;
int cnt[N];
int res;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u)
{
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        int d = dfs(j);
        if (d + 1 >= d1) d2 = d1, d1 = d + 1;
        else if (d + 1 > d2) d2 = d + 1;
    }

    res = max(res, d1 + d2);
    return d1;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ )
        for (int j = 2; j <= n / i; j ++ )
            cnt[i * j] += i;
    
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i ++ )
        if (cnt[i] < i)
            add(cnt[i], i);

    dfs(1);

    cout << res << endl;
    
    return 0;
}