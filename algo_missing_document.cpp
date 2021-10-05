#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int A[maxN][5];

bool cmp(int a, int b)
{
    int count_a_less = 0;
    
    for(int i=0; i<5; i++)
    {
        if(A[a-1][i] < A[b-1][i])
        {
            count_a_less++;
        }
    }
    
    if(count_a_less >= 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int N;
    cin >> N;
    
    for(int k=0; k<5; k++)
    {
        for(int i=0; i<N; i++)
        {
            int c;
            cin >> c;
            
            A[c-1][k] = i;
        }
    }
    
    int C[N];
    for(int i=0; i<N; i++)
    {
        C[i] = i+1;
    }
    
    sort(C, C+N, cmp);
    
    for(int i=0; i<N; i++)
    {
        cout << C[i] << " ";
    }
    cout << "\n";
}