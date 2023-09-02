#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N], siz[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    // Initialize
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    while (m--)
    {
        string op;
        int a, b;
        cin >> op;
        if (op[0] == 'C')
        {
            cin >> a >> b;
            if (find(a) == find(b))
                continue;
            siz[find(b)] += siz[find(a)];
            p[find(a)] = find(b);
                }

        else if (op[1] == '1')
        {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

        else
        {
            cin >> a;
            cout << siz[find(a)] << endl;
        }
    }

    return 0;
}
