#include<bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
long long tot, A[N];
int main()
{
    scanf("%d", &m);
    for (; m; m --)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        A[v] += w; A[u] -= w;
    }
    for (int i = 1; i <= m; i++)
        if (A[i] > 0)
            tot += A[i];
    return !printf("%lld\n", tot);
}
