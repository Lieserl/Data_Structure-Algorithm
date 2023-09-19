#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5 + 10, mod = 2;

int n;
int p[N], d[N];

int find(int x)
{
    if (x != p[x])
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }

    return p[x];
}

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        bool flag = 1;
        cin >> n;

        for (int i = 1; i <= n; i ++ )
            p[i] = i;

        for (int i = 1; i <= n; i ++ )
        {
            int a, b, op;
            cin >> a >> b >> op;
            int pa = find(a), pb = find(b);
            if (op == 1)
            {
                if (pa == pb && (d[a] - d[b]) % mod)
                {
                    cout << "NO" << endl;
                    flag = 0;
                    break;
                }
                else if (pa != pb)
                {
                    p[pa] = pb;
                    d[pa] = d[b] - d[a];
                }
            }
            else
            {
                if (pa == pb && !((d[a] - d[b]) % mod))
                {
                    cout << "NO" << endl;
                    flag = 0;
                    break;
                }
                else if (pa != pb)
                {
                    p[pa] = pb;
                    d[pa] = d[b] + 1 - d[a];
                }
            }
        }

        if (flag == 1)
            cout << "YES" << endl;
    }

    return 0;
}