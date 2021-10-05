#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3;
long long D[maxN], C[maxN];

int N, T;
long long K;

bool canDefend(long long x)
{
    double T2 = 0;
    
    for(int i=0; i<N; i++)
    {
        // Type cast to double to avoid overflow
        double r = ((double)T)*D[i] + 1;
        double t = max(0.0, ceil((r-C[i])/(min(D[i], x))));
        
        T2 += t;
    }
    
    if(T2 > T)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{    
    cin >> N >> T >> K;
    
    for(int i=0; i<N; i++)
    {
        cin >> D[i];
    }
    for(int i=0; i<N; i++)
    {
        cin >> C[i];
    }
    
    long long l = K, u = 1e18;
    
    if(canDefend(l))
    {
        cout << "0\n";
    }
    else if(not canDefend(u))
    {
        cout << "-1\n";
    }
    else
    {
        while(u-l > 1)
        {
            long long d = (l+u)/2;
            
            if(canDefend(d))
            {
                u = d;
            }
            else
            {
                l = d;
            }
        }
        
        cout << u-K << "\n";
    }
}