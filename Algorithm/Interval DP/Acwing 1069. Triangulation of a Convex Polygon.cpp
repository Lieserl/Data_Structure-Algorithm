#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 55;

int n;
int w[N];
vector<int> f[N][N];

vector<int> add(vector<int> &a, vector<int> &b)
{
    vector<int> c;

    int t = 0;
    for (int i = 0; i < a.size() ||  i < b.size(); i ++ )
    {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) c.push_back(t % 10), t /= 10;
    return c;
}

vector<int> mul(vector<int> &a, LL b)
{
    vector<int> c;

    LL t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) c.push_back(t % 10), t /= 10;
    return c;
}

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size()) return a.size() < b.size();

    for (int i = a.size() - 1; i >= 0; i -- )
        if (a[i] != b[i])
            return a[i] < b[i];
    return true;
}

void print(vector<int> &a)
{
    for (int i = a.size() - 1; i >= 0; i -- )
        cout << a[i];
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    for (int len = 3; len <= n; len ++ )
        for (int l = 1; l + len - 1 <= n; l ++ )
        {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k ++ )
            {   
                vector<int> temp;
                temp.push_back(w[l]);
                temp = mul(temp, w[k]);
                temp = mul(temp, w[r]);
                temp = add(temp, f[l][k]);
                temp = add(temp, f[k][r]);
                if (f[l][r].empty() || cmp(temp, f[l][r]))
                    f[l][r] = temp;
            }
        }
    
    print(f[1][n]);

    return 0;
}