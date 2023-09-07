# ADD
## Ver. Vector
```
Vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C; // Answer

    int t = 0; // Carry
    for (int i = 0; i < A.size() || i < B.size(); i ++ )
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    if (t) C.push_back(1);
    return C;
}

auto C = add(A, B);
```

## Ver. Array
```
void add(LL a[], LL b[])
{
    static LL c[M];
    memset(c, 0, sizeof c);
    for (int i = 0, t = 0; i < M; i ++ )
    {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}
```

# Multiply
## Ver. Vector
```
vector<int> mul(vector<int> &A, LL B)
{
    vector<int> C;
    LL t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) c.push_back(t % 10), t /= 10;
    return C;
}
```
## Ver. Array
```
void mul(LL a[], LL b)
{
    static LL c[M];
    memset(c, 0, sizeof c);
    LL t = 0;
    for (int i = 0; i < M; i ++ )
    {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);
}
```

# Compare
## Ver. Vector
```
bool cmp(vector<int> &A, vector<int> &B)
{
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i -- )
        if (a[i] != b[i])
            return a[i] < b[i]
    return true;
}
```

## Ver. Array
```
int cmp(LL a[], LL b[])
{
    for (int i = M - 1; i >= 0; i -- )
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    return 0;
}
```


# Print
```
void print(LL a[])
{
    int k = M - 1;
    while (k && !a[k]) k -- ;
    while(k >= 0) cout << a[k -- ];
    cout << endl;
}
```


